/* clientqueue.h -- timetable distribution, client queue class source
 * Copyright (C) 2013 daneos
 * See LICENSE for legal information
 */

#include "clientqueue.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
//-----------------------------------------------------------------------------

Client::Client(const char *ip, const char *port)
{
	this->id = idgen();
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

char *Client::dump(void)
{
	printf("%d [ %s ] (%d)\n",
			id,
			this->sock->tgetInstanceName(),
			this->sock->tgetDescriptor()
	);
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
	if(this->index == 0) free(list);
	else
	{
		for(int i=0; i <= this->index; i++)
			if(this->list[i] != NULL) delete this->list[i];
		free(list);
	}
}
//-----------------------------------------------------------------------------

int Queue::addClient(const char *ip, const char *port)
{
	this->list[this->index] = new Client(ip, port);
	return this->list[this->index++]->getID();
}
//-----------------------------------------------------------------------------

void Queue::removeClient(int id)
{
	Client *c = this->getClient(id);
	delete c;
	c = NULL;
}
//-----------------------------------------------------------------------------

Client **Queue::getList(void)
{
	return this->list;
}
//-----------------------------------------------------------------------------

Client *Queue::getClient(int id)
{
	for(int i=0; i <= this->index; i++) 
		if(this->list[i] != NULL)
			if(this->list[i]->getID() == id) return this->list[i];
	return NULL;
}
//-----------------------------------------------------------------------------

Client *Queue::getClientBySocket(tsocket *sock)
{
	for(int i=0; i <= this->index; i++) 
		if(!strcmp(this->list[i]->getSocket()->tgetInstanceName(), sock->tgetInstanceName()))
			return this->list[i];
	return NULL;
}
//-----------------------------------------------------------------------------

void Queue::dump(void)
{
	for(int i=0; i <= this->index; i++) 
		if(this->list[i] != NULL)
			this->list[i]->dump();
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

int idgen(void)
{
	int cid = 0;
	int fd = open("/dev/urandom", O_RDONLY, NULL);
	read(fd, &cid, sizeof(cid));
	close(fd);
	return abs(cid);
}
//-----------------------------------------------------------------------------