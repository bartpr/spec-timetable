/* distributor.cpp -- timetable distribution, class source
 * Copyright (C) 2013 daneos
 * See LICENSE for legal information
 */

#include "distributor.h"
//-----------------------------------------------------------------------------

Distributor::Distributor(int maxclients, const char *port)
{
#if defined(_WIN32)
	init_winsock(2,0);
#endif
	s = new tselector(maxclients);
	q = new Queue(maxclients);
}
//-----------------------------------------------------------------------------

Distributor::~Distributor()
{
	delete s;
	delete q;
#if defined(_WIN32)
	close_winsock();
#endif
}
//-----------------------------------------------------------------------------

int Distributor::addClient(const char *ip, const char *port)
{
	int id = q->addClient(ip, port);
	Client *c = q->getClient(id);
	if(c == NULL) ; // return some sort of error
	s->taddSocket(c->getSocket(), TS_MODE_R);
	s->taddSocket(c->getSocket(), TS_MODE_W); // not sure if it's needed
	return id;
}
//-----------------------------------------------------------------------------

void Distributor::removeClient(int id)
{
	q->removeClient(id);
}
//-----------------------------------------------------------------------------

int Distributor::sendData(int id, header *hdr, void *data)
{
	int hdrlen = sizeof(hdr);
	void *buffer = (void*)malloc(hdr->len);
	memcpy(buffer, hdr, hdrlen);
	memcpy(buffer+hdrlen, data, hdr->len-hdrlen);
	int status = q->getClient(id)->getSocket()->tsend((char*)buffer, hdr->len);
	free(buffer);
	return status;
}
//-----------------------------------------------------------------------------

int Distributor::recvData(int *id, void *buffer)
{
	memset(buffer, 0, sizeof(buffer));
	tsocket *S = s->twait();
	if(S == NULL) return NULL;
	void *rec_buf = malloc(sizeof(buffer));

	int n = 0;
	if((n = S->treceive((char*)rec_buf)) == -1) perror("tRECEIVE");
	if(n == 0) 
	{
		printf("[%s] Connection reset by peer.\n", S->tgetInstanceName());
		return 0;
	}
	// TODO: checking for full data receive
	header *hdr;
	int hdrlen = sizeof(header);
	memcpy(hdr, rec_buf, hdrlen);
	int len = hdr->len - hdrlen;
	memcpy(buffer, rec_buf+hdrlen, len);

	*id = q->getClientBySocket(S)->getID();
}
//-----------------------------------------------------------------------------

int Distributor::sendTransferPerm(int id)
{
	header *hdr = (header*)malloc(sizeof(header));
	hdr->len = sizeof(hdr);
	hdr->code = PERMISSN;
	int status = q->getClient(id)->getSocket()->tsend((char*)hdr, hdr->len);
	free(hdr);
	return status;
}
//-----------------------------------------------------------------------------

Client *Distributor::getClient(int id)
{
	return this->q->getClient(id);
}
//-----------------------------------------------------------------------------