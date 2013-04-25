/* clientqueue.h -- timetable distribution, client queue class source
 * Copyright (C) 2013 daneos
 * See LICENSE for legal information
 */

#include "clientqueue.h"
//-----------------------------------------------------------------------------

Client::Client(const char *ip, const char *port)
{
	this->id = rand(); //randomize client id
	char instance_name[32];
	sprintf(instance_name, "terve://socket/%x", this->id);
	this->sock = new tsocket(SOCK_STREAM, instance_name);
}
//-----------------------------------------------------------------------------

Client::~Client()
{
	delete this->sock;
}
//-----------------------------------------------------------------------------

int Client::getID(void)
{
	return this->id;
}
//-----------------------------------------------------------------------------

tsocket *Client::getSocket(void)
{
	return this->sock;
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

Queue::Queue()
{
	this->index = 0;
}
//-----------------------------------------------------------------------------

Queue::~Queue()
{
	for(int i=0; i <= this->index; i++) delete this->list[i];
}
//-----------------------------------------------------------------------------

int addClient(const char *ip, const char *port)
{
	this->list[this->index++] = (Client*)malloc(sizeof(Client*));
	this->list[this->index] = new Client(ip, port);
	return this->list[this->index]->getID();
}
//-----------------------------------------------------------------------------

void removeClient(int id)
{
	delete this->getClient(id);
}
//-----------------------------------------------------------------------------

Client **getList(void)
{
	return this->list;
}
//-----------------------------------------------------------------------------

Client *getClient(int id)
{
	for(int i=0; i <= this->index; i++) if(this->list[i]->getID() == id) return this->list[i];
}
//-----------------------------------------------------------------------------