#include "data.h"

//id i poziomy liczone s¹ od 1
//pozniej wejda jako static
short cl= 1;//Current_level poziom drzewa na ktorym jestesmy
short ci= 1;//current_id obecne id
unsigned short knot::knots = 0;

short Dolans_t[3]={ 2, 3, 4 };

Data::Data(unsigned char numberOfLessons)
{
    tab = new Lesson[numberOfLessons];
}

void Data::Make_Forest( short *D_t ){
	this->k= new knot;
	int m=0;
	while( D_t != '\0' ){
		m++;
	}
	for( int i= 0; i< m; i++ ){
	
	}
	
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