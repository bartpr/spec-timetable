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
	q = new Queue();
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
	s->taddSocket(q->getClient(id)->getSocket(), TS_MODE_R);
	s->taddSocket(q->getClient(id)->getSocket(), TS_MODE_W);
}
//-----------------------------------------------------------------------------

void Distributor::removeClient(int id)
{
	q->removeClient(id);
}
//-----------------------------------------------------------------------------

int Distributor::sendData(int id, header *hdr, void *data)
{

}
//-----------------------------------------------------------------------------

int Distributor::recvData(int *id, void *buffer)
{

}
//-----------------------------------------------------------------------------

int Distributor::sendTransferPerm(int id)
{

}
//-----------------------------------------------------------------------------