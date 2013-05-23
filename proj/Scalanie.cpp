//---------------------------------------------------------------------------

#pragma hdrstop
#include <iostream>
#include "include/tsocket.h"
#include <winsock2.h>


using namespace std;

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
        WSADATA wsaData;
        int iResult;

        // Initialize Winsock
        iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
        if (iResult != 0) {
            printf("WSAStartup failed: %d\n", iResult);
            return 1;
        }


        tsocket *socket = new tsocket(SOCK_STREAM,"sock");
        socket->taddress(NULL,"1223");
        socket->topen();

        if(socket->tbind() == SOCKET_ERROR)
        {
         cout << "Blad bind" << endl;
        }

        cout << "Nastepuje odsluchiwanie";
        socket->tlisten(1);

        tsocket *client = socket->taccept();
        printf("%s\n", client->tgetInstanceName());
        getchar();
        return 0;
}
//---------------------------------------------------------------------------


