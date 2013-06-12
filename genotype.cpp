#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <math.h>
#include "genotype.h"
#include <windows.h>
using namespace std;


Genotype::Genotype(const Data &data)
{
    numberOfGenes = data.numberOfLessons;
    numberOfRooms = data.numberOfRooms;
    numberOfTerms = data.numberOfTerms;
    genes = new Gene*[numberOfGenes];
    srand(time(NULL));
    for(unsigned int i=0;i<numberOfGenes;i++)
    {
        int terms = rand()%data.numberOfTerms;
        int rooms = rand()%data.numberOfRooms;
        genes[i] = new Gene(terms, rooms);
    }
}

Genotype::~Genotype()
{
    for(unsigned int i=0;i<this->numberOfGenes;i++)
    {
        delete genes[i];
    }
    delete genes;
}

void Genotype::Evaluation(const Data &d)
{
  //zalozenia przed ocena
  penalty = false;
  mark = 0;
  LARGE_INTEGER lpFrequency;
  LARGE_INTEGER lpPerformanceCountStart, lpPerformanceCountEnd;

  if (QueryPerformanceFrequency(&lpFrequency) != 0)
  {
    QueryPerformanceCounter(&lpPerformanceCountStart);
    for(int i = 0; i < 1000000; i++)
    {
      mark += termsCollision(); //kolizja jednej sali w danym terminie
      mark += collisionsInClass(d);
      mark += teachersEvaluation(d); //okienka i kolizje nauczycieli, mo¿liwe szybkie dopisanie preferencji godzinnych
      mark += eval(d);
    }
    QueryPerformanceCounter(&lpPerformanceCountEnd);
    double Frequency = lpFrequency.LowPart;
    double End = lpPerformanceCountEnd.LowPart;
    double Start = lpPerformanceCountStart.LowPart;
    cout << (End - Start) / Frequency << " s." << endl;
    /*QueryPerformanceCounter(&lpPerformanceCountStart);
    mark += termsCollision1(); //kolizja jednej sali w danym terminie
    QueryPerformanceCounter(&lpPerformanceCountEnd);
    Frequency = lpFrequency.LowPart;
    End = lpPerformanceCountEnd.LowPart;
    Start = lpPerformanceCountStart.LowPart;
    cout << (End - Start) / Frequency << " s." << endl; */
  }

}//funkcja oceniaj¹ca
/*double Genotype::termsCollision1()
{
  const double CollisionPenalty = 1;//wspolczynnik odpowiedzialny za kolizje sali w danym terminie
  double tmpPenalty= 0; //zmienna do zliczania kary z tej funkcji
  for( int i= 0; i< numberOfGenes; i++ )//sprawdzenia kazdej ts z kazda
    for( int j= i+1; j< numberOfGenes; j++ )
      if( genes[ i ]->term== genes[ j ]->term )
        if( genes[ i ]->room== genes[ j ]->room )
        {
          penalty= true;
          tmpPenalty--;
        }  //druga wersja algorytmu prawdopodobnie mniej optymalna
  return tmpPenalty;
} */

double Genotype::termsCollision()
{
  const double CollisionPenalty = 1;//wspolczynnik odpowiedzialny za kolizje sali w danym terminie
  double tmpPenalty= 0; //zmienna do zliczania kary z tej funkcji

  bool **tab = new bool*[numberOfRooms];
  for (int i=0;i<numberOfRooms;i++)
    tab[i] = new bool[numberOfTerms];
  //dynamiczna tablica dwuwymiarowa sala x termin, ktora bedzie przechowywac czy dana czy
  //dana terminosala jest juz zajeta czy tez nie , true dla zajetego terminu

  for( int i= 0; i< numberOfRooms; i++)
    for( int j= 0; j< numberOfTerms; j++)
      tab[i][j] = false;
  //przygotowanie tablicy, przyjecie, ¿e ka¿dy termin dla ka¿dej sali jest wolny


  for( int i= 0; i< numberOfGenes; i++ ) //przechodzimy przez wszystkie geny, czyli wszystkie wystepuj¹ce kombinacje terminow u sali
      if ( !tab[genes[ i ]->room][genes[ i ]->term] )//sprawdzany czy dana sala jest ju¿ zajeta w tym terminie
        tab[genes[ i ]->room][genes[ i ]->term] = true; //jesli nie zaznaczamy iz tak jest w tablicy booli
      else
      {
        tmpPenalty -= CollisionPenalty;
        if (!penalty)
          penalty = true;
        //jesli nie zliczamy kare oraz zaznaczamy iz taka sytuacja nie moze wystapic
      }

  /*for( int i= 0; i< numberOfGenes; i++ )//sprawdzenia kazdej ts z kazda
    for( int j= i+1; j< numberOfGenes; j++ )
      if( genes[ i ]->term== genes[ j ]->term )
        if( genes[ i ]->room== genes[ j ]->room )
        {
          penalty= true;
          tmpPenalty--;
        }  //druga wersja algorytmu prawdopodobnie mniej optymalna */


  for (int i=0;i<numberOfRooms;i++)
    delete[] tab[i];
  delete[] tab;
  //czystki etniczne pamieci

  return tmpPenalty;
  //funkcja zwraca nasza tymczasowo liczona kare

}//termsCollision()

