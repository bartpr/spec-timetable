#ifndef GROUP_H
#define GROUP_H

#include <vector>

class Classs;
#include "Subgroup.h"

class Group {
	public:
		Classs* classs;
		AnsiString id;
		vector<Subgroup*> subgroups;
		
		Group(Classs* classs);
		bool operator==(Group* g);
};

#endif