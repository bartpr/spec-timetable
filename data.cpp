#include "data.h"
unsigned short Data::knot::knots = 0;

Data::Data(unsigned char numberOfLessons)
{
    tab = new Lesson[numberOfLessons];
}

void Data::Make_Forest( short *Dolans_t, knot *k ){
	k->id= ci;
	ci++;
	k->knots+= Dolans_t[ cl ];
	if( Dolans_t[cl+1] != 0 ){//istnieja nizsze poziomy
		for( int i=0; i <Dolans_t[cl]; i++ ){
			k->subgroups[ i ]= new knot;
		}
		cl++;
		for( int i=0; i <Dolans_t[cl]; i++ ){
			Make_Forest( Dolans_t, k->subgroups[ i ] );
		}
	}else{
		for( int i=0; i <Dolans_t[cl]; i++ ){
			k->subgroups[ i ]= NULL;
		}
	}
}