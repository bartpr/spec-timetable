#ifndef CLASSS_H
#define CLASSS_H

#include <vector>

#include "Group.h"

class Classs {
	public:
		AnsiString id;
		vector<Group*> groups;
		
		bool operator==(Classs* c);
};

#endif