bool Genotype::Mark(double &mark)
{
    mark = this->mark;
    return penalty;
}

double Genotype::evalSubject(const Data &d, Data::Node *p)
{
  double tmpPenalty= 0;
  short int *tab = new short int[numberOfTerms];
  for( int i= 0; i< numberOfTerms; i++ )
    tab[ i ]= 0;
  for( int i= 0; i< p->numberOfLessons; i++ )
  {
    tab[ genes[ p->lessons[ i ]]->term ]++;//wpisanie terminu przedmiotu
    if( i+ 1== p->numberOfLessons )//jezeli nie ma juz wiecej
      tmpPenalty+= evalSubject_( tab );
    else
      if( d.tab[ p->lessons[ i ]].subject!= d.tab[ p->lessons[ i+ 1 ]].subject )//jezeli kolejny jest inny
        tmpPenalty+= evalSubject_( tab );
  }
  delete[] tab;
  return tmpPenalty;
}

double Genotype::evalSubject_( short int *tab )
{
  double tmpPenalty= 0;
  const int noBlockCost= 1;
  const int numberOfDays= 5;
  int days[ numberOfDays ];
  for( int i= 0; i< numberOfDays; i++ )
    days[ i ]= 0;
  /*for( int i= 0; i< numberOfTerms; i++ )//wypisanie poszczegolnych terminow
    cout<< i<< ": "<< tab[ i ]<< endl;*/
  for( int i= 0; i< numberOfTerms; i++ )//liczenie ile godzin w dniu
    days[ i/ ( numberOfTerms/ numberOfDays )]+= tab[ i ];
  //ocena czy sa w bloku w danym dniu
  bool break_= false;
  int j= 0;
  for( int i= 0; i< numberOfTerms; i++ )
  {
    if( tab[ i ]> 0 )
    {
      break_= true;
      j+= tab[ i ];
    }
    else
      if( break_ )
      {
        if( j!= days[ i/ ( numberOfTerms/ numberOfDays )])//juz byly wszystkie lekcje
        {
          tmpPenalty-= noBlockCost;
          penalty= true;
          break_= false;
        }
        else
          break_= false;
      }
    if( i% ( numberOfTerms/ numberOfDays )== ( numberOfTerms/ numberOfDays )- 1 )// koniec dnia
    {
      j= 0;
      break_= false;
    }
  }
  //zblokowanie
  int ideal[]= { 0, 0, 0, 0, 0 };
  const double no_day_cost = 1.0;
	const double day_add_cost = 2.0;
	const double hour_add_cost = 2.5;
  int hours_total= 0;
  for( int i= 0; i< numberOfDays; i++ )
    hours_total+= days[ i ];
  bubble_sort( days, numberOfDays );
  ideal[ 2 ]= 0;
  if( hours_total<= 6 )//stworzenie idealnego
    for( int i= 0; i< hours_total; i++ )
      ideal[ i% 3 ]++;
  else
    if( hours_total<= 8 )
      for( int i= 0; i< hours_total; i++ )
        ideal[ i% 4 ]++;
    else
      for( int i= 0; i< hours_total; i++ )
        ideal[ i% 5 ]++;
  int k;
  k= ideal[ 0 ];//zamiana, zeby pozycje ideal i days odpowiadaly sobie
  ideal[ 0 ]= ideal[ 4 ];
  ideal[ 4 ]= k;
  k= ideal[ 1 ];
  ideal[ 1 ]= ideal[ 3 ];
  ideal[ 3 ]= k;
  for(int i = 0; i< numberOfDays; i++)
		tmpPenalty-= (((ideal[i] == 0 && days[i] != 0) ? day_add_cost : (pow(max<double>(days[i]-ideal[i], 0), 2)
      *hour_add_cost))*sqrt((ideal[i]-days[i] > 0) ? ((days[i] != 0) ? ideal[i]/days[i] : 1) : 1)
      +((ideal[i] != 0 && days[i] == 0) ? no_day_cost : 0)+((ideal[i] > days[i]) ? (ideal[i]+1)/(days[i]+1) : 0))/hours_total;//wzor na blokowanie
  //for( int i= 0; i< numberOfDays; i++ )//wypisanie ilosci godzin w dniu
    //cout<< ideal[ i ]<< " - "<< days[ i ]<< endl;
  //cout<< "Kara: "<< tmpPenalty<< endl;
  for( int i= 0; i< numberOfTerms; i++ )//czyszczenie tablicy
    tab[ i ]= 0;
  //system( "pause" );
  return tmpPenalty;
}

