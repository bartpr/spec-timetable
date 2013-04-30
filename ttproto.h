/* ttproto.h -- timetable distribution protocol
 * Copyright (C) 2013 daneos
 * See LICENSE for legal information
 */

#if !defined(__TTPROTO_H__)
#	define __TTPROTO_H__
//-----------------------------------------------------------------------------
#include <stdint.h>
//-----------------------------------------------------------------------------
#define INITIALZ		0x00	// init client
#define INITPOPL		0x01	// initial population
#define DATAREQT		0x02	// data request
#define ACKNWLGD		0x03	// acknowledged
#define DATADATA		0x04	// data (general purpose)
#define INSTRUCT		0x05	// instructions
#define PERMISSN		0x06	// transfer permission
#define CLOSEALL		0xFF	// shutdown
//-----------------------------------------------------------------------------

typedef uint32_t[1024] ttdata; // do something with this !!!

typedef struct _packet {
						uint32_t len;
						uint8_t code;
						ttdata data; // as most of packets will have no data, only codes, try to do it in other way
} __attribute__((packed)) packet;
//-----------------------------------------------------------------------------

#endif /* __TTPROTO_H__ */