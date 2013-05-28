#include "Classroom.h"

bool Classroom::operator==(Classroom* c) {
	return c->id == id;
}