/* distributor.cpp -- timetable distribution, class source
 * Copyright (C) 2013 daneos.com
 * See LICENSE for legal information
 */

#include "distributor.h"
//-----------------------------------------------------------------------------

Distributor::Distributor(int maxclients, const char *port)
{
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
}
//-----------------------------------------------------------------------------