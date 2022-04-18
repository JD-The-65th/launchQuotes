#include "GlobalNamespace/MainMenuViewController.hpp"

#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"
#include "beatsaber-hook/shared/utils/hooking.hpp"

#include "questui_components/shared/components/Text.hpp"
#include "sombrero/shared/FastColor.hpp"

#include "questui/shared/QuestUI.hpp"
#include "questui/shared/BeatSaberUI.hpp"
#include "questui/shared/CustomTypes/Components/ExternalComponents.hpp"

#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/Vector3.hpp"
#include "UnityEngine/Vector2.hpp"
#include "main.hpp"
#include "TMPro/TextMeshProUGUI.hpp"

#include <string>

#include "main.hpp"
#include "LaunchQuotes.hpp"


using namespace QuestUI;
using namespace UnityEngine;
using namespace UnityEngine::UI;
using namespace GlobalNamespace;
using namespace QUC;


std::vector<std::string> quotePool = {

    // thank you github copilot, you made this not tedious to copy over.
    "Well that's just the cost of Limerence.",
    "I'm not a cop, I'm a cop with a gun.",
    "BMBF WHEN",
    "BMBF NOW",
    "Just like in minecraft!",
    "ew u stink",
    "bandoot known hacker",
    "crying's easier in secret",
    "you better not be going to play a cametek map",
    "you better be going to play a cametek map",
    "JD is sad",
    "ur mom says hi",
    "ANOMALY DETECTED, BANGING UR MOM",
    "you better not be going to play a cametek map",
    "hee hee",
    "the tiny little piece on the quest 2 strap broke ;-;",
    "sugma",
    "sugma is a bitch",
    "Karen said she'd give me the kids back if you S'd the next song",
    "about soulless 5...",
    "pp trash",
    "acc trach",
    "ur mom is proud of you",
    "glad to see you've gotten off twitter",
    "doot doot",
    "E A SPORTS!",
    "It's in the game",
    "I'm not a fan of you",
    "Acc trash",
    "Furries are a major part of the IT industry",
    "You should also try beats and shapes",
    "New york is from New York",
    "Goodbye America, hello New York",
    "Also try MoonRider.xyz",
    "What day is it",
    "100 Percent Goose free",
    "Come on, how hard could making it cross platform be?",
    "Just hit the bloq, It is really easy",
    "Having an issue? Ask in #quest-help",
    "Having an issue? Do not.",
    "Why is New York called New York",
    "dope ass game - XBOX magazine",
    "Get Gud",
    "[Quest] Noodle Extensions",
    "Too many weeks",
    "wHy DiD tHe DeVs BrEaK mOdS aGaIn",
    "It's a game!",
    "my mother stole my homework",
    "peepoDuck",
    "pink cute eris cute goobie cute scad",
    "wdym my spelling is corect(edited)",
    "anomaly detected. Banging you're mom",
    "anomaly detected, doin ur mom",
    "how do i get noodle extensions(edited)",
    "cyan is a furry",
    "chroma NOT included",
    "Supports Noozle Extensions",
    "#quest-help",
    "SaberFactory",
    "Heqq",
    "wen BMBF???"
    "thank god for github copilot",
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAA",
    "every single night im on rule 34, beating my dick to some anime whore",
    "insert overused meme",
    "adhd personified"
};

std::string randomQuote() {
    int index = rand() % quotePool.size();
    return quotePool[index];
}

static RenderContext textCtx = nullptr;

TMPro::TextMeshProUGUI* text;

MAKE_HOOK_MATCH(MainMenuViewController_DidActivate, &MainMenuViewController::DidActivate, void,
    MainMenuViewController* self,
    bool firstActivation,
    bool addedToHierarchy,
    bool screenSystemEnabling
) {
    MainMenuViewController_DidActivate(self, firstActivation, addedToHierarchy, screenSystemEnabling);

    getLogger().info("Main Menu Opened");

    if(firstActivation){
        // Legacy code, replacing with questui_components soon tm. Default to this if you encounter issues with QUC
        // /*
        text = BeatSaberUI::CreateText(self->get_transform(), randomQuote());

        text->get_transform()->set_localPosition({ 15.0f, 150.0f, 360.0f });
        text->get_transform()->set_localScale({ 4.0f, 4.0f, 4.0f }); 
        // */


    } else {

    }
}

void LaunchQuotes::Hooks::MainMenuViewController() {
  INSTALL_HOOK(getLogger(), MainMenuViewController_DidActivate);
}