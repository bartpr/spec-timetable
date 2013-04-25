/* clientqueue.h -- timetable distribution, client queue class source
 * Copyright (C) 2013 daneos
 * See LICENSE for legal information
 */

#include "clientqueue.h"
//-----------------------------------------------------------------------------

Client::Client(const char *ip, const char *port)
{
	this->id = rand(); //randomize client id
	this->sock = new tsocket(SOCK_STREAM, "CHANGE_ME"); // here goes randomized id as a string
}
//-----------------------------------------------------------------------------

Client::~Client()
{

}
//-----------------------------------------------------------------------------

Client::getID(void)
{
	return this->id;
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
}
//-----------------------------------------------------------------------------

void removeClient(int id)
{
	for(int i=0; i <= this->index; i++)	if(this->list[i]->getID() == id) delete this->list[i];
}
//-----------------------------------------------------------------------------