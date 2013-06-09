/* clientqueue.h -- timetable distribution, client queue class header
 * Copyright (C) 2013 daneos
 * See LICENSE for legal information
 */

#if !defined(__CLIENTQUEUE_H__)
#	define __CLIENTQUEUE_H__
//-----------------------------------------------------------------------------
#include "include/tsocket.h"
//-----------------------------------------------------------------------------

class Client
{
protected:
	int id;
	tsocket *sock;
	bool connstate;

public:
	Client(const char *ip, const char *port);
	~Client();
	tsocket *getSocket();
	int getID(void);
	void dump(void);
	int connect(void);
	bool connected(void);
};
//-----------------------------------------------------------------------------

class Queue
{
protected:
	int index;
	Client **list;

public:
	Queue(int maxclients);
	~Queue();
	int addClient(const char *ip, const char *port);
	void removeClient(int id);
	Client **getList(void);
	Client *getClient(int id);
	Client *getClientBySocket(tsocket *sock);
	void dump(void);
	int getIndex(void);
};
//-----------------------------------------------------------------------------

int idgen(void);

#endif /* __CLIENTQUEUE_H__ */