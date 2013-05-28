#include "GenPacket.h"


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
 