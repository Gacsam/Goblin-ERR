#include "goblin_config.hpp"
#include <spdlog/spdlog.h>

bool goblin::config::disableGoblin = false;
long long goblin::config::loadDelay = 10;
bool goblin::config::requireMapFragments = true;

bool goblin::config::showBossIcons = false;
bool goblin::config::showCampIcons = true;
bool goblin::config::showOverworldIcons = true;
bool goblin::config::showMerchants = true;

bool goblin::config::hideBossesOnCompletion = false;
bool goblin::config::hideCampsOnCompletion = false;
bool goblin::config::hideOverworldOnCompletion = false;

bool goblin::config::showReforgedIncantations = true;
bool goblin::config::showReforgedSorceries = true;
bool goblin::config::showReforgedArmaments = true;
bool goblin::config::showReforgedSpiritAshes = true;
bool goblin::config::showReforgedAshesOfWar = true;
bool goblin::config::showReforgedCrystalTears = true;
bool goblin::config::showReforgedTalismans = true;
bool goblin::config::showReforgedFortunes = true;
bool goblin::config::showReforgedApparel = true;
bool goblin::config::showReforgedChanges = true;
bool goblin::config::showReforgedGraces = true;
bool goblin::config::showReforgedArcheryChallenges = true;

bool goblin::config::showGoblinGraces = true;
bool goblin::config::showGoblinSpiritSprings = true;
bool goblin::config::showGoblinSummoningPools = true;
bool goblin::config::showGoblinUniqueDrops = true;
bool goblin::config::showGoblinHostileNPC = true;
bool goblin::config::showGoblinImpStatues = true;
bool goblin::config::showGoblinTeardropScarabs = true;
bool goblin::config::showGoblinNonRespawningMaterials = true;
bool goblin::config::showGoblinKeyAndUnique = true;
bool goblin::config::showGoblinPrayerbooks = true;
bool goblin::config::showGoblinCookbooks = true;
bool goblin::config::showGoblinMemoryStones = true;
bool goblin::config::showGoblinCrystalTears = true;
bool goblin::config::showGoblinPotsAndPerfumes = true;
bool goblin::config::showGoblinLostAshesOfWar = true;
bool goblin::config::showGoblinLarvalTears = true;
bool goblin::config::showGoblinCelestialDew = true;
bool goblin::config::showGoblinStoneswordKeys = true;
bool goblin::config::showGoblinPaintings = true;
bool goblin::config::showGoblinPlayerUpgrades = true;
bool goblin::config::showGoblinSmithingStones = true;
bool goblin::config::showGoblinGloveworts = true;
bool goblin::config::showGoblinArmaments = true;
bool goblin::config::showGoblinApparel = true;
bool goblin::config::showGoblinTalismans = true;
bool goblin::config::showGoblinSpiritAsh = true;
bool goblin::config::showGoblinAshesOfWar = true;
bool goblin::config::showGoblinSorceries = true;
bool goblin::config::showGoblinIncantations = true;
bool goblin::config::showGoblinConsumables = true;
bool goblin::config::showGoblinCraftingMaterials = true;
bool goblin::config::showGoblinMultiplayerItems = true;

bool goblin::config::redifyBossIcons = false;

