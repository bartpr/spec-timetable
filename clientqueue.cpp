/* clientqueue.h -- timetable distribution, client queue class source
 * Copyright (C) 2013 daneos
 * See LICENSE for legal information
 */

#include "clientqueue.h"

#if defined(_WIN32)
#	include <stdlib.h>
#else
#	include <fcntl.h>
#endif

#include <math.h>
#include <stdio.h>
//-----------------------------------------------------------------------------

Client::Client(const char *ip, const char *port)
/* Initialize id and create client socket */
{
	this->id = idgen();
	char instance_name[32];
	sprintf(instance_name, "terve://socket/%x", this->id);
	this->sock = new tsocket(SOCK_STREAM, instance_name);
	this->sock->taddress(ip, port);
}
//-----------------------------------------------------------------------------

Client::~Client()
/* Memory cleanup */
{
	this->sock->tclose(TS_NO_RW);
	delete this->sock;
}
//-----------------------------------------------------------------------------

int Client::getID(void)
/* Return client ID */
{
	return this->id;
}
//-----------------------------------------------------------------------------

tsocket *Client::getSocket(void)
/* Return client's communication socket */
{
	return this->sock;
}
//-----------------------------------------------------------------------------

void Client::dump(void)
/* Print client information */
{
	printf("%-12d [ %-25s ] (%d)\n",
			id,
			this->sock->tgetInstanceName(),
			this->sock->tgetDescriptor()
	);
}
//-----------------------------------------------------------------------------

int Client::connect(void)
/* Open connection to client */
{
	if(!this->sock->topen()) return -1;
	return this->sock->tgetDescriptor();
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

Queue::Queue(int maxclients)
/* Initialize list of clients */
{
	this->index = 0;
	this->list = (Client**)malloc(sizeof(Client*) * maxclients);
}
//-----------------------------------------------------------------------------

Queue::~Queue()
/* Cleanup and remove list */
{
	if(this->index == 0) free(list);
	else
	{
		for(int i=0; i < this->index; i++)
			if(this->list[i] != NULL) delete this->list[i];
		free(list);
	}
}
//-----------------------------------------------------------------------------

int Queue::addClient(const char *ip, const char *port)
/* Create new client in list */
{
	this->list[this->index] = new Client(ip, port);
	return this->list[this->index++]->getID();
}
//-----------------------------------------------------------------------------

void Queue::removeClient(int id)
/* Remove client */
{
	Client *c = this->getClient(id);
	delete c;
	c = NULL;
}
//-----------------------------------------------------------------------------

Client **Queue::getList(void)
/* Return client list
 * Should not be used directly, instead use Queue::getClient() */
{
	return this->list;
}
//-----------------------------------------------------------------------------

Client *Queue::getClient(int id)
/* Return client for given ID */
{
	for(int i=0; i < this->index; i++) 
		if(this->list[i] != NULL)
			if(this->list[i]->getID() == id) return this->list[i];
	return NULL;
}
//-----------------------------------------------------------------------------

Client *Queue::getClientBySocket(tsocket *sock)
{
	for(int i=0; i < this->index; i++) 
		if(!strcmp(this->list[i]->getSocket()->tgetInstanceName(), sock->tgetInstanceName()))
			return this->list[i];
	return NULL;
}
//-----------------------------------------------------------------------------

void Queue::dump(void)
/* Print all clients' in list information */
{
	for(int i=0; i < this->index; i++) 
		if(this->list[i] != NULL)
			this->list[i]->dump();
}
//-----------------------------------------------------------------------------

int Queue::getIndex(void)
{
	return this->index;
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

int idgen(void)
/* Generate completely random ID */
{
	int cid = 0;
#if defined(_WIN32)
	cid = atoi(getenv("RANDOM"));
#else
	int fd = open("/dev/urandom", O_RDONLY, NULL);
	read(fd, &cid, sizeof(cid));
	close(fd);
#endif
	return abs(cid);
}
//-----------------------------------------------------------------------------