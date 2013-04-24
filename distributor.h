/* distributor.h -- timetable distribution, class header
 * Copyright (C) 2013 daneos.com
 * See LICENSE for legal information
 */

#if !defined(__DISTRIBUTOR_H__)
#	define __DISTRIBUTOR_H__
//-----------------------------------------------------------------------------
#include "include/tsocket.h"
//-----------------------------------------------------------------------------
#define MAX_CLIENTS		2048

class Distributor
{
protected:
	tselector *clients;
	tsocket *listener;

public:
	Distributor(int maxclients, const char *port);
	~Distributor();

};

#endif /*__DISTRIBUTOR_H__ */