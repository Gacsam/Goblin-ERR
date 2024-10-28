#include "goblin_icons.hpp"

void goblin::map::Initialise() {
    // Loop through all bonfires

    for (auto [id, row] :
        from::params::get_param<from::paramdef::BONFIRE_WARP_PARAM_ST>(L"BonfireWarpParam")) {
        // hide boss names from graces on completion
        if (goblin::config::hideBossesOnCompletion)
            goblin::map::errNative::HideOnCompletion(row);
    }


    // Loop through all WorldMapPointParam
    for (auto [id, row] :
        from::params::get_param<from::paramdef::WORLD_MAP_POINT_PARAM_ST>(L"WorldMapPointParam")) {
        // Boss icons enabled and overworld range
        if (id >= goblin::icons::bossIcons && id < goblin::icons::campIcons) {

            // Skip the row if its texts are not "Boss Name" (skipped), "Encountered", "Resurrected" and "Defeated"
            if (goblin::param::ContainsTextId(row, 1, 5100, 5110, 5120)) {
                if (config::modifyBossIcons)
                    goblin::map::errNative::SetupReforgedIcon(id, row);
                // Hide the boss icons on completion
                if (goblin::config::hideBossesOnCompletion)
                    goblin::map::errNative::HideOnCompletion(row);

                // Set the boss iconId to red blades, 41 boss, 67 remembrance, 372 red blades
                if (config::redifyBossIcons)
                {
                    row.iconId = 372;
                }
            }
        }
        else if ((id >= goblin::icons::dungeonIcons && id < goblin::icons::dungeonIconsCutoff) || (id >= goblin::icons::overworldLocations && id < goblin::icons::overworldCutoff)) {
            // Skip the row if its texts are not "Location name"  (skipped), "Boss Name" (skipped), "Encountered", "Resurrected" and "Defeated"
            if (goblin::param::ContainsTextId(row, 2, 5100, 5110, 5120) || goblin::param::ContainsTextId(row, 2, 5300, 5310, 5320)) {
                if (config::modifyOverworldIcons)
                    goblin::map::errNative::SetupReforgedIcon(id, row);

                // Hide the boss names from dungeons and locations
                if (goblin::config::hideBossesOnCompletion)
                    goblin::map::errNative::HideOnCompletion(row);
            }
        }
        // Camp icons enabled and within range
        else if (id >= goblin::icons::campIcons && id < goblin::icons::overworldLocations) {
            // Skip the row if its texts are not "Camp Name" (skipped), "Discovered" and "Completed", 0 is also skipped
            if (goblin::param::ContainsTextId(row, 1, 5000, 0, 5020)) {
                if (config::modifyCampIcons)
                    goblin::map::errNative::SetupReforgedIcon(id, row);

                if (goblin::config::hideCampsOnCompletion)
                    goblin::map::errNative::HideOnCompletion(row);
            }
        }
    }
}


void goblin::map::errNative::SetupReforgedIcon(int rowId, from::paramdef::WORLD_MAP_POINT_PARAM_ST& row) {
    auto eventFlag = &row.eventFlagId;
    auto showNameFlag = &row.textEnableFlagId1;
    auto showEncounteredFlag = &row.textEnableFlagId2;
    // textId5 checks for dungeon, cause then textId1 is dungeon name
    if (row.textId5 == 5020 || row.textId5 == 5120 || row.textId5 == 5220 || row.textId5 == 5320) {
        showNameFlag = &row.textEnableFlagId2;
        showEncounteredFlag = &row.textEnableFlagId3;
    }
    else {
        // Show "Encountered" only when encountered
        // In case of dungeons, they already have those flags
        *showEncounteredFlag = *eventFlag;
    }
    // Name always visible
    *showNameFlag = 0;

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
        *eventFlag = mapFragment;
    }
    *eventFlag = mapFragment;
}

/// <summary>
/// Hides boss names on completion
/// </summary>
void goblin::map::errNative::HideOnCompletion(from::paramdef::WORLD_MAP_POINT_PARAM_ST& row) {
    auto hideNameFlag = &row.textDisableFlagId1;
    auto showCompleteFlag = &row.textEnableFlagId4;
    auto hideCompleteFlag = &row.textDisableFlagId4;
    if (row.textId5 == 5020 || row.textId5 == 5120 || row.textId5 == 5220 || row.textId5 == 5320) {
        // in case of a dungeon, encounterFlag is textEnableFlagId3
        hideNameFlag = &row.textDisableFlagId2;
        showCompleteFlag = &row.textEnableFlagId5;
        hideCompleteFlag = &row.textDisableFlagId5;
    }
    *hideNameFlag = *showCompleteFlag;
    *hideCompleteFlag = *showCompleteFlag;
}

/// <summary>
/// Hides boss names on completion - grace version
/// </summary>
void goblin::map::errNative::HideOnCompletion(from::paramdef::BONFIRE_WARP_PARAM_ST& row) {
    auto hideNameFlag = &row.textDisableFlagId1;
    auto showCompleteFlag = &row.textEnableFlagId4;
    auto hideCompleteFlag = &row.textDisableFlagId4;
    if (row.textId5 == 5020 || row.textId5 == 5120 || row.textId5 == 5220 || row.textId5 == 5320) {
        // in case of a dungeon, encounterFlag is textEnableFlagId3
        hideNameFlag = &row.textDisableFlagId2;
        showCompleteFlag = &row.textEnableFlagId5;
        hideCompleteFlag = &row.textDisableFlagId5;
    }
    *hideNameFlag = *showCompleteFlag;
    *hideCompleteFlag = *showCompleteFlag;
}