#include "goblin_icons.hpp"

void goblin::map::Initialise() {
    // Loop through all bonfires

    for (auto [id, row] :
        from::params::get_param<from::paramdef::BONFIRE_WARP_PARAM_ST>(L"BonfireWarpParam")) {
        // if they're dungeons that contain boss names
        if (goblin::param::ContainsTextId(row, 2, 5100, 5110, 5120)) {
            if (goblin::config::hideBossesOnCompletion)
                goblin::map::errNative::HideOnCompletion(row.textDisableFlagId2, row.textEnableFlagId5, row.textId5);
        }
    }

    // Loop through all WorldMapPointParam
    for (auto [id, row] :
        from::params::get_param<from::paramdef::WORLD_MAP_POINT_PARAM_ST>(L"WorldMapPointParam")){



        // Boss icons enabled and overworld range
        if (id >= goblin::icons::bossIcons && id < goblin::icons::campIcons) {
            if (config::modifyBossIcons) {
                // Skip the row if its texts are not "Boss Name" (skipped), "Encountered", "Resurrected" and "Defeated"
                if (goblin::param::ContainsTextId(row, 1, 5100, 5110, 5120)) {
                    goblin::map::errNative::SetupReforgedIcon(id, row, false);
                    // Hide the boss icons on completion
                    if (goblin::config::hideBossesOnCompletion)
                        goblin::map::errNative::HideOnCompletion(row.textDisableFlagId1, row.textEnableFlagId4, row.textId4);

                    // Set the boss iconId to red blades, 41 boss, 67 remembrance, 372 red blades
                    if (config::redifyBossIcons)
                    {
                        row.iconId = 372;
                    }
                }
            }
        }
        else if ((id >= goblin::icons::dungeonIcons && id < goblin::icons::dungeonIconsCutoff) || (id >= goblin::icons::overworldLocations && id < goblin::icons::overworldCutoff)) {
            if (config::modifyOverworldIcons) {
                // Skip the row if its texts are not "Location name"  (skipped), "Boss Name" (skipped), "Encountered", "Resurrected" and "Defeated"
                if (goblin::param::ContainsTextId(row, 2, 5100, 5110, 5120) || goblin::param::ContainsTextId(row, 2, 5300, 5310, 5320)) {
                    goblin::map::errNative::SetupReforgedIcon(id, row, true);
                    // Hide the boss names from dungeon on completion
                    if (goblin::config::hideBossesOnCompletion)
                        goblin::map::errNative::HideOnCompletion(row.textDisableFlagId2, row.textEnableFlagId5, row.textId5);
                    // Hide the dungeons themselves
                    if (goblin::config::hideOverworldOnCompletion)
                        goblin::map::errNative::HideOnCompletion(row.textDisableFlagId1, row.textEnableFlagId5, row.textId5);
                }
            }
        }
        // Camp icons enabled and within range
        else if (id >= goblin::icons::campIcons && id < goblin::icons::overworldLocations) {
            if (config::modifyCampIcons) {
                // Skip the row if its texts are not "Camp Name" (skipped), "Discovered" and "Completed", 0 is also skipped
                if (goblin::param::ContainsTextId(row, 1, 5000, 0, 5020)) {
                    goblin::map::errNative::SetupReforgedIcon(id, row, false);

                    if (goblin::config::hideCampsOnCompletion)
                        goblin::map::errNative::HideOnCompletion(row.textDisableFlagId1, row.textEnableFlagId4, row.textId4);
                }
            }
        }
    }
}


void goblin::map::errNative::SetupReforgedIcon(int rowId, from::paramdef::WORLD_MAP_POINT_PARAM_ST& row, bool isDungeon) {
    // Split off "encounter" flag
    if (isDungeon) {
        row.textEnableFlagId2 = 0;
    }
    else {
        row.textEnableFlagId2 = row.eventFlagId;
    }
    /*
    * Check if requires map fragments
    * If true, set the event flag to fragment acquisition flag
    * Else make it always appear
    */
    int mapFragment = 0;
    if (config::requireMapFragments) {
        // Get this icon's location
        auto chunk = goblin::map::MapChunk(row.areaNo, row.gridXNo, row.gridZNo);
        // Get this icon's map fragment
        if (!goblin::map::IsFlagException(rowId, mapFragment)) {
            mapFragment = goblin::map::GetMapFlag(chunk);
        }
        row.eventFlagId = mapFragment;
    }
    row.eventFlagId = mapFragment;
}

/// <summary>
/// Hides boss name on completion
/// </summary>
/// <param name="bossNameFlag">The flag with the boss name</param>
/// <param name="defeatedFlag">The defeated flag</param>
/// <param name="defeatText">The defeated text</param>
void goblin::map::errNative::HideOnCompletion(auto& bossNameFlag, auto& defeatedFlag, auto& defeatText) {
    // boss name disable flag
    bossNameFlag = defeatedFlag;
    // defeated disable text
    defeatText = -1;
}