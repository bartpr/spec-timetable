/* distributor.cpp -- timetable distribution, class source
 * Copyright (C) 2013 daneos
 * See LICENSE for legal information
 */

#include "distributor.h"
//-----------------------------------------------------------------------------

Distributor::Distributor(int maxclients)
/* Create socket selector and client queue
 * Initialize network if applicable */
{
#if defined(_WIN32)
	init_winsock(2,0);
#endif
	s = new tselector(maxclients);
	q = new Queue(maxclients);
}
//-----------------------------------------------------------------------------

Distributor::~Distributor()
/* Free memory and close library if needed */
{
	delete s;
	delete q;
#if defined(_WIN32)
	close_winsock();
#endif
}
//-----------------------------------------------------------------------------

int Distributor::addClient(const char *ip, const char *port)
/* Add client to queue and its socket to selector */
{
	int id = q->addClient(ip, port);
	Client *c = q->getClient(id);
	if(c == NULL) return -1;
	s->taddSocket(c->getSocket(), TS_MODE_R);
	s->taddSocket(c->getSocket(), TS_MODE_W); // not sure if it's needed
	return id;
}
//-----------------------------------------------------------------------------

void Distributor::removeClient(int id)
/* Remove client from queue and its socket from selector */
{
	s->tremoveSocket(q->getClient(id)->getSocket()->tgetInstanceName());
	q->removeClient(id);
}
//-----------------------------------------------------------------------------

int Distributor::sendData(int id, void *data)
/* Send data to client of given ID */
{
	header hdr;
	memcpy(&hdr, data, sizeof(header));
	return q->getClient(id)->getSocket()->tsend((char*)data, hdr.len);
}
//-----------------------------------------------------------------------------

int Distributor::recvData(int *id, void *buffer)
/* Receive all sent data, fill up id with id of sending client,
 * buffer with received data */
{
	memset(buffer, 0, sizeof(buffer));
	tsocket *S = s->twait();
	if(S == NULL) return NULL;
	void *rec_buf = malloc(sizeof(buffer));
	header hdr;
	int hdrlen = sizeof(header);
	int len = 0;

	int rec_count = 0;
	do // be sure to receive all data sent
	{
		int n = 0;
		if((n = S->treceive((char*)rec_buf)) == -1) perror("tRECEIVE");
		if(n == 0) return -1; // connection reset by peer
		if(rec_count == 0) // copy header only at first loop pass
		{
			memcpy(&hdr, rec_buf, hdrlen);
			len = hdr.len - hdrlen;
		}
		memcpy(buffer+(rec_count-hdrlen), rec_buf, n);
		rec_count += n;
	}
	while(rec_count < hdr.len);
	free(rec_buf);

	*id = q->getClientBySocket(S)->getID();
	return rec_count;
}
//-----------------------------------------------------------------------------

int Distributor::sendTransferPerm(int id)
/* Send transfer permission packet to client */
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
/* Return client from queue */
{
	return this->q->getClient(id);
}
//-----------------------------------------------------------------------------

void Distributor::dump(void)
/* Print all clients in distributor */
{
	this->q->dump();
}
//-----------------------------------------------------------------------------

int initClients(void)
{

}
//-----------------------------------------------------------------------------