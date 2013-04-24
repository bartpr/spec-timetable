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
	clients = new tselector(maxclients);
	listener = new tsocket(SOCK_STREAM, "terve://socket/0");
	if(listener->taddress(NULL, port) == -1) perror("tADDRESS");
	if(listener->topen() == -1) perror("tOPEN");
	if(listener->tbind() == -1) perror("tBIND");
	if(listener->tlisten(1) == -1) perror("tLISTEN");
	clients->taddSocket(listener, TS_MODE_R);
}
//-----------------------------------------------------------------------------

Distributor::~Distributor()
{
	delete clients;
	delete listener;
#if defined(_WIN32)
	close_winsock();
#endif
}
//-----------------------------------------------------------------------------

int Distributor::addClient(const char *ip, const char *port)
{

}
//-----------------------------------------------------------------------------

void Distributor::removeClient(int id)
{

}
//-----------------------------------------------------------------------------