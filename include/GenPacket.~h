#ifndef genpacket
#define genpacket


//klasa s³u¿¹ca do odczytania pakietu
class GenPacket
{
  private:
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


#endif
