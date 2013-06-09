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
	listener->taddress(NULL, port);
	listener->topen();
	listener->tbind();
	listener->tlisten(1);
	s->tAddSocket(listener, TS_MODE_R)
	this->role = role;
}
//-----------------------------------------------------------------------------

dClient::~dClient()
{
	s->tclose(TS_NO_RW);
	delete D;
	delete s;
	delete listener;
}
//-----------------------------------------------------------------------------