void goblin::load_config(const std::filesystem::path& ini_path)
{
    spdlog::info("Loading config from {}", ini_path.string());

    mINI::INIFile file(ini_path.string());
    mINI::INIStructure ini;
    if (file.read(ini) && ini.has("Goblin"))
    {
        auto& config = ini["Goblin"];

        load_line(config, "disable_goblin", config::disableGoblin);
        load_line(config, "load_delay", config::loadDelay);
        load_line(config, "require_map_fragments", config::requireMapFragments);

        load_line(config, "show_boss_icons", config::showBossIcons);
        load_line(config, "show_camp_icons", config::showCampIcons);
        load_line(config, "show_overworld_icons", config::showOverworldIcons);

        load_line(config, "hide_bosses_on_completion", config::hideBossesOnCompletion);
        load_line(config, "hide_camps_on_completion", config::hideCampsOnCompletion);

        load_line(config, "show_reforged_incantations", config::showReforgedIncantations);
        load_line(config, "show_reforged_sorceries", config::showReforgedSorceries);
        load_line(config, "show_reforged_armaments", config::showReforgedArmaments);
        load_line(config, "show_reforged_spirit_ashes", config::showReforgedSpiritAshes);
        load_line(config, "show_reforged_ashes_of_war", config::showReforgedAshesOfWar);
        load_line(config, "show_reforged_crystal_tears", config::showReforgedCrystalTears);
        load_line(config, "show_reforged_talismans", config::showReforgedTalismans);
        load_line(config, "show_reforged_fortunes", config::showReforgedFortunes);
        load_line(config, "show_reforged_apparel", config::showReforgedApparel);
        load_line(config, "show_reforged_changes", config::showReforgedChanges);
        load_line(config, "show_reforged_graces", config::showReforgedGraces);
        load_line(config, "show_reforged_archery_challenges", config::showReforgedArcheryChallenges);

        load_line(config, "redify_boss_icons", config::redifyBossIcons);

        // Vanilla Goblin
        load_line(config, "show_goblin_graces", config::showGoblinGraces);
        load_line(config, "show_goblin_spirit_springs", config::showGoblinSpiritSprings);
        load_line(config, "show_goblin_summoning_pools", config::showGoblinSummoningPools);
        load_line(config, "show_goblin_unique_drops", config::showGoblinUniqueDrops);
        load_line(config, "show_goblin_hostile_npc", config::showGoblinHostileNPC);
        load_line(config, "show_goblin_imp_statues", config::showGoblinImpStatues);
        load_line(config, "show_goblin_teardrop_scarabs", config::showGoblinTeardropScarabs);
        load_line(config, "show_goblin_non_respawning_materials", config::showGoblinNonRespawningMaterials);
        load_line(config, "show_goblin_key_and_unique", config::showGoblinKeyAndUnique);
        load_line(config, "show_goblin_prayerbooks", config::showGoblinPrayerbooks);
        load_line(config, "show_goblin_cookbooks", config::showGoblinCookbooks);
        load_line(config, "show_goblin_memory_stones", config::showGoblinMemoryStones);
        load_line(config, "show_goblin_crystal_tears", config::showGoblinCrystalTears);
        load_line(config, "show_goblin_pots_and_perfumes", config::showGoblinPotsAndPerfumes);
        load_line(config, "show_goblin_lost_ashes_of_war", config::showGoblinLostAshesOfWar);
        load_line(config, "show_goblin_larval_tears", config::showGoblinLarvalTears);
        load_line(config, "show_goblin_celestial_dew", config::showGoblinCelestialDew);
        load_line(config, "show_goblin_stonesword_keys", config::showGoblinStoneswordKeys);
        load_line(config, "show_goblin_paintings", config::showGoblinPaintings);
        load_line(config, "show_goblin_character_upgrades", config::showGoblinPlayerUpgrades);
        load_line(config, "show_goblin_smithing_stones", config::showGoblinSmithingStones);
        load_line(config, "show_goblin_gloveworts", config::showGoblinGloveworts);
        load_line(config, "show_goblin_armaments", config::showGoblinArmaments);
        load_line(config, "show_goblin_apparel", config::showGoblinApparel);
        load_line(config, "show_goblin_talismans", config::showGoblinTalismans);
        load_line(config, "show_goblin_spirit_ash", config::showGoblinSpiritAsh);
        load_line(config, "show_goblin_ashes_of_war", config::showGoblinAshesOfWar);
        load_line(config, "show_goblin_sorceries", config::showGoblinSorceries);
        load_line(config, "show_goblin_incantations", config::showGoblinIncantations);
        load_line(config, "show_goblin_consumables", config::showGoblinConsumables);
        load_line(config, "show_goblin_crafting_materials", config::showGoblinCraftingMaterials);
        load_line(config, "show_goblin_multiplayer_items", config::showGoblinMultiplayerItems);

    }
}

void goblin::load_line(mINI::INIMap<std::string> config, std::string lineInIni, bool& boolVariable) {
    if (config.has(lineInIni))
        boolVariable = config[lineInIni] != "false";
    spdlog::info("Loaded: " + lineInIni);
    spdlog::info("Loaded value = {}", boolVariable);
}

void goblin::load_line(mINI::INIMap<std::string> config, std::string lineInIni, long long& intVariable) {
    if (config.has(lineInIni))
        intVariable = std::stoll(config[lineInIni]);
    spdlog::info("Loaded: " + lineInIni);
    spdlog::info("Loaded value = {}", intVariable);
}