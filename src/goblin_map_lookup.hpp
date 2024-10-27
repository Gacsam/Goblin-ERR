#pragma once
#include "goblin_flag_lookup.hpp"
namespace goblin::map {
	bool IsFlagException(int paramId, int& mapFragment);
}

using namespace goblin::flag;
static std::unordered_map<int, int> ExceptionList = {
	{31443400, WestLimgrave}, // Bridge of Sacrifice - Tree Sentinel
	{35505701, Snowfields}, // Snowfield - Putrid Avatar
	{35505600, Snowfields}, // Snowfield - Great Wyrm Theodorix
	{30120100, LakeOfRot}, // Lake of Rot - Baleful Shadow
	{30120101, LakeOfRot}, // Lake of Rot - Dragonkin
	{30120103, LakeOfRot}, // Lake of Rot - Tree Spirit
};