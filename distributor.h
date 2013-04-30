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
	int sendData(int id, packet data);
	int recvData(int *id, packet *buffer);
	int sendTransferPerm(int id);
};

#endif /*__DISTRIBUTOR_H__ */