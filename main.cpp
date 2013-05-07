/* Completely dummy main file, only for testing */

#include <stdio.h>
#include "distributor.h"

int main(void)
{
	Distributor *D = new Distributor(200, "1003");
	delete D;
	return 0;
}