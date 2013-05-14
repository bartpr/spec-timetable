//---------------------------------------------------------------------------

#pragma hdrstop
#include <iostream>
#include "ttproto.h"
#include <winsock2.h>

using namespace std;


class WSAInitializer
{
 public:
        bool init();
};

class GeneticListener
{
  unsigned int initialized;
  string ip;
  string port;

  public:
  GeneticListener();

  void setIP(string ip);
  void setPort(string port);
  void run();
  bool is_initialized();
};

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
        WSAInitializer ws;
        ws.init();

        GeneticListener lst;
        lst.setIP("127.0.0.1");
        lst.setPort("10000");
        lst.run();
        cout << lst.is_initialized();


        getchar();
        return 0;
}
//---------------------------------------------------------------------------


GeneticListener::GeneticListener()
{
 initialized = 0;
}

void GeneticListener::setIP(string ip)
{
 this->ip = ip;
 if((initialized & 1) == false)
 {
  initialized +=1;
 }
}

void GeneticListener::setPort(string port)
{
 this->port = port;
 if((initialized & 2) == false)
 {
  initialized +=2;
 }

}


void GeneticListener::run()
{
  if((initialized & 4) == false)
  {
        initialized +=4;
  }

  //Wystartowanie

}

bool GeneticListener::is_initialized()
{
 cout << initialized;
 if(initialized == 7)
 {
  return true;
 }
 else
 {
  return false;
 }

}

bool WSAInitializer::init()
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
