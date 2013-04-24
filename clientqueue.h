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
	tsocket sock;

public:
	Client();
	~Client();
};
//-----------------------------------------------------------------------------

class Queue
{
protected:
	Client *list;

public:
	Queue();
	~Queue();
};

#endif /*__CLIENTQUEUE_H__ */