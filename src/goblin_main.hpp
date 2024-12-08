#pragma once
#include "goblin_config.hpp"
#include "goblin_map_lookup.hpp"

namespace goblin
{
	namespace icons
	{
		namespace base {
			static constexpr ParamRange dungeonIcons(100000, 500000);
		};
		namespace baseGoblin {
			namespace baseGame {
				static constexpr ParamRange graces(1, 350);
				static constexpr ParamRange spiritSprings(350, 400);
				static constexpr ParamRange summoningPools(400, 800);
				static constexpr ParamRange uniqueDrops(800, 1200);
				static constexpr ParamRange hostileNPC(1200, 1400);
				static constexpr ParamRange impStatues(1400, 1500);
				static constexpr ParamRange teardropScarabs(1500, 2000);
				static constexpr ParamRange nonRespawningMaterials(2000, 4100);
				static constexpr ParamRange keyAndUnique(4100, 4700);
				static constexpr ParamRange prayerbooks(4700, 4800);
				static constexpr ParamRange cookbooks(4800, 5700);
				static constexpr ParamRange memoryStones(5700, 5800);
				static constexpr ParamRange crystalTears(5800, 5900);
				static constexpr ParamRange potsAndPerfumes(5900, 6200);
				static constexpr ParamRange lostAshesOfWar(6200, 6300);
				static constexpr ParamRange larvalTears(6300, 6400);
				static constexpr ParamRange celestialDew(6400, 6500);
				static constexpr ParamRange stoneswordKeys(6500, 6700);
				static constexpr ParamRange paintings(6700, 6900);
				static constexpr ParamRange keyAndUnique2(6900, 7200);
				static constexpr ParamRange characterUpgradeItems(7200, 12200);
				static constexpr ParamRange armaments(12200, 13200);
				static constexpr ParamRange apparel(13200, 14200);
				static constexpr ParamRange talismans(14200, 15200);
				static constexpr ParamRange spiritAsh(15200, 16200);
				static constexpr ParamRange ashesOfWar(16200, 17200);
				static constexpr ParamRange sorceries(17200, 18200);
				static constexpr ParamRange incantations(18200, 19200);
				static constexpr ParamRange consumables(19200, 25400);
				static constexpr ParamRange craftingMaterials(25400, 26400);
				static constexpr ParamRange multiplayerItems(26400, 27700);
			};
			namespace DLC {
				static constexpr ParamRange graces(50000, 50500);
				static constexpr ParamRange spiritSprings(50500, 50700);
				static constexpr ParamRange summoningPools(50700, 52000);
				static constexpr ParamRange uniqueDrops(52000, 53000);
				static constexpr ParamRange hostileNPC(53000, 54000);
				static constexpr ParamRange impStatues(54000, 55000);
				static constexpr ParamRange teardropScarabs(55000, 55100);
				static constexpr ParamRange nonRespawningMaterials(55100, 56100);
				static constexpr ParamRange keyAndUnique(56100, 56300);
				static constexpr ParamRange cookbooks(56300, 56400);
				static constexpr ParamRange potsAndPerfumes(56400, 56500);
				static constexpr ParamRange lostAshesOfWar(56500, 56600);
				static constexpr ParamRange larvalTears(56600, 56700);
				static constexpr ParamRange paintings(56700, 56800);
				static constexpr ParamRange keyAndUnique2(56800, 60000);
				static constexpr ParamRange characterUpgradeItems(60000, 60200);
				static constexpr ParamRange smithingStones(60200, 63000);
				static constexpr ParamRange gloveworts(63000, 65000);
				static constexpr ParamRange armaments(65000, 66000);
				static constexpr ParamRange apparel(66000, 67000);
				static constexpr ParamRange talismans(67000, 68000);
				static constexpr ParamRange spiritAsh(68000, 69000);
				static constexpr ParamRange ashesOfWar(69000, 70000);
				static constexpr ParamRange sorceries(70000, 71000);
				static constexpr ParamRange incantations(71000, 72000);
				static constexpr ParamRange consumables(72000, 78500);
				static constexpr ParamRange consumables2(79000, 80000);
				static constexpr ParamRange craftingMaterials(80000, 85000);
				static constexpr ParamRange multiplayerItems(85000, 90000);

			};
		};

		namespace reforged {
			static constexpr ParamRange incantations(1000000, 1000100);
			static constexpr ParamRange sorceries(1000100, 1000200);
			static constexpr ParamRange armaments(1000200, 1000300);
			static constexpr ParamRange spiritAshes(1000300, 1000400);
			static constexpr ParamRange ashesOfWar(1000400, 1000500);
			static constexpr ParamRange crystalTears(1000500, 1000600);
			static constexpr ParamRange talismans(1000600, 1000700);
			static constexpr ParamRange fortunes(1000700, 1000800);
			static constexpr ParamRange apparel(1000800, 1000900);
			static constexpr ParamRange changes(1000900, 1002300);
			static constexpr ParamRange graces(1002300, 1002400);
			static constexpr ParamRange archeryChallenges(1002400, 1100000);

			static constexpr ParamRange bossIcons(30000000, 40000000);
			static constexpr ParamRange campIcons(50000000, 60000000);
		};

		namespace base {
			static constexpr ParamRange overworldLocations(60000000, 80000000);
			static constexpr ParamRange gameNPCs(80000000, 90000000);
		};
	};	

	namespace mapPoint {
		void Initialise();
		namespace errNative {
			static void SetupMerchantIcon(int rowId, from::paramdef::WORLD_MAP_POINT_PARAM_ST& row);
			static void SetupReforgedIcon(int rowId, from::paramdef::WORLD_MAP_POINT_PARAM_ST& row);
			static void HideOnCompletion(from::paramdef::WORLD_MAP_POINT_PARAM_ST& row);
			static void HideOnCompletion(from::paramdef::BONFIRE_WARP_PARAM_ST& row);
		};
		static int GetMapFragment(int rowId, from::paramdef::WORLD_MAP_POINT_PARAM_ST& row);
	};
};