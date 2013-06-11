#include "Group.h"

Group::Group(Classs* classs) {
	this->classs = classs;
}
bool Group::operator==(Group* g) {
	return classs == g->classs && g->id == id;
}