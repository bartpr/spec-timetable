/* terve/tsocket.h -- socket support for terve, class header
 * Copyright (C) 2012 daneos.com
 * See LICENSE for legal information
 */

//#define __DEBUG

#if !defined(__tSOCKET_H__)
#	define __tSOCKET_H__
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_WIN32)
#	include <winsock2.h>
#	include <ws2tcpip.h>
#else
#	include <unistd.h>
 
#	include <sys/types.h>
#	include <sys/socket.h>
#	include <netinet/in.h>
#	include <netdb.h>
#	include <arpa/inet.h>
#endif

//#include "ieee_754.h"
//-----------------------------------------------------------------------------

#define TS_NO_READ		0
#define TS_NO_WRITE		1
#define TS_NO_RW		2
#define IPv4			4
#define IPv6			6
#define MESSAGE_LEN		512
#define TS_MODE_R		0
#define TS_MODE_W		1
#define LEN_AUTO		-1

//-----------------------------------------------------------------------------

typedef struct addrinfo 		us_addrinfo;			// renaming unix socket structs
typedef struct sockaddr			us_sockaddr;
typedef struct sockaddr_storage	us_sockaddr_s;
typedef struct sockaddr_in		us_sockaddr4;
typedef struct sockaddr_in6		us_sockaddr6;
typedef fd_set					sockset;
//-----------------------------------------------------------------------------

#if defined(_WIN32)
	inline int init_winsock(int v1, int v2);
	inline void close_winsock(void);
#endif

class tsocket
{
protected:
	int fsocket;
	us_addrinfo *address;
	int type;
	char in[32];

public:
	tsocket(int socktype, const char *instance_name);
	~tsocket();
	int taddress(const char *name, const char *port);
	int topen(void);
	int tbind(void);
	int tconnect(void);
	int tlisten(int max);
	tsocket *taccept(void);
	int tsend(const char *message, int len);
	int treceive(char *buffer);
	int tclose(int mode);
	int tgetAddress(char *addr);
	int tgetPort(void);
	char *tgetInstanceName(void);
	int tgetDescriptor(void);
	/// ADD TO ORIGINAL TSOCKET AND RECOMPILE
	us_sockaddr_s *tgetBinIP(void);
	/////////////////////////////////////////
};
//-----------------------------------------------------------------------------

typedef struct __tcontainer {
								int __tsM;
								tsocket *__tsO;
							} tcontainer;
//-----------------------------------------------------------------------------

class tselector
{
protected:
	tcontainer *socktab;
	int count;
	int to;
	int max;
	bool *avl;
	sockset read;
	sockset write;
	int maxfd;

public:
	tselector(int max_socks);
	~tselector();
	int taddSocket(tsocket *sock, int mode);
	int tremoveSocket(const char *sock);
	tsocket *twait(void);
	int tsetTimeout(int t);
};

#endif /* __tSOCKET_H__ */
