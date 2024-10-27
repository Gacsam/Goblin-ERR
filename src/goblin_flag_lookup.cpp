#include "goblin_flag_lookup.hpp"

int goblin::map::GetMapFlag(goblin::map::MapChunk location)
{
	// Iterating through MapList
	for (const auto& fragment : MapList) {
		// Iterating through chunks within each MapFragments
		for (auto& chunk : fragment.mapFragmentChunks) {
			if (chunk == location)
			{
				return fragment.mapFragmentId;
			}
		}
	}
	return 0;
}

bool goblin::param::ContainsTextId(from::paramdef::WORLD_MAP_POINT_PARAM_ST& row, int offset, int firstTextId, int secondTextId, int thirdTextId)
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

bool goblin::param::ContainsTextId(from::paramdef::BONFIRE_WARP_PARAM_ST& row, int offset, int firstTextId, int secondTextId, int thirdTextId)
{
	if (offset == 0) {
		if (firstTextId == 0) {
			return row.textId2 == secondTextId && row.textId3 == thirdTextId;
		}
		else if (secondTextId == 0) {
			return row.textId1 == firstTextId && row.textId3 == thirdTextId;
		}
		else if (thirdTextId == 0) {
			return row.textId1 == secondTextId && row.textId2 == thirdTextId;
		}
		return row.textId1 == firstTextId && row.textId2 == secondTextId && row.textId3 == thirdTextId;
	}
	else if (offset == 1) {
		if (firstTextId == 0) {
			return row.textId3 == secondTextId && row.textId4 == thirdTextId;
		}
		else if (secondTextId == 0) {
			return row.textId2 == firstTextId && row.textId4 == thirdTextId;
		}
		else if (thirdTextId == 0) {
			return row.textId2 == secondTextId && row.textId3 == thirdTextId;
		}
		return row.textId2 == firstTextId && row.textId3 == secondTextId && row.textId4 == thirdTextId;
	}
	else if (offset == 2) {
		if (firstTextId == 0) {
			return row.textId4 == secondTextId && row.textId5 == thirdTextId;
		}
		else if (secondTextId == 0) {
			return row.textId3 == firstTextId && row.textId5 == thirdTextId;
		}
		else if (thirdTextId == 0) {
			return row.textId3 == firstTextId && row.textId4 == secondTextId;
		}
		return row.textId3 == firstTextId && row.textId4 == secondTextId && row.textId5 == thirdTextId;
	}
	return false;
}
