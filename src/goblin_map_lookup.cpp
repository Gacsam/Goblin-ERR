#include "goblin_map_lookup.hpp"

bool goblin::map::IsFlagException(int paramId, int& mapFragment)
{
	if (ExceptionList.count(paramId)) {
		mapFragment = ExceptionList.at(paramId);
		return true;
	}
	return false;
}