#pragma once
#include "from/params.hpp"

#include "from/paramdef/WORLD_MAP_POINT_PARAM_ST.hpp"
#include "from/paramdef/BONFIRE_WARP_PARAM_ST.hpp"

#include "goblin/goblin_map_exceptions.hpp"
#include "goblin/goblin_map_tiles.hpp"


namespace goblin::mapPoint {
	bool HasException(int paramId, int& mapFragment);
	int GetMapFlagFromTile(MapTile mapTile);
	/// <summary>
	/// TextId 0 are ignored
	/// </summary>
	/// <param name="row">A single row from WORLD_MAP_POINT_PARAM_ST</param>
	/// <param name="offset">At which textId to start</param>
	/// <returns>Whether row contains these TextIds</returns>
	bool ContainsTextId(from::paramdef::WORLD_MAP_POINT_PARAM_ST& row, int offset, int firstTextId, int secondTextId, int thirdTextId);
	// Same but for graces
	bool ContainsTextId(from::paramdef::BONFIRE_WARP_PARAM_ST& row, int offset, int firstTextId, int secondTextId, int thirdTextId);
};