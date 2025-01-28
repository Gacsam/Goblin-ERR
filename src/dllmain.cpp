#define WIN32_LEAN_AND_MEAN
#include <filesystem>
#include <memory>
#include <spdlog/sinks/daily_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
#include <thread>
#include <windows.h>

#include "from/params.hpp"
#include "modutils.hpp"

#include "goblin_config.hpp"
#include "goblin_main.hpp"

static std::thread mod_thread;

static void setup_logger(std::filesystem::path log_file)
{
    auto logger = std::make_shared<spdlog::logger>("goblin");
    logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%n] %^[%l]%$ %v");
    logger->sinks().push_back(
        std::make_shared<spdlog::sinks::daily_file_sink_st>(log_file.string(), 0, 0, false, 5));
    logger->flush_on(spdlog::level::info);

#if _DEBUG
    AllocConsole();
    FILE *stream;
    freopen_s(&stream, "CONOUT$", "w", stdout);
    freopen_s(&stream, "CONOUT$", "w", stderr);
    freopen_s(&stream, "CONIN$", "r", stdin);
    logger->sinks().push_back(std::make_shared<spdlog::sinks::stdout_color_sink_st>());
    logger->set_level(spdlog::level::trace);
#endif

    spdlog::set_default_logger(logger);
}

static void setup_mod()
{
    modutils::initialize();
    from::params::initialize();
    std::string delayInfo = "Sleeping an extra " + std::to_string(goblin::config::loadDelay) + " to work potential compatibility issues...";
    spdlog::info(delayInfo);
    std::this_thread::sleep_for(std::chrono::seconds(goblin::config::loadDelay));

    if (goblin::config::disableGoblin)
    {
        goblin::config::showBossIcons = false;
        goblin::config::showCampIcons = false;
        goblin::config::showOverworldIcons = false;
        goblin::config::showMerchants = false;

        goblin::config::hideBossesOnCompletion = false;
        goblin::config::hideCampsOnCompletion = false;
        goblin::config::hideOverworldOnCompletion = false;

        goblin::config::showReforgedIncantations = false;
        goblin::config::showReforgedSorceries = false;
        goblin::config::showReforgedArmaments = false;
        goblin::config::showReforgedSpiritAshes = false;
        goblin::config::showReforgedAshesOfWar = false;
        goblin::config::showReforgedCrystalTears = false;
        goblin::config::showReforgedTalismans = false;
        goblin::config::showReforgedFortunes = false;
        goblin::config::showReforgedApparel = false;
        goblin::config::showReforgedChanges = false;
        goblin::config::showReforgedGraces = false;
        goblin::config::showReforgedArcheryChallenges = false;

        goblin::config::showGoblinGraces = false;
        goblin::config::showGoblinSpiritSprings = false;
        goblin::config::showGoblinSummoningPools = false;
        goblin::config::showGoblinUniqueDrops = false;
        goblin::config::showGoblinHostileNPC = false;
        goblin::config::showGoblinImpStatues = false;
        goblin::config::showGoblinTeardropScarabs = false;
        goblin::config::showGoblinNonRespawningMaterials = false;
        goblin::config::showGoblinKeyAndUnique = false;
        goblin::config::showGoblinPrayerbooks = false;
        goblin::config::showGoblinCookbooks = false;
        goblin::config::showGoblinMemoryStones = false;
        goblin::config::showGoblinCrystalTears = false;
        goblin::config::showGoblinPotsAndPerfumes = false;
        goblin::config::showGoblinLostAshesOfWar = false;
        goblin::config::showGoblinLarvalTears = false;
        goblin::config::showGoblinCelestialDew = false;
        goblin::config::showGoblinStoneswordKeys = false;
        goblin::config::showGoblinPaintings = false;
        goblin::config::showGoblinPlayerUpgrades = false;
        goblin::config::showGoblinSmithingStones = false;
        goblin::config::showGoblinGloveworts = false;
        goblin::config::showGoblinArmaments = false;
        goblin::config::showGoblinApparel = false;
        goblin::config::showGoblinTalismans = false;
        goblin::config::showGoblinSpiritAsh = false;
        goblin::config::showGoblinAshesOfWar = false;
        goblin::config::showGoblinSorceries = false;
        goblin::config::showGoblinIncantations = false;
        goblin::config::showGoblinConsumables = false;
        goblin::config::showGoblinCraftingMaterials = false;
        goblin::config::showGoblinMultiplayerItems = false;
    }

    spdlog::info("Running Goblin setup...");
    goblin::mapPoint::Initialise();

    modutils::enable_hooks();
    spdlog::info("Initialized mod");
}

bool WINAPI DllMain(HINSTANCE dll_instance, unsigned int fdw_reason, void *lpv_reserved)
{
    if (fdw_reason == DLL_PROCESS_ATTACH)
    {
        wchar_t dll_filename[MAX_PATH] = {0};
        GetModuleFileNameW(dll_instance, dll_filename, MAX_PATH);
        auto folder = std::filesystem::path(dll_filename).parent_path();

        setup_logger(folder / "logs" / "GoblinERR.log");

#ifdef PROJECT_VERSION
        spdlog::info("Map For Goblins - Reforged version {}", PROJECT_VERSION);
#endif
        spdlog::info("Loading ini...");
        goblin::load_config(folder / "GoblinERR.ini");

        mod_thread = std::thread([]() {
            try
            {
                setup_mod();
            }
            catch (std::runtime_error const &e)
            {
                spdlog::error("Error initializing mod: {}", e.what());
                modutils::deinitialize();
            }
        });
    }
    else if (fdw_reason == DLL_PROCESS_DETACH && lpv_reserved != nullptr)
    {
        try
        {
            mod_thread.join();
            modutils::deinitialize();
            spdlog::info("Deinitialized mod");
        }
        catch (std::runtime_error const &e)
        {
            spdlog::error("Error deinitializing mod: {}", e.what());
            spdlog::shutdown();
            return false;
        }
        spdlog::shutdown();
    }
    return true;
}