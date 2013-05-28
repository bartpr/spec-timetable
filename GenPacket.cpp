#include "GenPacket.h"
#include <ttproto.h>
#include <stdio.h>


//Generowanie pakietu
// * value -> wartosc dowolnego typu zrzutowana na typ void
// * len   -> dlugosc value w bajtach
// * code  -> kod pakietu ustalony w standardzie ttproto.h
//Dlugosc zwroconego pakietu: 5 + len + 1, gdzie len to ilosc bajtow
//Zawiera NULL terminatora
void *createPacket(void *value, int len, int code)
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

//******************************************************
//******************************************************

GenPacket::GenPacket()
{
 initializeDefaultValues();
 head = new header;
 head->len = 0;
 head->code = 0;

}

GenPacket ::  ~GenPacket()
{
 if(head != NULL)
 {
  delete head;
 }

 if(value != NULL)
 {
  delete value;
 }


}


void GenPacket::initializeDefaultValues()
{
  head = NULL;
  value = NULL;
  this->valueLen = 0;
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
    value = new char[this->valueLen+1];
    memcpy(value,((char*)packet)+5,this->valueLen); //!!!!!!!!!
  }
  else
  {
    value = NULL;
  }


}

//wielkosc pakietu w bajtach
unsigned int GenPacket::getPacketSize()
{
  if(head == NULL && value == NULL )return 0;
  else if(value == NULL) return 5;
  else
  {
   return 5 + this->valueLen;
  }
}


//zwraca wartosc pakietu
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

void GenPacket::setValue(void *value,int len)
{
    if(this->value != NULL)
    {
     delete this->value;
    }

    //Inicjalizacja pustego bufora wartosci
    this->value = new char[len+1];
    memset(this->value,'\0',len+1);

    //Ustalenie nowej wartosci
    memcpy(this->value,value,len);
    this->valueLen = len;
    head->len = 5 + len + 1;

}


void GenPacket::setPacketCode(int code)
{
     if(head != NULL)
     {
        head->code = code;
     }

}

void * GenPacket::getPacket()
{
  char *pack = new char[5 + valueLen + 1];
  memcpy(pack,this->head,5);
  memcpy(pack+5,this->value,this->valueLen);

  return pack;
}

void validationPacket(void *packet)
{
      char *pack = (char*)packet;
      header *head = new header;
      head = ((header*)packet);
      char *text = ((char*)packet+5);

      printf("Packet size: %d \n", head->len);
      printf("Packet code: %d \n", head->code);
      printf("Packet text: %s \n", text);
}

