#include "goblin_main.hpp"

void goblin::mapPoint::Initialise() {

    // Loop through all bonfires
    for (auto [id, row] :
        from::params::get_param<from::paramdef::BONFIRE_WARP_PARAM_ST>(L"BonfireWarpParam")) {
        // hide boss names from graces on completion
        if (goblin::config::hideBossesOnCompletion)
            goblin::mapPoint::errNative::HideOnCompletion(row);
    }

    // Loop through all WorldMapPointParam
    for (auto [id, row] :
        from::params::get_param<from::paramdef::WORLD_MAP_POINT_PARAM_ST>(L"WorldMapPointParam")) {

        /*
        *
        * Reforged stuff goes here
        *
        */

        // base ER dungeon and overworld icons
        if (goblin::icons::base::dungeonIcons.IsInRange(id) || goblin::icons::base::overworldLocations.IsInRange(id)) {
            // Skip the row if its texts are not "Location name"  (skipped), "Boss Name" (skipped), "Encountered", "Resurrected" and "Defeated"
            if (row.textId3 == 5100 || row.textId3 == 5300) {
                if (config::showOverworldIcons)
                    goblin::mapPoint::errNative::SetupDungeonIcon(id, row);

                // Hide the boss names from dungeons and locations
                if (goblin::config::hideBossesOnCompletion)
                    goblin::mapPoint::errNative::HideOnCompletion(row);
            }
#ifdef _DEBUG
            spdlog::info("eventFlagId = {}", row.eventFlagId);
            spdlog::info("textEnableFlagId1 = {}", row.textEnableFlagId1);
            spdlog::info("textEnableFlagId2 = {}", row.textEnableFlagId2);
            spdlog::info("textEnableFlagId3 = {}", row.textEnableFlagId3);
            spdlog::info("textDisableFlagId1 = {}", row.textDisableFlagId1);
            spdlog::info("textEnableFlag2Id1 = {}", row.textEnableFlag2Id1);
#endif // DEBUG
        }
        // Boss icons enabled and overworld range
        else if (goblin::icons::reforged::bossIcons.IsInRange(id)) {
            // Skip the row if its texts are not "Boss Name" (skipped), "Encountered", "Resurrected" and "Defeated"
            if (row.textId2 == 5100) {
                if (config::showBossIcons)
                    goblin::mapPoint::errNative::SetupReforgedIcon(id, row);
                // Hide the boss icons on completion
                if (goblin::config::hideBossesOnCompletion)
                    goblin::mapPoint::errNative::HideOnCompletion(row);

                // Set the boss iconId to red blades, 41 boss, 67 remembrance, 372 red blades
                if (config::redifyBossIcons)
                {
                    row.iconId = 372;
                }
            }
        }
        // Camp icons enabled and within range
        else if (goblin::icons::reforged::campIcons.IsInRange(id)) {
            // Skip the row if its texts are not "Camp Name" (skipped), "Discovered" and "Completed", 0 is also skipped
            if (row.textId2 == 5000) {
                if (config::showCampIcons)
                    goblin::mapPoint::errNative::SetupReforgedIcon(id, row);

                if (goblin::config::hideCampsOnCompletion)
                    goblin::mapPoint::errNative::HideOnCompletion(row);
            }
        }
        // Merchant icons
        else if (goblin::icons::base::gameNPCs.IsInRange(id)) {
            if (config::showMerchants) {
                if ((row.textId2 >= 180000 && row.textId3 < 190000) || (row.textId3 >= 180000 && row.textId3 < 190000)) {
                    goblin::mapPoint::errNative::SetupMerchantIcon(id, row);
                }
            }
        }


        /*
        *
        * Goblin base goes here
        * Include DLC stuff
        *
        */

        else if (goblin::icons::baseGoblin::baseGame::graces.IsInRange(id) || goblin::icons::baseGoblin::DLC::graces.IsInRange(id)) {
            if (goblin::config::showGoblinGraces) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::spiritSprings.IsInRange(id) || goblin::icons::baseGoblin::DLC::spiritSprings.IsInRange(id)) {
            if (goblin::config::showGoblinSpiritSprings) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::summoningPools.IsInRange(id) || goblin::icons::baseGoblin::DLC::summoningPools.IsInRange(id)) {
            if (goblin::config::showGoblinSummoningPools) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::uniqueDrops.IsInRange(id) || goblin::icons::baseGoblin::DLC::uniqueDrops.IsInRange(id)) {
            if (goblin::config::showGoblinUniqueDrops) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::hostileNPC.IsInRange(id) || goblin::icons::baseGoblin::DLC::hostileNPC.IsInRange(id)) {
            if (goblin::config::showGoblinHostileNPC) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::impStatues.IsInRange(id) || goblin::icons::baseGoblin::DLC::impStatues.IsInRange(id)) {
            if (goblin::config::showGoblinImpStatues) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::teardropScarabs.IsInRange(id) || goblin::icons::baseGoblin::DLC::teardropScarabs.IsInRange(id)) {
            if (goblin::config::showGoblinTeardropScarabs) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::nonRespawningMaterials.IsInRange(id) || goblin::icons::baseGoblin::DLC::nonRespawningMaterials.IsInRange(id)) {
            if (goblin::config::showGoblinNonRespawningMaterials) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::keyAndUnique.IsInRange(id) || goblin::icons::baseGoblin::baseGame::keyAndUnique2.IsInRange(id) || goblin::icons::baseGoblin::DLC::keyAndUnique.IsInRange(id) || goblin::icons::baseGoblin::DLC::keyAndUnique2.IsInRange(id)) {
            if (goblin::config::showGoblinKeyAndUnique) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::prayerbooks.IsInRange(id)) {
            if (goblin::config::showGoblinPrayerbooks) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }
        else if (goblin::icons::baseGoblin::baseGame::cookbooks.IsInRange(id) || goblin::icons::baseGoblin::DLC::cookbooks.IsInRange(id)) {
            if (goblin::config::showGoblinCookbooks) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::memoryStones.IsInRange(id)) {       
            if (goblin::config::showGoblinMemoryStones) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::crystalTears.IsInRange(id)) {
            if (goblin::config::showGoblinCrystalTears) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }
        else if (goblin::icons::baseGoblin::baseGame::potsAndPerfumes.IsInRange(id) || goblin::icons::baseGoblin::DLC::potsAndPerfumes.IsInRange(id)) {
            if (goblin::config::showGoblinPotsAndPerfumes) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }
        else if (goblin::icons::baseGoblin::baseGame::lostAshesOfWar.IsInRange(id) || goblin::icons::baseGoblin::DLC::lostAshesOfWar.IsInRange(id)) {
            if (goblin::config::showGoblinLostAshesOfWar) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::larvalTears.IsInRange(id) || goblin::icons::baseGoblin::DLC::larvalTears.IsInRange(id)) {
            if (goblin::config::showGoblinLarvalTears) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::celestialDew.IsInRange(id)) {
            if (goblin::config::showGoblinCelestialDew) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::stoneswordKeys.IsInRange(id)) {
            if (goblin::config::showGoblinStoneswordKeys) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::paintings.IsInRange(id) || goblin::icons::baseGoblin::DLC::paintings.IsInRange(id)) {
            if (goblin::config::showGoblinPaintings) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::DLC::characterUpgradeItems.IsInRange(id)) {
            if (goblin::config::showGoblinPlayerUpgrades) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }
        else if (goblin::icons::baseGoblin::DLC::smithingStones.IsInRange(id)) {
            if (goblin::config::showGoblinSmithingStones) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::DLC::gloveworts.IsInRange(id)) {
            if (goblin::config::showGoblinGloveworts) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::armaments.IsInRange(id) || goblin::icons::baseGoblin::DLC::armaments.IsInRange(id)) {
            if (goblin::config::showGoblinArmaments) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }
        else if (goblin::icons::baseGoblin::baseGame::apparel.IsInRange(id) || goblin::icons::baseGoblin::DLC::apparel.IsInRange(id)) {
            if (goblin::config::showGoblinApparel) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }
        else if (goblin::icons::baseGoblin::baseGame::talismans.IsInRange(id) || goblin::icons::baseGoblin::DLC::talismans.IsInRange(id)) {
            if (goblin::config::showGoblinTalismans) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }
        else if (goblin::icons::baseGoblin::baseGame::spiritAsh.IsInRange(id) || goblin::icons::baseGoblin::DLC::spiritAsh.IsInRange(id)) {
            if (goblin::config::showGoblinSpiritAsh) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }
        else if (goblin::icons::baseGoblin::baseGame::ashesOfWar.IsInRange(id) || goblin::icons::baseGoblin::DLC::ashesOfWar.IsInRange(id)) {
            if (goblin::config::showGoblinAshesOfWar) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::sorceries.IsInRange(id) || goblin::icons::baseGoblin::DLC::sorceries.IsInRange(id)) {
            if (goblin::config::showGoblinSorceries) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::incantations.IsInRange(id) || goblin::icons::baseGoblin::DLC::incantations.IsInRange(id)) {
            if (goblin::config::showGoblinIncantations) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::consumables.IsInRange(id) || goblin::icons::baseGoblin::DLC::consumables.IsInRange(id) || goblin::icons::baseGoblin::DLC::consumables2.IsInRange(id)) {
            if (goblin::config::showGoblinConsumables) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::craftingMaterials.IsInRange(id) || goblin::icons::baseGoblin::DLC::craftingMaterials.IsInRange(id)) {
            if (goblin::config::showGoblinCraftingMaterials) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::multiplayerItems.IsInRange(id) || goblin::icons::baseGoblin::DLC::multiplayerItems.IsInRange(id)) {
            if (goblin::config::showGoblinCraftingMaterials) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }
        /*
        *
        * Reforged Goblin goes here
        *
        */

        // Reforged incantations, manually added map flags so they only have to check if they're on, then adjust based on map fragments
        else if (goblin::icons::reforged::incantations.IsInRange(id)) {
            // Check if they're enabled
            if (goblin::config::showReforgedIncantations) {
                // Check if they don't require map fragments
                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;

                // If they require, just do nothing, since they're manually added
            }
            else {
                // If they're not enabled, always off
                row.eventFlagId = goblin::flag::AlwaysOff;
            }
        }
        // Reforged sorceries, manually added map flags so they only have to check if they're on, then adjust based on map fragments
        else if (goblin::icons::reforged::sorceries.IsInRange(id)) {
            // Check if they're enabled
            if (goblin::config::showReforgedSorceries) {
                // Check if they don't require map fragments
                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;

                // If they require, just do nothing, since they're manually added
            }
            else {
                // If they're not enabled, always off
                row.eventFlagId = goblin::flag::AlwaysOff;
            }
        }
        // Reforged weapons, manually added map flags so they only have to check if they're on, then adjust based on map fragments
        else if (goblin::icons::reforged::armaments.IsInRange(id)) {
            // Check if they're enabled
            if (goblin::config::showReforgedArmaments) {
                // Check if they don't require map fragments
                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;

                // If they require, just do nothing, since they're manually added
            }
            else {
                // If they're not enabled, always off
                row.eventFlagId = goblin::flag::AlwaysOff;
            }
        }
        // Reforged spirit ashes, manually added map flags so they only have to check if they're on, then adjust based on map fragments
        else if (goblin::icons::reforged::spiritAshes.IsInRange(id)) {
            // Check if they're enabled
            if (goblin::config::showReforgedSpiritAshes) {
                // Check if they don't require map fragments
                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;

                // If they require, just do nothing, since they're manually added
            }
            else {
                // If they're not enabled, always off
                row.eventFlagId = goblin::flag::AlwaysOff;
            }
        }
        // Reforged ashes of war, manually added map flags so they only have to check if they're on, then adjust based on map fragments
        else if (goblin::icons::reforged::ashesOfWar.IsInRange(id)) {
            // Check if they're enabled
            if (goblin::config::showReforgedAshesOfWar) {
                // Check if they don't require map fragments
                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;

                // If they require, just do nothing, since they're manually added
            }
            else {
                // If they're not enabled, always off
                row.eventFlagId = goblin::flag::AlwaysOff;
            }
        }
        // Reforged crystal tears, manually added map flags so they only have to check if they're on, then adjust based on map fragments
        else if (goblin::icons::reforged::crystalTears.IsInRange(id)) {
            // Check if they're enabled
            if (goblin::config::showReforgedCrystalTears) {
                // Check if they don't require map fragments
                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;

                // If they require, just do nothing, since they're manually added
            }
            else {
                // If they're not enabled, always off
                row.eventFlagId = goblin::flag::AlwaysOff;
            }
        }
        // Reforged talismans, manually added map flags so they only have to check if they're on, then adjust based on map fragments
        else if (goblin::icons::reforged::talismans.IsInRange(id)) {
            // Check if they're enabled
            if (goblin::config::showReforgedTalismans) {
                // Check if they don't require map fragments
                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;

                // If they require, just do nothing, since they're manually added
            }
            else {
                // If they're not enabled, always off
                row.eventFlagId = goblin::flag::AlwaysOff;
            }
        }
        // Reforged fortunes, manually added map flags so they only have to check if they're on, then adjust based on map fragments
        else if (goblin::icons::reforged::fortunes.IsInRange(id)) {
            // Check if they're enabled
            if (goblin::config::showReforgedFortunes) {
                // Check if they don't require map fragments
                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;

                // If they require, just do nothing, since they're manually added
            }
            else {
                // If they're not enabled, always off
                row.eventFlagId = goblin::flag::AlwaysOff;
            }
        }
        // Reforged apparel, manually added map flags so they only have to check if they're on, then adjust based on map fragments
        else if (goblin::icons::reforged::apparel.IsInRange(id)) {
            // Check if they're enabled
            if (goblin::config::showReforgedApparel) {
                // Check if they don't require map fragments
                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;

                // If they require, just do nothing, since they're manually added
            }
            else {
                // If they're not enabled, always off
                row.eventFlagId = goblin::flag::AlwaysOff;
            }
        }
        // Reforged changes, manually added map flags so they only have to check if they're on, then adjust based on map fragments
        else if (goblin::icons::reforged::changes.IsInRange(id)) {
            // Check if they're enabled
            if (goblin::config::showReforgedChanges) {
                // Check if they don't require map fragments
                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;

                // If they require, just do nothing, since they're manually added
            }
            else {
                // If they're not enabled, always off
                row.eventFlagId = goblin::flag::AlwaysOff;
            }
        }
        // Reforged graces, manually added map flags so they only have to check if they're on, then adjust based on map fragments
        else if (goblin::icons::reforged::graces.IsInRange(id)) {
            // Check if they're enabled
            if (goblin::config::showReforgedGraces) {
                // Check if they don't require map fragments
                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;

                // If they require, just do nothing, since they're manually added
            }
            else {
                // If they're not enabled, always off
                row.eventFlagId = goblin::flag::AlwaysOff;
            }
        }
        // Reforged graces, manually added map flags so they only have to check if they're on, then adjust based on map fragments
        else if (goblin::icons::reforged::archeryChallenges.IsInRange(id)) {
            // Check if they're enabled
            if (goblin::config::showReforgedArcheryChallenges) {
                // Check if they don't require map fragments
                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;

                // If they require, just do nothing, since they're manually added
            }
            else {
                // If they're not enabled, always off
                row.eventFlagId = goblin::flag::AlwaysOff;
            }
        }
    }
}

