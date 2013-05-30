#include "Subject.h"

Subject::Subject() {
	filterMode = true;
}

bool Subject::operator==(Subject* s) {
	return s->name == name;
}