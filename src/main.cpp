#include "main.hpp"
#include "LaunchQuotes.hpp"
#include "config-utils/shared/config-utils.hpp"
#include "ModConfig.hpp"



static ModInfo modInfo; // Stores the ID and version of our mod, and is sent to the modloader upon startup

// Loads the config from disk using our modInfo, then returns it for use
Configuration& getConfig() {
    static Configuration config(modInfo);
    config.Load();
    return config;
}

// Returns a logger, useful for printing debug messages
Logger& getLogger() {
    static Logger* logger = new Logger(modInfo);
    return *logger;
}

// Called at the early stages of game loading
extern "C" void setup(ModInfo& info) {
    info.id = MOD_ID;
    info.version = VERSION;
    modInfo = info;
	
    getConfig().Load(); // Load the config file
    getLogger().info("Completed setup!");
}
DEFINE_CONFIG(ModConfig);

// Called later on in the game loading - a good time to install function hooks
extern "C" void load() {
    getModConfig().Init(modInfo); 
    il2cpp_functions::Init();

    getLogger().info("Installing hooks...");
    // Install our hooks 
    LaunchQuotes::InstallHooks();
    getLogger().info("Installed all hooks!");
}