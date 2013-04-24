/* distributor.h -- timetable distribution, class header
 * Copyright (C) 2013 daneos
 * See LICENSE for legal information
 */

#if !defined(__DISTRIBUTOR_H__)
#	define __DISTRIBUTOR_H__
//-----------------------------------------------------------------------------
#include "include/tsocket.h"
#include "clientqueue.h"
//-----------------------------------------------------------------------------

class Distributor
{
protected:
	tselector *s;
	tsocket *listener; // do I need this ?
	Queue *q;

public:
	Distributor(int maxclients, const char *port);
	~Distributor();
	int addClient(const char *ip, const char *port);
	void removeClient(int id);
};

#endif /*__DISTRIBUTOR_H__ */