double Genotype::collisionsInClass(Data &d, Data::Node *p, Data::Node *q)
{
  const double collisionPenalty = 1;
	double tmpPenalty = 0;
	if(p == 0 && q == 0) //pierwsze wywolanie
	{
		for(int i = 0; i < d.k->numberOfSubgroups; i++) //sprawdzamy kolizje korzenia z kazda podgrupa
			tmpPenalty += collisionsInClass(d, d.k, d.k->subgroups[i]);
		cleanVectors(d.k);
		return tmpPenalty;
	}
	if(p->numberOfLessons == 0) //p = d.k, (korzen nie ma lekcji)
	{
		p->checked.push_back(q->id);
		p->checked.push_back(p->id);
	}
	else
	{
		bool betweenGroups = false, inGroupP = false, inGroupQ = false;
		for(int i = 0; i < p->checked.size(); i++) 
		{
			if(p->checked[i] == q->id) //czy kolizje miêdzy grupami p i q byly sprawdzane
				betweenGroups = true;
			if(p->checked[i] == p->id) //czy byly sprawdzane kolizje wewnetrzne w grupie p
				inGroupP = true;
		}
		for(int i = 0; i < q->checked.size(); i++)
			if(q->checked[i] == q->id) //czy byly sprawdzane kolizje wewnetrzne w grupie q
				inGroupQ = true;
		if(!betweenGroups)
		{
			bool *tab = new bool[d.numberOfTerms];
			for(int i = 0; i < d.numberOfTerms; i++)
				tab[i] = false;
			for(int i = 0; i < p->numberOfLessons; i++) 
				if(!tab[genes[p->lessons[i]]->term])
					tab[genes[p->lessons[i]]->term] = true;
				else if(!inGroupP) //kolizja w grupie p
        {
					tmpPenalty -= collisionPenalty;
          if(!penalty)
            penalty = true;
        }
			for(int i = 0; i < q->numberOfLessons; i++)
				if(tab[genes[q->lessons[i]]->term]) //kolizja miedzy p i q
				{
        	tmpPenalty -= collisionPenalty;
          if(!penalty)
            penalty = true;
        }
				else if(!inGroupQ) //kolizja w q
					tab[genes[q->lessons[i]]->term] = true;
			p->checked.push_back(q->id);
			p->checked.push_back(p->id);
			q->checked.push_back(q->id);
			delete[] tab;
		}
    if(!inGroupP)
    {
      tmpPenalty += evalSubject( d, p );
    }
    if(!inGroupQ)
    {
      tmpPenalty += evalSubject( d, q );
    }
		for(int i = 0; i < q->numberOfSubgroups; i++) //sprawdzamy kolizje p ze wszystkimi podgrupami q
			tmpPenalty += collisionsInClass(d, p, q->subgroups[i]);
	}
	for(int i = 0; i < q->numberOfSubgroups; i++) //sprawdzamy kolizje q ze wszystkimi podgrupami q
		tmpPenalty += collisionsInClass(d, q, q->subgroups[i]);
	return tmpPenalty;
}

void Genotype::cleanVectors(Data::Node *p)
{
	p->checked.clear();
	for(int i = 0; i < p->numberOfSubgroups; i++)
		cleanVectors(p->subgroups[i]);
}

