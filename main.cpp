/* Completely dummy main file, only for testing */

#include <stdio.h>
#include "distributor.h"

int main(void)
{
	Distributor *D = new Distributor(200);
	printf("D ok\n");
	int id = D->addClient("127.0.0.1", "5555");
	printf("add ok\n");
	printf("Added client "); D->getClient(id)->dump();
	printf("get ok\n");
	id = D->addClient("127.0.0.1", "5555");
	printf("add ok\n");
	printf("Added client "); D->getClient(id)->dump();
	printf("get ok\n");
	id = D->addClient("127.0.0.1", "5555");
	printf("add ok\n");
	printf("Added client "); D->getClient(id)->dump();
	printf("get ok\n");
	D->dump();
	//printf("Initialized %d clients\n", D->initClients());perror("main");
	delete D;
	printf("delete ok\n");
	printf("%p\n", D);
	// tsocket *s = new tsocket(SOCK_STREAM, "testing");
	// s->taddress(NULL, "9989");
	// printf("%d", s->tgetPort());
	return 0;
}