static ParamRange baseMerchantText(180000, 190000);
void goblin::mapPoint::errNative::SetupMerchantIcon(int rowId, from::paramdef::WORLD_MAP_POINT_PARAM_ST& row) {
    auto eventFlag = &row.eventFlagId;
    auto displayNameFlag = &row.textEnableFlagId2;
    if (baseMerchantText.IsInRange(row.textId3))
        displayNameFlag = &row.textEnableFlagId3;

    int requiredMapFragment = goblin::flag::AlwaysOn;
    if (config::requireMapFragments)
        requiredMapFragment = GetMapFragment(rowId, row);

    *displayNameFlag = 0;
    *eventFlag = requiredMapFragment;

}


void goblin::mapPoint::errNative::SetupReforgedIcon(int rowId, from::paramdef::WORLD_MAP_POINT_PARAM_ST& row) {
    auto eventFlag = &row.eventFlagId;
    auto showNameFlag = &row.textEnableFlagId1;
    auto showEncounteredFlag = &row.textEnableFlagId2;  

    // Show "Encountered" only when encountered
    *showEncounteredFlag = *eventFlag;
    // Name always visible
    *showNameFlag = goblin::flag::AlwaysOn;

    // Get required map fragment
    int requiredMapFragment = GetMapFragment(rowId, row);

    // If it doesn't require a map, get rid of the map fragment flag
    if (!config::requireMapFragments) {
        requiredMapFragment = goblin::flag::AlwaysOn;
    }
    *eventFlag = requiredMapFragment;
}

