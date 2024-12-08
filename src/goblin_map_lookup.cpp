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

bool goblin::mapPoint::ContainsTextId(from::paramdef::WORLD_MAP_POINT_PARAM_ST& row, int offset, int firstTextId, int secondTextId, int thirdTextId)
{
	if (offset == 1) {
		if (secondTextId == 0 || secondTextId == -1)
		{
			return row.textId2 == firstTextId && row.textId4 == thirdTextId;
		}

		return row.textId2 == firstTextId && row.textId3 == secondTextId && row.textId4 == thirdTextId;
	}
	else if (offset == 2) {

		if (secondTextId == 0 || secondTextId == -1) {
			return row.textId3 == firstTextId && row.textId5 == thirdTextId;
		}
		return row.textId3 == firstTextId && row.textId4 == secondTextId && row.textId5 == thirdTextId;
	}
	return false;
}

bool goblin::mapPoint::ContainsTextId(from::paramdef::BONFIRE_WARP_PARAM_ST& row, int offset, int firstTextId, int secondTextId, int thirdTextId)
{
	if (offset == 1) {
		if (secondTextId == 0 || secondTextId == -1)
		{
			return row.textId2 == firstTextId && row.textId4 == thirdTextId;
		}

		return row.textId2 == firstTextId && row.textId3 == secondTextId && row.textId4 == thirdTextId;
	}
	else if (offset == 2) {

		if (secondTextId == 0 || secondTextId == -1) {
			return row.textId3 == firstTextId && row.textId5 == thirdTextId;
		}
		return row.textId3 == firstTextId && row.textId4 == secondTextId && row.textId5 == thirdTextId;
	}
	return false;
}