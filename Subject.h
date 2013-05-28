#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

#include "Classroom.h"

class Subject {
	public:
		AnsiString name;
		vector<Classroom*> filters;
};

#endif