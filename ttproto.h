/* ttproto.h -- timetable distribution protocol
 * Copyright (C) 2013 daneos
 * See LICENSE for legal information
 */

#if !defined(__TTPROTO_H__)
#	define __TTPROTO_H__
//-----------------------------------------------------------------------------
#include <stdint.h>
//-----------------------------------------------------------------------------
// Protocol codes
#define INITIALZ		0x00	// init client
#define INITPOPL		0x01	// initial population
#define DATAREQT		0x02	// data request
#define ACKNWLGD		0x03	// acknowledged
#define DATADATA		0x04	// data (general purpose)
#define INSTRUCT		0x05	// instructions
#define PERMISSN		0x06	// transfer permission
#define CLOSEALL		0xFF	// shutdown
//-----------------------------------------------------------------------------

typedef struct _header {
	uint32_t len;
	uint8_t code;
} PACKED header;
//-----------------------------------------------------------------------------

#endif /* __TTPROTO_H__ */
 