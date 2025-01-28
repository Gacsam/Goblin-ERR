#pragma once

#include <filesystem>
#include <mini/ini.h>

namespace goblin
{
	/**
	 * Load user preferences from an .ini file
	 */
	void load_line(mINI::INIMap<std::string> config, std::string lineInIni, bool &lineVariable);
	void load_line(mINI::INIMap<std::string> config, std::string lineInIni, long long& floatVariable);
	void load_config(const std::filesystem::path& ini_path);

	namespace config
	{
		extern bool disableGoblin;
		extern long long loadDelay;
		extern bool requireMapFragments;

		extern bool showBossIcons;
		extern bool showOverworldIcons;
		extern bool showCampIcons;
		extern bool showMerchants;

		extern bool hideBossesOnCompletion;
		extern bool hideOverworldOnCompletion;
		extern bool hideCampsOnCompletion;

		extern bool showReforgedIncantations;
		extern bool showReforgedSorceries;
		extern bool showReforgedArmaments;
		extern bool showReforgedSpiritAshes;
		extern bool showReforgedAshesOfWar;
		extern bool showReforgedCrystalTears;
		extern bool showReforgedTalismans;
		extern bool showReforgedFortunes;
		extern bool showReforgedApparel;
		extern bool showReforgedChanges;
		extern bool showReforgedGraces;
		extern bool showReforgedArcheryChallenges;


		extern bool showGoblinGraces;
		extern bool showGoblinSpiritSprings;
		extern bool showGoblinSummoningPools;
		extern bool showGoblinUniqueDrops;
		extern bool showGoblinHostileNPC;
		extern bool showGoblinImpStatues;
		extern bool showGoblinTeardropScarabs;
		extern bool showGoblinNonRespawningMaterials;
		extern bool showGoblinKeyAndUnique;
		extern bool showGoblinPrayerbooks;
		extern bool showGoblinCookbooks;
		extern bool showGoblinMemoryStones;
		extern bool showGoblinCrystalTears;
		extern bool showGoblinPotsAndPerfumes;
		extern bool showGoblinLostAshesOfWar;
		extern bool showGoblinLarvalTears;
		extern bool showGoblinCelestialDew;
		extern bool showGoblinStoneswordKeys;
		extern bool showGoblinPaintings;
		extern bool showGoblinPlayerUpgrades;
		extern bool showGoblinSmithingStones;
		extern bool showGoblinGloveworts;
		extern bool showGoblinArmaments;
		extern bool showGoblinApparel;
		extern bool showGoblinTalismans;
		extern bool showGoblinSpiritAsh;
		extern bool showGoblinAshesOfWar;
		extern bool showGoblinSorceries;
		extern bool showGoblinIncantations;
		extern bool showGoblinConsumables;
		extern bool showGoblinCraftingMaterials;
		extern bool showGoblinMultiplayerItems;


		extern bool redifyBossIcons;
	};
};