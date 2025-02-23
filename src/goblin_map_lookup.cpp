#include "goblin_map_lookup.hpp"

bool goblin::mapPoint::HasException(int paramId, int& mapFragment)
{
	if (ExceptionList.count(paramId)) {
		mapFragment = ExceptionList.at(paramId);
		return true;
	}
	return false;
}

int goblin::mapPoint::GetMapFlagFromTile(goblin::mapPoint::MapTile location)
{
	// Iterating through MapList
	for (const auto& fragment : MapList) {
		// Iterating through chunks within each MapFragments
		for (auto& chunk : fragment.mapFragmentTile) {
			if (chunk == location)
			{
				return fragment.mapFragmentId;
			}
		}
	}
	return 0;
}