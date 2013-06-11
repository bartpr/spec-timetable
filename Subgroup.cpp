#include "Subgroup.h"

Subgroup::Subgroup(Group* group) {
	this->group = group;
}
bool Subgroup::operator==(Subgroup* sg) {
	return group == sg->group && sg->id == id;
}