/* distributor.cpp -- timetable distribution, class source
 * Copyright (C) 2013 daneos
 * See LICENSE for legal information
 */

#include "distributor.h"
//-----------------------------------------------------------------------------

Distributor::Distributor(int maxclients, const char *port)
/* Create socket selector and client queue
 * Initialize network if applicable */
{
#if defined(_WIN32)
	init_winsock(2,0);
#endif
	s = new tselector(maxclients);
	q = new Queue(maxclients);
}
//-----------------------------------------------------------------------------

Distributor::~Distributor()
/* Free memory and close library if needed */
{
	delete s;
	delete q;
#if defined(_WIN32)
	close_winsock();
#endif
}
//-----------------------------------------------------------------------------

int Distributor::addClient(const char *ip, const char *port)
/* Add client to queue and its socket to selector */
{
	int id = q->addClient(ip, port);
	Client *c = q->getClient(id);
	if(c == NULL) return -1;
	s->taddSocket(c->getSocket(), TS_MODE_R);
	s->taddSocket(c->getSocket(), TS_MODE_W); // not sure if it's needed
	return id;
}
//-----------------------------------------------------------------------------

void Distributor::removeClient(int id)
/* Remove client from queue and its socket from selector */
{
	s->tremoveSocket(q->getClient(id)->getSocket()->tgetInstanceName());
	q->removeClient(id);
}
//-----------------------------------------------------------------------------

int Distributor::sendData(int id, void *data)
/* Send data to client of given ID */
{
	header hdr;
	memcpy(&hdr, data, sizeof(header));
	return q->getClient(id)->getSocket()->tsend((char*)data, hdr->len);
}
//-----------------------------------------------------------------------------

int Distributor::recvData(int *id, void *buffer)
/* Receive all sent data, fill up id with id of sending client,
 * buffer with received data */
{
	memset(buffer, 0, sizeof(buffer));
	tsocket *S = s->twait();
	if(S == NULL) return NULL;
	void *rec_buf = malloc(sizeof(buffer));
	header *hdr;
	int hdrlen = sizeof(header);
	int len = 0;

	int rec_count = 0;
	do // be sure to receive all data sent
	{
		int n = 0;
		if((n = S->treceive((char*)rec_buf)) == -1) perror("tRECEIVE");
		if(n == 0) return -1; // connection reset by peer
		if(rec_count == 0) // copy header only at first loop pass
		{
			memcpy(hdr, rec_buf, hdrlen);
			len = hdr->len - hdrlen;
		}
		memcpy(buffer+(rec_count-hdrlen), rec_buf, n);
		rec_count += n;
	}
	while(rec_count < hdr->len);

	*id = q->getClientBySocket(S)->getID();
	return rec_count;
}
//-----------------------------------------------------------------------------

int Distributor::sendTransferPerm(int id)
/* Send transfer permission packet to client */
{
	header *hdr = (header*)malloc(sizeof(header));
	hdr->len = sizeof(hdr);
	hdr->code = PERMISSN;
	int status = q->getClient(id)->getSocket()->tsend((char*)hdr, hdr->len);
	free(hdr);
	return status;
}
//-----------------------------------------------------------------------------

Client *Distributor::getClient(int id)
/* Return client from queue */
{
	return this->q->getClient(id);
}
//-----------------------------------------------------------------------------

void Distributor::dump(void)
/* Print all clients in distributor */
{
	this->q->dump();
}
//-----------------------------------------------------------------------------

/*int Distributor::initClients(void)
/* Initialize all clients in queue */
/*{
	int index = this->q->getIndex();
	Client **list = this->q->getList();
	uint32_t i = 0;
	void *buffer = malloc(sizeof(uint32_t)+index*(sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t)));
					// sizeof(uint32_t) - number of client
					// index - multiply by number of clients
					// sizeof(uint32_t) - id
					// sizeof(uint32_t) - ip addr
					// sizeof(uint32_t) - port
					// all values in NBO
	for(i=0; i < index; i++)
	{
		if(list[i] != NULL)
		{
			uint32_t id = htonl(list[i]->getID());
			uint32_t port = htonl(list[i]->getSocket()->tgetPort());
			uint32_t ip = 0; // TODO: get binary IP from tsocket
					// copy id to buffer (1st entry of each record)
			memcpy(buffer+sizeof(uint32_t) + i*(3*sizeof(uint32_t)), &id, sizeof(uint32_t));
					// copy ip to buffer (2nd entry of each record) 
			memcpy(buffer+sizeof(uint32_t) + (i+1)*(3*sizeof(uint32_t)) - 2*sizeof(uint32_t), &ip, sizeof(uint32_t));
					// copy port to buffer (3rd entry of each record)
			memcpy(buffer+sizeof(uint32_t) + (i+1)*(3*sizeof(uint32_t)) - sizeof(uint32_t), &port, sizeof(uint32_t)); 
		}
	}
	i = htonl(i);
	memcpy(buffer, &i, sizeof(uint32_t)); // copy number of clients
	int len = sizeof(header) + sizeof(buffer);
	void *send_buf = malloc(len);
	
	header hdr; // create packet header
	hdr.len = len;
	hdr.code = INITIALZ;

	memcpy(send_buf, &hdr, sizeof(hdr));
	memcpy(send_buf+sizeof(hdr), buffer, sizeof(buffer));

	for(i=0; i < index; i++)
	{ 
		if(list[i] != NULL)
		{
			if(list[i]->connect() == -1) return -1; // open connection to client
			list[i]->getSocket()->tsend((char*)send_buf, len); // send full client list to each client			
		}
	}
	free(buffer);
	free(send_buf);
	return i;
}
//-----------------------------------------------------------------------------

int Distributor::sendPopulation(int id, void *data)
/* Distribute initial population among the clients */
/*{
	header hdr;
	hdr.len = sizeof(hdr)+sizeof(data);
	hdr.code = INITPOPL;
	void *send_buf = malloc(hdr.len);
	memcpy(send_buf, &hdr, sizeof(hdr));
	memcpy(send_buf+sizeof(hdr), data, sizeof(data));
	int status = q->getClient(id)->getSocket()->tsend((char*)send_buf, hdr.len);
	free(send_buf);

	void *rec_buf = malloc(sizeof(header));
	return status;
}
//-----------------------------------------------------------------------------

int Distributor::dataWait(void)
/* Wait for data from clients */
/*{

}
//-----------------------------------------------------------------------------

int Distributor::instruct(int id, void *data)
/* Send instructions to clients */
/*{
	header hdr;
	hdr.len = sizeof(hdr)+sizeof(data);
	hdr.code = INITPOPL;
	void *send_buf = malloc(hdr.len);
	memcpy(send_buf, &hdr, sizeof(hdr));
	memcpy(send_buf+sizeof(hdr), data, sizeof(data));
	int status = q->getClient(id)->getSocket()->tsend((char*)send_buf, hdr.len);
	free(send_buf);
	return status;
}
//-----------------------------------------------------------------------------

int Distributor::shutdown(void)
/* Shutdown all clients */
/*{

}*/
//-----------------------------------------------------------------------------