double Genotype::evalStudent( short int *tTable )
{
  const int hoursLimit = 8;
  //for( int i= 0; i< numberOfTerms; i++ )
  //  cout<< i<< ": "<< tTable[ i ]<< endl;
  double tmpPenalty= 0;
  const int numberOfDays= 5;
  int days[ numberOfDays ];
  for( int i= 0; i< numberOfDays; i++ )
    days[ i ]= 0;
  for( int i= 0; i< numberOfTerms; i++ )//liczenie ile godzin w dniu
    days[ i/ ( numberOfTerms/ numberOfDays )]+= tTable[ i ];
  //kara za liczbe godzin
  for( int i= 0; i< numberOfDays; i++ )
    if(days[i] > hoursLimit)
    {
      tmpPenalty -= (days[i]-hoursLimit)*(1+days[i]-hoursLimit)/2;//magiczne liczby
      if(days[i] > hoursLimit+1)
        if(!penalty)
          penalty = true;
    }
  //wczesniejszy koniec
  const int prizeEnd= 1;
  for( int i= 0; i< numberOfDays; i++ )
    for( int j= numberOfTerms/ numberOfDays; j> 0; j-- )
      if( tTable[ i* numberOfTerms/ numberOfDays+ j- 1 ]== 0 )
        tmpPenalty+= prizeEnd;
      else
        break;
  //nierownomiernosc
  int hours= 0;
  for( int i= 0; i< numberOfDays; i++ )
    hours+= days[ i ];
  for( int i= 0; i< numberOfDays; i++ )
    tmpPenalty-= pow( days[ i ]- hours/ numberOfDays, 2 )/ 2;
  //odstep poczatke-koniec
  int end= 0, begin= 0;
  const int prizeBeginEnd= 1;
  for( int i= 0; i< numberOfDays- 1; i++ )
  {
    for( int j= numberOfTerms/ numberOfDays; j> 0; j-- )
      if( tTable[ i* numberOfTerms/ numberOfDays+ j- 1 ]== 0 )
        end++;
      else
        break;
    for( int j= 0; j< numberOfTerms; j++ )
      if( tTable[( i+ 1 )* ( numberOfTerms/ numberOfDays )+ j ]== 0 )
        begin++;
      else
        break;
    if( begin+ end> 5 )
      tmpPenalty+= prizeBeginEnd* 5;
    else
      tmpPenalty+= prizeBeginEnd* ( begin+ end );
    begin= end= 0;
  }
  //okienko
  const int breakCost= 1;
  bool break_= false;
  int j= 0;
  for( int i= 0; i< numberOfTerms; i++ )
  {
    if( tTable[ i ]> 0 )
    {
      break_= true;
      j+= tTable[ i ];
    }
    else
      if( break_ )
        if( j!= days[ i/ ( numberOfTerms/ numberOfDays )])//juz byly wszystkie lekcje
        {
          tmpPenalty-= breakCost;
          if(!penalty)
            penalty = true;
        }
    if( i% ( numberOfTerms/ numberOfDays )== ( numberOfTerms/ numberOfDays )- 1 )// koniec dnia
    {
      j= 0;
      break_= false;
    }
  }
  //for( int i= 0; i< numberOfDays; i++ )//wypisanie ilosci godzin w dniu
  //  cout<< days[ i ]<< endl;
  //cout<< "Kara: "<< tmpPenalty<< endl;
  //system("pause");
  return tmpPenalty;
}

double Genotype::eval(const Data &d, Data::Node *p, unsigned short *tab, int n)
{
	double tmpPenalty = 0;
	if(p == 0) //pierwsze wywolanie funkcji
	{
		unsigned short *plan = new unsigned short[d.numberOfTerms];
		for(int i = 0; i < d.k->numberOfSubgroups; i++) //przechodzimy po wszystkich klasach
			tmpPenalty += eval(d, d.k->subgroups[i], plan); //ustalamy plan dla kazdej grupy
    delete[] plan;
		return tmpPenalty;
	}
	else
	{
		for(int i = 0; i < p->numberOfLessons; i++) //dodajemy do tab wszystkie lekcje danej podgrupy
			tab[n + i] = p->lessons[i];
		n += p->numberOfLessons;
		if(p->numberOfSubgroups != 0)
		{
			for(int i = 0; i < p->numberOfSubgroups; i++) //przechodzimy po wszystkich podgrupach danej grupy
				tmpPenalty += eval(d, p->subgroups[i], tab, n);
			return tmpPenalty;
		}
		else
		{
			//tab zawiera indeksy lekcji, ktore ma ta grupa (lacznie z lekcjami wspolnym z innymi grupami)
			//n - ilosc wszystkich lekcji w tej grupie
      short int *tTable= new short int[ numberOfTerms ];
      for( int i= 0; i< numberOfTerms; i++ )
        tTable[ i ]= 0;

      for( int i= 0; i< n; i++ )
        tTable[ genes[ tab[ i ]]->term ]++;

      tmpPenalty += evalStudent( tTable );

      delete[] tTable;
      return tmpPenalty;
		}
	}
}

