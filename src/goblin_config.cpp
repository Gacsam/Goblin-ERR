#include "goblin_config.hpp"

#include <mini/ini.h>
#include <spdlog/spdlog.h>

extern bool goblin::config::requireMapFragments = true;
extern bool goblin::config::modifyBossIcons = true;
extern bool goblin::config::modifyCampIcons = true;
extern bool goblin::config::modifyOverworldIcons = true;

extern bool goblin::config::hideBossesOnCompletion = false;
extern bool goblin::config::hideCampsOnCompletion = false;
extern bool goblin::config::hideOverworldOnCompletion = false;

extern bool goblin::config::redifyBossIcons = false;

void goblin::load_config(const std::filesystem::path& ini_path)
{
    spdlog::info("Loading config from {}", ini_path.string());

    mINI::INIFile file(ini_path.string());
    mINI::INIStructure ini;
    if (file.read(ini) && ini.has("Goblin"))
    {
        auto& config = ini["Goblin"];

        if (config.has("require_map_fragments"))
            config::requireMapFragments = config["require_map_fragments"] != "false";
        spdlog::info("require_map_fragments = {}", config::requireMapFragments);

        // Show icons ini
        if (config.has("modify_boss_icons"))
            config::modifyBossIcons = config["modify_boss_icons"] != "false";
        spdlog::info("modify_boss_icons = {}", config::modifyBossIcons);

        if (config.has("modify_camp_icons"))
            config::modifyCampIcons = config["modify_camp_icons"] != "false";
        spdlog::info("modify_camp_icons = {}", config::modifyCampIcons);
                
        if (config.has("modify_overworld_icons"))
            config::modifyOverworldIcons = config["modify_overworld_icons"] != "false";
        spdlog::info("modify_overworld_icons = {}", config::modifyOverworldIcons);

        // Completion stuff
        if (config.has("hide_bosses_on_completion"))
            config::hideBossesOnCompletion = config["hide_bosses_on_completion"] != "false";
        spdlog::info("hide_bosses_on_completion = {}", config::hideBossesOnCompletion);

        if (config.has("hide_camps_on_completion"))
            config::hideCampsOnCompletion = config["hide_camps_on_completion"] != "false";
        spdlog::info("hide_camps_on_completion = {}", config::hideCampsOnCompletion);


        if (config.has("redify_boss_icons"))
            config::redifyBossIcons = config["redify_boss_icons"] != "false";
        spdlog::info("redify_boss_icons = {}", config::redifyBossIcons);
    }
}
