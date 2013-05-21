/* distributor.h -- timetable distribution, class header
 * Copyright (C) 2013 daneos
 * See LICENSE for legal information
 */

#if !defined(__DISTRIBUTOR_H__)
#	define __DISTRIBUTOR_H__
//-----------------------------------------------------------------------------
#include "include/tsocket.h"
#include "clientqueue.h"
#include "ttproto.h"
//-----------------------------------------------------------------------------

class Distributor
{
protected:
	tselector *s;
	Queue *q;

public:
	Distributor(int maxclients, const char *port);
	~Distributor();
	int addClient(const char *ip, const char *port);
	void removeClient(int id);
	int sendData(int id, header *hdr, void *data);
	int recvData(int *id, void *buffer);
	int sendTransferPerm(int id);
	Client *getClient(int id);
	void dump(void);
	//--- PROTOCOL IMPLEMENTATION ---//
	int initClients(void);					// sent to all clients
	int sendPopulation(int id, void *data);	// require id 
	int dataWait(void);						// do not need any input
	int instruct(int id, void *data);		// require client id
	int shutdown(void);						// sent to all
};

#endif /*__DISTRIBUTOR_H__ */

/** How to use it:
	
	initClients();
	sendPopulation();
	flag = 0;
	while(!flag)
	{
		dataWai()
		instruct()
	}