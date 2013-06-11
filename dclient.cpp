/* dclient.cpp -- timetable distribution client, class source
 * Copyright (C) 2013 daneos
 * See LICENSE for legal information
 */

#include "dclient.h"
//-----------------------------------------------------------------------------

dClient::dClient(int role, char *port, int maxclients)
{
	D = new Distributor(maxclients);
	s = new tselector(1);
	listener = new tsocket(SOCK_STREAM, "terve://socket/listen0");
	if(role == ROLE_CLIENT)
	{
		listener->taddress(NULL, port);
		listener->topen();
		listener->tbind();
		listener->tlisten(1);
	}
	s->taddSocket(listener, TS_MODE_R);
	this->role = role;
}
//-----------------------------------------------------------------------------

dClient::~dClient()
{
	listener->tclose(TS_NO_RW);
	delete D;
	delete s;
	delete listener;
}
//-----------------------------------------------------------------------------

Distributor *dClient::getDistributor(void)
{
	return D;
}
//-----------------------------------------------------------------------------

int dClient::receive(void *buffer)
{
	memset(buffer, 0, sizeof(buffer));
	void *rec_buf = malloc(sizeof(buffer));
	header hdr;
	int hdrlen = sizeof(header);
	int len = 0;

	int rec_count = 0;
	do // be sure to receive all data sent
	{
		int n = 0;
		if((n = listener->treceive((char*)rec_buf)) == -1) perror("tRECEIVE");
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

	return rec_count;
}
//-----------------------------------------------------------------------------

int dClient::sendTo(int id, void *data)
{
	Client *c = D->getClient(id);
	if(!c->connected()) c->connect();
	D->sendData(id, data);
}
//-----------------------------------------------------------------------------