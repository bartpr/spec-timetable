#ifndef CLASSROOM_H
#define CLASSROOM_H

class Classroom {
	public:
		AnsiString id;
		
		bool operator==(Classroom* c);
};

#endif