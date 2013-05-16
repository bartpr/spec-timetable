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
  char *value;
  unsigned int valueLen;

  void initializeDefaultValues();

  public:
  GenPacket();
  GenPacket(void *packet);

  unsigned int getPacketSize();
  unsigned int getValueSize();
  void *getValue();
  char *getValueAsCString();


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

        char *t = "hello word";
        void *packet = createPacket(t, strlen(t)+1,2);
        int i = 0;
        for(;;i++) if(((char*)packet+5)[i] == '\0') break;
        cout << i;

        GenPacket *p = new GenPacket(packet);
        cout << p->getPacketSize() << endl;
        cout << p->getValueSize() << endl;
        cout << p->getValueAsCString() << endl;

        delete p;
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
  value = NULL;
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

  cout << endl << head->len;
  if(head->len > 5)
  {
  this->valueLen = head->len - 5;
  value = new char[this->valueLen+1];
  memcpy(value,((char*)packet)+5,this->valueLen); //!!!!!!!!!
  }
  else
  {
   value = NULL;
  }


}

unsigned int GenPacket::getPacketSize()
{
  if(head == NULL && value == NULL )return 0;
  else if(value == NULL) return 5;
  else
  {
   return 5 + this->valueLen;
  }
}

void *GenPacket::getValue()
{
 return (void*)this->value;
}

unsigned int GenPacket::getValueSize()
{
   return this->valueLen;
}

char *GenPacket::getValueAsCString()
{
   return this->value;
}
