/* Completely dummy main file, only for testing */

#include <stdio.h>
#include "dclient.h"

void runClient(void);
void runServer(void);

int main(void)
{
	printf("(c)lient or (s)erver: ");
	char choice = getchar();
	switch(choice)
	{
		case 'C':
		case 'c':
			runClient();
			break;
		case 'S':
		case 's':
			runServer();
			break;
		default:
			printf("Error.\n");
			break;
	}
	return 0;
}

void runClient(void)
{
	printf("CLIENT\n");
	dClient *client = new dClient(ROLE_CLIENT, "1996", 200);
	char buffer[100];
	memset(buffer, 0 ,100);
	client->receive(buffer);
	printf("Received %s\n", buffer);

	delete client;
}

void runServer(void)
{
	printf("SERVER\n");
	dClient *server = new dClient(ROLE_SERVER, NULL, 200);
	printf("dclient ok\n");
	int cid = server->getDistributor()->addClient("127.0.0.1", "1996");
	printf("add ok\n");
	printf("Waiting for client <%d> to connect", cid);
	while(!server->getDistributor()->getClient(cid)->connected())
	{
		printf(".");
		server->getDistributor()->getClient(cid)->connect();
	}
	server->sendTo(cid, (void*)"teeeeest");
	printf("\nMessage sent to client <%d>.\n", cid);
	char tmp[100];
	memset(tmp, 0, 100);
	int got_id = 0;
	int n = server->getDistributor()->recvData(&got_id, (void*)tmp);
	printf("Received %s (%d bytes) from <%d>\n", tmp, n, got_id);

	delete server;
}