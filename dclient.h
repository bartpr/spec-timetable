/* dclient.h -- timetable distribution client, class header
 * Copyright (C) 2013 daneos
 * See LICENSE for legal information
 */

#if !defined(__DCLIENT_H__)
#	define __DCLIENT_H__
//-----------------------------------------------------------------------------
#include "distributor.h"
//-----------------------------------------------------------------------------

class dClient
{
protected:

public:
	void *returnDistribution(void);
	//--- PROTOCOL IMPLEMENTATION ---//
	int waitInit(void);
	int waitPopulation(void);
	int wait(void);
	int sendData(void);
	int waitInstruct(void);

};
//-----------------------------------------------------------------------------

void *mkpacket(header *hdr, void *data);

#endif /* __DCLIENT_H__ */