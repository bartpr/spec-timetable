//---------------------------------------------------------------------------

#pragma hdrstop
#include <iostream>
#include <GenPacket.h>
#include <tsocket.h>
#include <winsock2.h>


using namespace std;




bool WinsockInit()
{
  WSADATA WSAData;
  if (WSAStartup(MAKEWORD(2,2),&WSAData) != 0)
  {
      return FALSE;
  }
  else
  {
      return TRUE;
  }
}













//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
        WinsockInit();


        GenPacket *pack = new GenPacket;
        char *str = new char[20];
        memset(str,'\0',20);
        strcpy(str,"chuj ci w dupala");
        delete []str;
        str = NULL;
        str = new char[20];
        str = "chuj ci w dupala";

        pack->setValue(str,strlen(str));
        delete []str;
        pack->setPacketCode(13);
        validationPacket(pack->getPacket());

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




