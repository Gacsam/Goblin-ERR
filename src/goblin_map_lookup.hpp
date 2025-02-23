#pragma once
#include "from/params.hpp"

#include "from/paramdef/WORLD_MAP_POINT_PARAM_ST.hpp"
#include "from/paramdef/BONFIRE_WARP_PARAM_ST.hpp"

#include "goblin/goblin_map_exceptions.hpp"
#include "goblin/goblin_map_tiles.hpp"


namespace goblin::mapPoint {
	bool HasException(int paramId, int& mapFragment);
	int GetMapFlagFromTile(MapTile mapTile);
};