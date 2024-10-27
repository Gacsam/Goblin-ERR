#pragma once
#include "goblin_config.hpp"
#include "goblin_map_lookup.hpp"

namespace goblin
{
	namespace icons
	{
		static constexpr int dungeonIcons = 100000;
		static constexpr int dungeonIconsCutoff = 500000;
		static constexpr int bossIcons = 30000000;
		static constexpr int campIcons = 50000000;
		static constexpr int overworldLocations = 60000000;
		static constexpr int overworldCutoff = 90000000;
	}
	namespace map {
		void Initialise();
		namespace errNative {
			void SetupReforgedIcon(int rowId, from::paramdef::WORLD_MAP_POINT_PARAM_ST& row, bool isOverworld);
			void HideOnCompletion(auto& bossNameFlag, auto& defeatedFlag, auto& defeatText);
		}
	}
};