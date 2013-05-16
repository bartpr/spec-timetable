//---------------------------------------------------------------------------

#pragma hdrstop
#include <iostream>
#include "ttproto.h"
#include <winsock2.h>

using namespace std;

//Inicjalizacja winsock'a w srodowisku Windows
//Klasa odpowiadajaca za inicjalizacje
class WSAInitializer
{
        bool initialized;
 public:
        bool init();
        WSAInitializer();
};

//Klasa odpowiadajaca za stworzenie gniazda nasluchujacego
//od klientow i odbierania tych wiadomosci
class GeneticListener
{
  //inicjalizacja
  unsigned int initialized;
  string ip;
  string port;

  public:
  GeneticListener();

  void setIP(string ip);
  void setPort(string port);
  void run();

  //czy zainicjowano poprawnie dane
  bool is_initialized();
};

//klasa s³u¿¹ca do odczytania pakietu
class GenPacket
{
  header *head;
  void *value;
  unsigned int valueLen;

  void initializeDefaultValues();

  public:
  GenPacket();
  GenPacket(void *packet);

};


//Funkcja tworzy przykladowy pakiet
void *createPacket(void *value, int len, int code) //dlugosc 5 + len + 1
{
 char *result = new char[5 + len + 1];
 memset(result,'\0',5+len+1);

 header *h = new header;
 h->len = 5 + len;
 h->code = code;

 memcpy(result,h,5);
 memcpy(result+5,value,len);

 return (void*)result;
}



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
        cout << lst.is_initialized() << endl;
        cout << sizeof(header) << endl;

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

WSAInitializer::WSAInitializer()
{
 initialized = false;
}


GenPacket::GenPacket()
{
 initializeDefaultValues();
}

void GenPacket::initializeDefaultValues()
{
  head = NULL;
}

//wczytanie istniejacego pakietu
GenPacket::GenPacket(void *packet)
{
  //Inicjalizacja domyslnych wartosci
  initializeDefaultValues();

  //Pobranie pakietu [5b]
  head = new header;
  head = ((header*)packet);

  //Pobranie wartosci
  if(head->len > 5)
  {
   this->valueLen = head->len - 5;
   memcpy(value,((char*)packet)+5,this->valueLen); //!!!!!!!!!
  }
  else
  {
   value = NULL;
  }


}
