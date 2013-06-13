#ifndef genpacket
#define genpacket

#include <ttproto.h>
#include <iostream>

class GenPacket
{
  private:
  header head;
  char *value;
  unsigned int valueLen;

  void initializeDefaultValues();

  public:
		
  //Konstruktorzy
  GenPacket();
  GenPacket(void *packet);
  
  //Destruktor
  ~GenPacket();

  //Size
  unsigned int getPacketSize();
  unsigned int getValueSize();
  //Value - get
  char *getValue();
  
  //Value - set
  void setValue(void *value, uint32_t n);
  
  //Packet - get
  char *getPacket(uint32_t *s = NULL);


};


//Przygotowywuje pakiet gotowy do wys³ania
void *preparePacket(void *value, uint32_t len, uint8_t code, unsigned int *sPacket = NULL);

uint32_t getPacketLength(void *packet);


#endif
