#ifndef TEACHER_H
#define TEACHER_H

#include <vector>

#include "Subject.h"

class Teacher {
	public:
		AnsiString name;
		vector<Subject*> teaches;
		
		bool operator==(Teacher* c);
};

#endif