void goblin::mapPoint::errNative::SetupDungeonIcon(int rowId, from::paramdef::WORLD_MAP_POINT_PARAM_ST& row) {
    row.eventFlagId = 0;
    auto showLocationFlag = &row.textEnableFlagId1;
    auto showNameFlag = &row.textEnableFlagId2;

    if (config::requireMapFragments) {
        // Get required map fragment
        int mapFragment = GetMapFragment(rowId, row);
        *showLocationFlag = mapFragment;
        *showNameFlag = mapFragment;
    }
        // Name always visible
    else *showNameFlag = goblin::flag::AlwaysOn;
}

/// <summary>
/// Hides boss names on completion
/// </summary>
void goblin::mapPoint::errNative::HideOnCompletion(from::paramdef::WORLD_MAP_POINT_PARAM_ST& row) {
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
void goblin::mapPoint::errNative::HideOnCompletion(from::paramdef::BONFIRE_WARP_PARAM_ST& row) {
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

static int goblin::mapPoint::GetMapFragment(int rowId, from::paramdef::WORLD_MAP_POINT_PARAM_ST& row) {
    int requiredMapFragment = goblin::flag::AlwaysOn;
    // Get this icon's location
    auto chunk = goblin::mapPoint::MapTile(row.areaNo, row.gridXNo, row.gridZNo);
    // Get this icon's map fragment
    if (!goblin::mapPoint::HasException(rowId, requiredMapFragment)) {
        requiredMapFragment = goblin::mapPoint::GetMapFlagFromTile(chunk);
    }

    // If it's Ashen Capital, make sure it only appears after erdtree is burnt, we guarantee it by using textEnableFlag2 which is checked alongside textEnableFlag and eventFlagId, all 3 need to be ON then
    if (requiredMapFragment == goblin::flag::StoryErdtreeOnFire)
    {
        if (row.textId1 != -1)
            row.textEnableFlag2Id1 = requiredMapFragment;
        if (row.textId2 != -1)
            row.textEnableFlag2Id2 = requiredMapFragment;
        if (row.textId3 != -1)
            row.textEnableFlag2Id3 = requiredMapFragment;
        if (row.textId4 != -1)
            row.textEnableFlag2Id4 = requiredMapFragment;
        if (row.textId5 != -1)
            row.textEnableFlag2Id5 = requiredMapFragment;
        if (row.textId6 != -1)
            row.textEnableFlag2Id6 = requiredMapFragment;
        if (row.textId7 != -1)
            row.textEnableFlag2Id7 = requiredMapFragment;
        if (row.textId8 != -1)
            row.textEnableFlag2Id8 = requiredMapFragment;
        requiredMapFragment = goblin::flag::Leyndell;
    }else if(requiredMapFragment == goblin::flag::StoryCharmBroken){}
    else if(requiredMapFragment == goblin::flag::StorySealingTreeBurnt){}
    return requiredMapFragment;
}

static void goblin::mapPoint::SetPrimaryFlags(from::paramdef::WORLD_MAP_POINT_PARAM_ST& row, int flagId) {
            row.textEnableFlagId1 = flagId;
            row.textEnableFlagId2 = flagId;
            row.textEnableFlagId3 = flagId;
            row.textEnableFlagId4 = flagId;
            row.textEnableFlagId5 = flagId;
            row.textEnableFlagId6 = flagId;
            row.textEnableFlagId7 = flagId;
            row.textEnableFlagId8 = flagId;
}

static void goblin::mapPoint::SetSecondaryFlags(from::paramdef::WORLD_MAP_POINT_PARAM_ST& row, int flagId) {
    row.textEnableFlag2Id1 = flagId;
    row.textEnableFlag2Id2 = flagId;
    row.textEnableFlag2Id3 = flagId;
    row.textEnableFlag2Id4 = flagId;
    row.textEnableFlag2Id5 = flagId;
    row.textEnableFlag2Id6 = flagId;
    row.textEnableFlag2Id7 = flagId;
    row.textEnableFlag2Id8 = flagId;
}