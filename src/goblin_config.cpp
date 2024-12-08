#include "goblin_config.hpp"
#include <spdlog/spdlog.h>

bool goblin::config::disableGoblin = false;
bool goblin::config::requireMapFragments = true;

bool goblin::config::showBossIcons = true;
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

bool goblin::config::showGoblinGraces = false;
bool goblin::config::showGoblinSpiritSprings = false;
bool goblin::config::showGoblinSummoningPools = false;
bool goblin::config::showGoblinUniqueDrops = false;
bool goblin::config::showGoblinHostileNPC = false;
bool goblin::config::showGoblinImpStatues = false;
bool goblin::config::showGoblinTeardropScarabs = false;
bool goblin::config::showGoblinNonRespawningMaterials = false;
bool goblin::config::showGoblinKeyAndUnique = false;
bool goblin::config::showGoblinPrayerbooks = false;
bool goblin::config::showGoblinCookbooks = false;
bool goblin::config::showGoblinMemoryStones = false;
bool goblin::config::showGoblinCrystalTears = false;
bool goblin::config::showGoblinPotsAndPerfumes = false;
bool goblin::config::showGoblinLostAshesOfWar = false;
bool goblin::config::showGoblinLarvalTears = false;
bool goblin::config::showGoblinCelestialDew = false;
bool goblin::config::showGoblinStoneswordKeys = false;
bool goblin::config::showGoblinPaintings = false;
bool goblin::config::showGoblinPlayerUpgrades = false;
bool goblin::config::showGoblinSmithingStones = false;
bool goblin::config::showGoblinGloveworts = false;
bool goblin::config::showGoblinArmaments = false;
bool goblin::config::showGoblinApparel = false;
bool goblin::config::showGoblinTalismans = false;
bool goblin::config::showGoblinSpiritAsh = false;
bool goblin::config::showGoblinAshesOfWar = false;
bool goblin::config::showGoblinSorceries = false;
bool goblin::config::showGoblinIncantations = false;
bool goblin::config::showGoblinConsumables = false;
bool goblin::config::showGoblinCraftingMaterials = false;
bool goblin::config::showGoblinMultiplayerItems = false;

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
        load_line(config, "show_goblin_summoning_pools", config::showGoblinGraces);
        load_line(config, "show_goblin_unique_drops", config::showGoblinSummoningPools);
        load_line(config, "show_goblin_hostile_npc", config::showGoblinUniqueDrops);
        load_line(config, "show_goblin_imp_statues", config::showGoblinImpStatues);
        load_line(config, "show_goblin_teardrop_scarabs", config::showGoblinTeardropScarabs);
        load_line(config, "show_goblin_non_respawning_materials", config::showGoblinNonRespawningMaterials);
        load_line(config, "show_goblin_key_and_unique", config::showGoblinKeyAndUnique);
        load_line(config, "show_goblin_cookbooks", config::showGoblinCookbooks);
        load_line(config, "show_goblin_pots_and_perfumes", config::showGoblinPotsAndPerfumes);
        load_line(config, "show_goblin_lost_ashes_of_war", config::showGoblinLostAshesOfWar);
        load_line(config, "show_goblin_larval_tears", config::showGoblinLarvalTears);
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