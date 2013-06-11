#include "Teacher.h"

bool Teacher::operator==(Teacher* t) {
	return t->name == name;
}