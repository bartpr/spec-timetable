#ifndef SUBGROUP_H
#define SUBGROUP_H

#include <vector>

#include "Group.h"

class Subgroup {
	public:
		Group* group;
		AnsiString id;
		//vector<Group*> groups;
		
		Subgroup(Group* group);
		bool operator==(Subgroup* sg);
};

#endif