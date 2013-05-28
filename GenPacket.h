#ifndef genpacket
#define genpacket
#include <iostream>
#include <ttproto.h>


//Funkcja tworzy przykladowy pakiet
void *createPacket(void *value, int len, int code);


void validationPacket(void *packet);


//klasa s³u¿¹ca do odczytania pakietu
class GenPacket
{
  private:
  header *head;
  char *value;
  unsigned int valueLen;

  void initializeDefaultValues();

  public:

  //Konstruktory
  GenPacket(); //Inicjalizacja dla pustego
  GenPacket(void *packet); //Inicjalizacja z odebranego pakietu z wypelnionymi polami

  ~GenPacket();

  //Zmiana zawartosci pakietu
  void setValue(void *value,int len);
  void setPacketCode(int code);

  //Zwracanie rozmiarow pakietu i jego skladowych
  unsigned int getPacketSize();
  unsigned int getValueSize();

  //Dostep do wartosci pakietu w okreslonym typie
  void *getValue();
  void *getPacket();
  char *getValueAsCString();


};


#endif
