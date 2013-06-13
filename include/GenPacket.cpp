#include "GenPacket.h"


GenPacket::GenPacket()
{
  initializeDefaultValues();
}

GenPacket::~GenPacket()
{
	if(value != NULL) delete value;

	
	
}

//Wyzerowanie wszystkich wartosci na starcie
void GenPacket::initializeDefaultValues()
{

  value = NULL;
  valueLen = 0;

  head.len = 0;
  head.code = 0;
  
}

//wczytanie istniejacego pakietu
GenPacket::GenPacket(void *packet)
{
  //Inicjalizacja domyslnych wartosci
  initializeDefaultValues();

  //Pobranie pakietu [5b]

  memcpy(&head,packet,sizeof(header));
  

  //Pobranie wartosci

  if(head.len > 5)
  {
    this->valueLen = head.len - 5;
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

  if(value == NULL) return 5;
  else
  {
   return 5 + this->valueLen;
  }
}


//zwraca wartosc pakietu
char *GenPacket::getValue()
{
	if(valueLen == 0) return NULL;
	else
	{
   		char *b = new char[valueLen + 1];
   		memset(b,'\0',valueLen + 1);
   		memcpy(b,value,valueLen);
   		return b;
	}
	
   
}

unsigned int GenPacket::getValueSize()
{
   return this->valueLen;
}




void GenPacket::setValue(void *value, uint32_t n)
{
	//Usuniecie starej wartości
	if(this->value != NULL)
	{
		delete this->value;
		this->value = NULL;
		this->valueLen = 0;
	}
	
	this->value = new char[n];
	memset(this->value,'\0', n);
	
	memcpy(this->value, value,n);
	
	this->valueLen = n;
	
	head.len = n + sizeof(head);
	
	
	
}

char * GenPacket::getPacket(uint32_t *s)
  {
	if(valueLen == 0)
	{
		return NULL;
	}
	else
	{
		//Inicjalizacja bufora dla wyjscia
		uint32_t buforLen = sizeof(header) + valueLen + 1;	
		char *bufor = new char[buforLen];
		memset(bufor,'\0',buforLen);
		
		//Skopiowanie naglowka i wartosci kolejno do bufora
		memcpy(bufor,&head,sizeof(header));
		memcpy(bufor+sizeof(header),this->value, valueLen);
		
		if(s != NULL)
		{
			*s = buforLen;
		}
		
		return bufor;
		
		
	}
			
  }




//Przygotowywuje pakiet gotowy do wysĹ‚ania
void *preparePacket(void *value, uint32_t len, uint8_t code, unsigned int *sPacket)
{
        if(len == 0) return NULL;


        //Rozmiar nagĹ‚Ăłwka
        uint8_t hSize = sizeof(header);

        //Stworzenie pakietu
        header *h = new header;
        h->len = len + hSize;
        h->code = code;

        //Wygenerowanie bufora
        uint32_t bSize = hSize + len + 1;
        char *bufor = new char[bSize];
        memset(bufor,'\0',bSize);

        //Skopiowanie nagĹ‚Ăłwka do bufora
        memcpy(bufor,h,hSize);
        delete h;

        //Skopiowanie wartosci do bufora
        memcpy(bufor+hSize,value,len);

        //Zwrocenie wartosci pakietu
        if(sPacket != NULL)
        {
         *sPacket = bSize;
        }

        return bufor;

}


uint32_t getPacketLength(void *packet)
{
		
		 header *h = (header*)packet;
		 return h->len;


}

 