/* dclient.h -- timetable distribution client, class header
 * Copyright (C) 2013 daneos
 * See LICENSE for legal information
 */

#if !defined(__DCLIENT_H__)
#	define __DCLIENT_H__
//-----------------------------------------------------------------------------
#include "distributor.h"
//-----------------------------------------------------------------------------
#define ROLE_SERVER 0
#define ROLE_CLIENT 1
//-----------------------------------------------------------------------------

class dClient
{
protected:
	Distributor *D;
	tselector *s;
	tsocket *listener;
	int role;

public:
	dClient(int role, int maxclients);
	~dClient();
};
//-----------------------------------------------------------------------------

#endif /* __DCLIENT_H__ */