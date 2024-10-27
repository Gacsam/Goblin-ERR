#pragma once

#include <filesystem>

namespace goblin
{
/**
 * Load user preferences from an .ini file
 */
void load_config(const std::filesystem::path &ini_path);

namespace config
{
/**
 * Automatically sell weapons upgraded to the highest level you've gotten on a given character
 */
extern bool requireMapFragments;
extern bool modifyBossIcons;
extern bool modifyOverworldIcons;
extern bool modifyCampIcons;
extern bool hideBossesOnCompletion;
extern bool hideOverworldOnCompletion;
extern bool hideCampsOnCompletion;
extern bool redifyBossIcons;

};
};
