/* Completely dummy main file, only for testing */

#include <stdio.h>
#include "distributor.h"

int main(void)
{
	Distributor *D = new Distributor(200, "1003");
	printf("D ok\n");
	int id = D->addClient("127.0.0.1", "5555");
	printf("add ok\n");
	printf("Added client %d, socket <%s>\n", id, D->getClient(id)->getSocket()->tgetInstanceName());
	printf("get ok\n");
	id = D->addClient("127.0.0.1", "5555");
	printf("add ok\n");
	printf("Added client %d, socket <%s>\n", id, D->getClient(id)->getSocket()->tgetInstanceName());
	printf("get ok\n");
	id = D->addClient("127.0.0.1", "5555");
	printf("add ok\n");
	printf("Added client %d, socket <%s>\n", id, D->getClient(id)->getSocket()->tgetInstanceName());
	printf("get ok\n");
	delete D;
	printf("delete ok\n");
	return 0;
}