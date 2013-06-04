#include "data.h"

unsigned short knot::knots = 0;

short Dolans_t[3]={ 2, 3, 4 };//tablica z iloscia rozgalezien na kazdym poziomie
const short nr= 3;

Data::Data(unsigned char numberOfLessons)
{
    tab = new Lesson[numberOfLessons];
}

void Data::tostruct( ){
	knot* tab[20];//zakladam ze nie bedzie 20 podgrup
	short cl=0;
	for( int i=0; i< nr; i++ ){//nr global narazie
		tab[i]= new knot;
		for( int j=0; j< Dolans_t[i]; j++ ){//tablica global !!!!!!
			tab[i].subgroups[j]= new knot;	
		}
	}
	//jest tablica
	this->knot = tab[0];//element 0 jest korzeniem
	for( int i=1; i< nr; i++ ){
		for( int j=0; j< Dolans_t[i]; j++ ){
			if( i+1 == nr ){//najnizszy poziom
				MF( tab[i].subgroups[j], tab[20], -1 );
			}else{
				MF( tab[i].subgroups[j], tab[20], i )
			}
		}
	}
}

void Data::MF( knot *k, knot* tab[20], int cl){
	if( cl == -1 ){//najnizszy poziom
		k= NULL;
	}else{
		k= tab[cl];
	}
	//SPRAWDZIC POWIAZANIA
}

/*void Data::Make_Forest( short *Dolans_t ){
    this->k= new knot;
	k->id= ci;
	ci++;
	k->knots+= Dolans_t[ cl ];
	if( Dolans_t[cl+1] != 0 ){//istnieja nizsze poziomy
		for( int i=0; i <Dolans_t[cl]; i++ ){
			k->subgroups[ i ]= new knot;
		}
		cl++;
		for( int i=0; i <Dolans_t[cl]; i++ ){
			Make_Forest_p( Dolans_t, k->subgroups[ i ] );
		}
	}else{
		for( int i=0; i <Dolans_t[cl]; i++ ){
			k->subgroups[ i ]= NULL;
		}
	}
}

void Data::Make_Forest_p( short *Dolans_t, knot *k ){
    k= new knot;
	k->id= ci;
	ci++;
	k->knots+= Dolans_t[ cl ];
	if( Dolans_t[cl+1] != 0 ){//istnieja nizsze poziomy
		for( int i=0; i <Dolans_t[cl]; i++ ){
			k->subgroups[ i ]= new knot;
		}
		cl++;
		for( int i=0; i <Dolans_t[cl]; i++ ){
			Make_Forest_p( Dolans_t, k->subgroups[ i ] );
		}
	}else{
		for( int i=0; i <Dolans_t[cl]; i++ ){
			k->subgroups[ i ]= NULL;
		}
	}
}*/