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
#ifdef _DEBUG
            spdlog::info("Found - Vanilla - Dungeons - ID = {}", id);
#endif // DEBUG

            // Skip the row if its texts are not "Location name"  (skipped), "Boss Name" (skipped), "Encountered", "Resurrected" and "Defeated"
            if (goblin::mapPoint::ContainsTextId(row, 2, 5100, 5110, 5120) || goblin::mapPoint::ContainsTextId(row, 2, 5300, 5310, 5320)) {
                if (config::showOverworldIcons)
                    goblin::mapPoint::errNative::SetupReforgedIcon(id, row);

                // Hide the boss names from dungeons and locations
                if (goblin::config::hideBossesOnCompletion)
                    goblin::mapPoint::errNative::HideOnCompletion(row);
            }
        }
        // Boss icons enabled and overworld range
        else if (goblin::icons::reforged::bossIcons.IsInRange(id)) {
#if _DEBUG
            spdlog::info("Found - Reforged Goblin - Bosses - ID = {}", id);
#endif // DEBUG
            // Skip the row if its texts are not "Boss Name" (skipped), "Encountered", "Resurrected" and "Defeated"
            if (goblin::mapPoint::ContainsTextId(row, 1, 5100, 5110, 5120)) {
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
#ifdef _DEBUG
            spdlog::info("Found - Reforged Goblin - Camps - ID = {}", id);
#endif // DEBUG
            // Skip the row if its texts are not "Camp Name" (skipped), "Discovered" and "Completed", 0 is also skipped
            if (goblin::mapPoint::ContainsTextId(row, 1, 5000, 0, 5020)) {
                if (config::showCampIcons)
                    goblin::mapPoint::errNative::SetupReforgedIcon(id, row);

                if (goblin::config::hideCampsOnCompletion)
                    goblin::mapPoint::errNative::HideOnCompletion(row);
            }
        }
        // Merchant icons
        else if (goblin::icons::base::gameNPCs.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Merchants - ID = {}", id);
#endif // DEBUG
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
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Graces - ID = {}", id);
#endif // DEBUG
            if (goblin::config::showGoblinGraces) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::spiritSprings.IsInRange(id) || goblin::icons::baseGoblin::DLC::spiritSprings.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Spirit Springs - ID = {}", id);
#endif // DEBUG
            if (goblin::config::showGoblinSpiritSprings) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::summoningPools.IsInRange(id) || goblin::icons::baseGoblin::DLC::summoningPools.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Summoning Pools - ID = {}", id);
#endif // DEBUG

            if (goblin::config::showGoblinSummoningPools) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::uniqueDrops.IsInRange(id) || goblin::icons::baseGoblin::DLC::uniqueDrops.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Unique Drops - ID = {}", id);
#endif // DEBUG            
            if (goblin::config::showGoblinUniqueDrops) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::hostileNPC.IsInRange(id) || goblin::icons::baseGoblin::DLC::hostileNPC.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Hostile NPCs - ID = {}", id);
#endif // DEBUG
            if (goblin::config::showGoblinHostileNPC) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::impStatues.IsInRange(id) || goblin::icons::baseGoblin::DLC::impStatues.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Imp Statues - ID = {}", id);
#endif // DEBUG
            if (goblin::config::showGoblinImpStatues) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::teardropScarabs.IsInRange(id) || goblin::icons::baseGoblin::DLC::teardropScarabs.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Teardrop Scarabs - ID = {}", id);
#endif // DEBUG
            if (goblin::config::showGoblinTeardropScarabs) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::nonRespawningMaterials.IsInRange(id) || goblin::icons::baseGoblin::DLC::nonRespawningMaterials.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Nodes - ID = {}", id);
#endif // DEBUG
            if (goblin::config::showGoblinNonRespawningMaterials) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::keyAndUnique.IsInRange(id) || goblin::icons::baseGoblin::baseGame::keyAndUnique2.IsInRange(id) || goblin::icons::baseGoblin::DLC::keyAndUnique.IsInRange(id) || goblin::icons::baseGoblin::DLC::keyAndUnique2.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Key & Uniques - ID = {}", id);
#endif // DEBUG            
            if (goblin::config::showGoblinKeyAndUnique) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::prayerbooks.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Prayerbooks - ID = {}", id);
#endif // DEBUG
            if (goblin::config::showGoblinPrayerbooks) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::cookbooks.IsInRange(id) || goblin::icons::baseGoblin::DLC::cookbooks.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Cookbooks - ID = {}", id);
#endif // DEBUG
            if (goblin::config::showGoblinCookbooks) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::memoryStones.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Memory Stones - ID = {}", id);
#endif // DEBUG            
            if (goblin::config::showGoblinMemoryStones) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::crystalTears.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Crystal Tears - ID = {}", id);
#endif // DEBUG
            if (goblin::config::showGoblinCrystalTears) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::potsAndPerfumes.IsInRange(id) || goblin::icons::baseGoblin::DLC::potsAndPerfumes.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Pots & Perfumes - ID = {}", id);
#endif // DEBUG
            if (goblin::config::showGoblinPotsAndPerfumes) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::lostAshesOfWar.IsInRange(id) || goblin::icons::baseGoblin::DLC::lostAshesOfWar.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Lost Ashes of War - ID = {}", id);
#endif // DEBUG
            if (goblin::config::showGoblinLostAshesOfWar) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::larvalTears.IsInRange(id) || goblin::icons::baseGoblin::DLC::larvalTears.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Larval Tears - ID = {}", id);
#endif // DEBUG

            if (goblin::config::showGoblinLarvalTears) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::celestialDew.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Celestial Dew - ID = {}", id);
#endif
            if (goblin::config::showGoblinCelestialDew) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::stoneswordKeys.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Stonesword Keys - ID = {}", id);
#endif
            if (goblin::config::showGoblinStoneswordKeys) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::paintings.IsInRange(id) || goblin::icons::baseGoblin::DLC::paintings.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Paintings - ID = {}", id);
#endif
            if (goblin::config::showGoblinPaintings) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::DLC::characterUpgradeItems.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Upgrades - ID = {}", id);
#endif
            if (goblin::config::showGoblinPlayerUpgrades) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::DLC::smithingStones.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Smithing Stones - ID = {}", id);
#endif
            if (goblin::config::showGoblinSmithingStones) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::DLC::gloveworts.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Gloveworts - ID = {}", id);
#endif
            if (goblin::config::showGoblinGloveworts) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::armaments.IsInRange(id) || goblin::icons::baseGoblin::DLC::armaments.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Armaments - ID = {}", id);
#endif
            if (goblin::config::showGoblinArmaments) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::apparel.IsInRange(id) || goblin::icons::baseGoblin::DLC::apparel.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Apparel - ID = {}", id);
#endif
            if (goblin::config::showGoblinApparel) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::talismans.IsInRange(id) || goblin::icons::baseGoblin::DLC::talismans.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Talismans - ID = {}", id);
#endif
            if (goblin::config::showGoblinTalismans) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::spiritAsh.IsInRange(id) || goblin::icons::baseGoblin::DLC::spiritAsh.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Ashes of War - ID = {}", id);
#endif
            if (goblin::config::showGoblinSpiritAsh) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::ashesOfWar.IsInRange(id) || goblin::icons::baseGoblin::DLC::ashesOfWar.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Spirit Ashes - ID = {}", id);
#endif
            if (goblin::config::showGoblinAshesOfWar) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::sorceries.IsInRange(id) || goblin::icons::baseGoblin::DLC::sorceries.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Sorceries - ID = {}", id);
#endif
            if (goblin::config::showGoblinSorceries) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::incantations.IsInRange(id) || goblin::icons::baseGoblin::DLC::incantations.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Incantations - ID = {}", id);
#endif
            if (goblin::config::showGoblinIncantations) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::consumables.IsInRange(id) || goblin::icons::baseGoblin::DLC::consumables.IsInRange(id) || goblin::icons::baseGoblin::DLC::consumables2.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Consumable Items - ID = {}", id);
#endif
            if (goblin::config::showGoblinConsumables) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::craftingMaterials.IsInRange(id) || goblin::icons::baseGoblin::DLC::craftingMaterials.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Crafting Items - ID = {}", id);
#endif
            if (goblin::config::showGoblinCraftingMaterials) {
                row.eventFlagId = GetMapFragment(id, row);

                if (!goblin::config::requireMapFragments)
                    row.eventFlagId = goblin::flag::AlwaysOn;
            }
            else
                row.eventFlagId = goblin::flag::AlwaysOff;
        }

        else if (goblin::icons::baseGoblin::baseGame::multiplayerItems.IsInRange(id) || goblin::icons::baseGoblin::DLC::multiplayerItems.IsInRange(id)) {
#ifdef _DEBUG
            spdlog::info("Found - Vanilla Goblin - Multiplayer Items - ID = {}", id);
#endif
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
#ifdef _DEBUG
            spdlog::info("Found - Reforged Goblin - Incantation - ID = {}", id);
#endif
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
#ifdef _DEBUG
            spdlog::info("Found - Reforged Goblin - Sorcery - ID = {}", id);
#endif
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
#ifdef _DEBUG
            spdlog::info("Found - Reforged Goblin - Weapon - ID = {}", id);
#endif
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
#ifdef _DEBUG
            spdlog::info("Found - Reforged Goblin - Spirit Ash - ID = {}", id);
#endif
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
#ifdef _DEBUG
            spdlog::info("Found - Reforged Goblin - Ash of War - ID = {}", id);
#endif
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
#ifdef _DEBUG
            spdlog::info("Found - Reforged Goblin - Crystal Tear - ID = {}", id);
#endif
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
#ifdef _DEBUG
            spdlog::info("Found - Reforged Goblin - Talisman - ID = {}", id);
#endif
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
#ifdef _DEBUG
            spdlog::info("Found - Reforged Goblin - Fortune - ID = {}", id);
#endif
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
#ifdef _DEBUG
            spdlog::info("Found - Reforged Goblin - Apparel - ID = {}", id);
#endif
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
#ifdef _DEBUG
            spdlog::info("Found - Reforged Goblin - Changes - ID = {}", id);
#endif
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
#ifdef _DEBUG
            spdlog::info("Found - Reforged Goblin - Graces - ID = {}", id);
#endif
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
#ifdef _DEBUG
            spdlog::info("Found - Archery Challenges - Fortune - ID = {}", id);
#endif
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

        if (id == 65023) {
            spdlog::info("Frenzyflame Event Id - ID = {}", row.eventFlagId);
            spdlog::info("Frenzyflame Flag Id1 - ID = {}", row.textEnableFlagId1);
            spdlog::info("Frenzyflame Flag Id2 - ID = {}", row.textEnableFlagId2);
            spdlog::info("Armaments enabled - ID = {}", goblin::config::showGoblinArmaments);
            
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
    // textId5 checks for clear flag, cause then textId1 is dungeon name
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
    *showNameFlag = goblin::flag::AlwaysOn;

    // Get required map fragment
    int requiredMapFragment = GetMapFragment(rowId, row);

    // If it doesn't require a map, get rid of the map fragment flag
    if (!config::requireMapFragments) {
        requiredMapFragment = goblin::flag::AlwaysOn;
    }

    *eventFlag = requiredMapFragment;
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