/* ttproto.cpp -- timetable distribution protocol
 * Copyright (C) 2013 daneos
 * See LICENSE for legal information
 */

 #include "ttproto.h"
 #include <string.h>
//-----------------------------------------------------------------------------

int mkpacket(void *destination, int code, void *data, int datalen)
{
	header hdr;
	hdr.code = code;
	hdr.len = sizeof(header) + datalen;

	memcpy(destination, &hdr, sizeof(header));
	memcpy(destination+sizeof(header), data, datalen);

	return hdr.len;
}
//-----------------------------------------------------------------------------

int dcpacket(void *destination, int *code, void *data)
{
	header hdr;
	memcpy(&hdr, data, sizeof(header));
	memcpy(destination, data+sizeof(header), hdr.len-sizeof(header));
	*code = hdr.code;
	return hdr.len - sizeof(header);
}
//-----------------------------------------------------------------------------