double Genotype::teachersEvaluation(const Data &d)
{
  const int numberOfDays = 5; //piec dni tygodnia, mozna przyszlosciowo ustawic w interfejsie
  const double breaks = 1; //wspolczynnik kary za okno
  const double collision = 2; //wspolczynnik kary za kolizje

  double tmpPenalty= 0;//zmienna do zliczania kary z tej funkcji

  bool **tab = new bool*[d.numberOfTeachers];
  for (int i=0;i<d.numberOfTeachers;i++)
    tab[i] = new bool[numberOfTerms];
  //tworzenie dynamicznej ablicy dwuwymiarowej nauczycel x termin, przechowywujacej
  //informacje o zajetosci danego nauczyciela w danym terminie, true dla zajetego terminu

  for (int i=0;i<d.numberOfTeachers;i++)
    for (int j=0;j<numberOfTerms;j++)
      tab[i][j]=false;
  //przygotowanie tablicy, wstepne zlozenie ze wszystkie terminy sa wolne

  /********************Kolizja Nauczyciela**********************************/
  for( int i= 0; i< numberOfGenes; i++ )
  {
    if( tab[d.tab[i].teacher][genes[ i ]->term] ) //sprawdzamy czy nauczyciel jest juz zajety w tym terminie
    {
      tmpPenalty -= collision;
      if (!penalty)
        penalty= true;
      //jesli tak dodlicz do kary i zaznacz fakt iz taki plan nie moze istniec
    }
    else
      tab[d.tab[i].teacher][genes[ i ]->term]=true;
    //jesli nie, zaktualizuj tablice stwierdzajac iz juz jest zajety
  }

  /*************Okienka + rozwojowo preferencje nauczycieli*****************/
  int firstTerm, lastTerm, thisDayTerms;
  //pierwszy i ostatni termin oraz liczba wszystkich zajêtych terminów w tym¿e dniu
  for (int i=0;i<d.numberOfTeachers;i++) //dla ka¿dego nauczyciela
    for (int j=0;j<numberOfDays;j++)//w ka¿dym dniu tygodnia
    {
      firstTerm = lastTerm = -1;
      thisDayTerms = 0;
      //wstêpne zalozenie - sytuacja w ktorej nauczyciel ma wolny dzien

      for (int k=0;k<numberOfTerms/numberOfDays;k++)//przejscie przez kolejne terminy w dniu
      {
        if(tab[i][j*(numberOfTerms/numberOfDays)+k])//jesli w tym terminie odbywaja sie zajecia
        {
          lastTerm = k; //zakladamy ze jest to ostatnia lekcja
          thisDayTerms++; //doliczamy ta lekcje do licznika
          if(firstTerm == -1)
            firstTerm = k;
          //jesli do tej pory nie znalazlismy zadnej lekcji, wiemy ze wlasnie natrafilismy na pierwsza lekcje

          // dzieki tym danym mozna bardzo latwo sprawdzac preferencje nauczycieli, nalezalo by to jednak rowniez zaimplementowac
          // w interfejsie wejsciowym  - do przedyskutowania
        }
      }
      if (thisDayTerms>1)//jesli nie ma nawet 2 lekcji nie moze byc okienek
       tmpPenalty -= breaks * (lastTerm - thisDayTerms - firstTerm + 1);
       //dodanie kary jednakze taki plan moze istniec ( w nawiasie wzor na ilosc okienek)

       //SUGESTIA do przemyslenia
       //wydaje mi sie ze kara ta nie powinna rosnac liniowo, gdyz przeciez 6 lekcyjne okienko jest tragiczne
       //proponuje liczyc je jako  (1.9^ilosc okienek)/2
       //kolejne kary bylyby nastepujeace (od 1 do 7)
       // 0,95; 1,805; 3,43; 6,51; 12,38; 23,52; 44,69
    }

  for (int i=0;i<d.numberOfTeachers;i++)
    delete [] tab[i];
  delete [] tab;
  //zwolnienie pamieci

  return tmpPenalty;
  // zworot wartosci kary
}
