/* clientqueue.h -- timetable distribution, client queue class source
 * Copyright (C) 2013 daneos
 * See LICENSE for legal information
 */

#include "clientqueue.h"
#include <time.h>
//-----------------------------------------------------------------------------

Client::Client(const char *ip, const char *port)
{
	srand(time(NULL));	// THIS HAS TO BE CHANGED, RANDOM RESULTS ONLY WHEN CALLED IN TIME MORE THAN 1sec
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

Queue::Queue(int maxclients)
{
	this->index = 0;
	this->list = (Client**)malloc(sizeof(Client*) * maxclients);
}
//-----------------------------------------------------------------------------

Queue::~Queue()
{
	if(this->index == 0) return;
	for(int i=0; i <= this->index; i++) delete this->list[i];
}
//-----------------------------------------------------------------------------

int Queue::addClient(const char *ip, const char *port)
{
	//this->list[this->index] = (Client*)malloc(sizeof(Client*));
	this->list[this->index] = new Client(ip, port);
	return this->list[this->index++]->getID();
}
//-----------------------------------------------------------------------------

void Queue::removeClient(int id)
{
	delete this->getClient(id); // HERE IS THE BUG IN <Queue::getClient()>
}
//-----------------------------------------------------------------------------

Client **Queue::getList(void)
{
	return this->list;
}
//-----------------------------------------------------------------------------

Client *Queue::getClient(int id)
{
	for(int i=0; i <= this->index; i++) if(this->list[i]->getID() /* big BOOM if any of clients have been deleted */ == id) return this->list[i];
	return NULL;
}
//-----------------------------------------------------------------------------