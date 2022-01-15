#include "GlobalNamespace/MainMenuViewController.hpp"

#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"
#include "beatsaber-hook/shared/utils/hooking.hpp"

#include "questui/shared/QuestUI.hpp"
#include "questui/shared/BeatSaberUI.hpp"

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


static int randomInt() {
    return rand() % 58;
}



TMPro::TextMeshProUGUI* text;

MAKE_HOOK_MATCH(MainMenuViewController_DidActivate, &MainMenuViewController::DidActivate, void,
    MainMenuViewController* self,
    bool firstActivation,
    bool addedToHierarchy,
    bool screenSystemEnabling
) {
    MainMenuViewController_DidActivate(self, firstActivation, addedToHierarchy, screenSystemEnabling);

    getLogger().info("Main Menu Opened");

    
    int sentence = randomInt();

    std::string phrase;

    if (sentence == 0) {
        phrase = "BMBF WHEN";
    }
    if (sentence == 1) {
        phrase = "BMBF NOW";
    }
    if (sentence == 2) {
        phrase = "Just like in minecraft!";
    }
    if (sentence == 3) {
        phrase = "ew u stink";
    }
    if (sentence == 4) {
        phrase = "bandoot known hacker";
    }
    if (sentence == 5) {
        phrase = "you better not be going to play a cametek map";
    }
    if (sentence == 6) {
        phrase = "you better be going to play a cametek map";
    }
    if (sentence == 7) {
        phrase = "JD is sad";
    }
    if (sentence == 8) {
        phrase = "ur mom says Hi.";
    }
    if (sentence == 9) {
        phrase = "ANOMALY DETECTED. BANGING UR MOM.";
    }
    if (sentence == 10) {
        phrase = "hee hee";
    }
    if (sentence == 11) {
        phrase = "the tiny little piece on the quest 2 strap broke ;-;";
    }
    if (sentence == 12) {
        phrase = "sugma";
    }
    if (sentence == 13) {
        phrase = "sugma is a bitch";
    }
    if (sentence == 14) {
        phrase = "Karen said she'd give me the kids back if you S'd the next song";
    }
    if (sentence == 15) {
        phrase = "about soulless 5...";
    }   
    if (sentence == 16) {
        phrase = "pp trash";
    }
    if (sentence == 17) {
        phrase = "acc trach";
    }
    if (sentence == 18) {
        phrase = "ur mom is proud of you";
    }
    if (sentence == 19) {
        phrase = "glad to see you've gotten off twitter";
    }
    if (sentence == 20) {
        phrase = "doot doot";
    }
    if (sentence == 21) {
        phrase = "E A SPORTS!";
    }
    if (sentence == 22) {
        phrase = "It's in the game";
    }
    if (sentence == 23) {
        phrase = "I'm not a fan of you";
    }
    if (sentence == 24) {
        phrase = "Acc trash";
    }
    if (sentence == 25) {
        phrase = "Furries are a major part of the IT industry";
    }
    if (sentence == 26) {
        phrase = "You should also try beats and shapes";
    }
    if (sentence == 27) {
        phrase = "New york is from New York";
    }
    if (sentence == 28) {
        phrase = "Goodbye America, hello New York";
    }
    if (sentence == 29) {
        phrase = "Also try MoonRider.xyz";
    }
    if (sentence == 30) {
        phrase = "What day is it";
    }
    if (sentence == 31) {
        phrase = "100 Percent Goose free";
    }
    if (sentence == 32) {
        phrase = "Come on, how hard could making it cross platform be?";
    }
    if (sentence == 33) {
        phrase = "Just hit the bloq, It’s really easy";
    }
    if (sentence == 34) {
        phrase = "Having an issue? Ask in #quest-help";
    }
    if (sentence == 35) {
        phrase = "Having an issue? Don’t";
    }
    if (sentence == 36) {
        phrase = "Why is New York called New York";
    }
    if (sentence == 37) {
        phrase = "dope ass game - XBOX magazine";
    }
    if (sentence == 38) {
        phrase = "Get Gud";
    }
    if (sentence == 39) {
        phrase = "[Quest] Noodle Extensions";
    }
    if (sentence == 40) {
        phrase = "Too many weeks";
    }
    if (sentence == 41) {
        phrase = "wHy DiD tHe DeVs BrEaK mOdS aGaIn";
    }
    if (sentence == 42) {
        phrase = "It's a game!";
    }
    if (sentence == 43) {
        phrase = "my mother stole my homework";
    }
    if (sentence == 44) {
        phrase = "peepoDuck";
    }
    if (sentence == 45) {
        phrase = "pink cute eris cute goobie cute scad";
    }
    if (sentence == 46) {
        phrase = "wdym my spelling is corect(edited)";
    }
    if (sentence == 47) {
        phrase = "anomaly detected. Banging you're mom";
    }
    if (sentence == 48) {
        phrase = "anomaly detected, doin ur mom";
    }
    if (sentence == 49) {
        phrase = "how do i get noodle extensions(edited)";
    }
    if (sentence == 50) {
        phrase = "cyan is a furry";
    }
    if (sentence == 51) {
        phrase = "chroma NOT included";
    }
    if (sentence == 52) {
        phrase = "Supports Noozle Extensions";
    }
    if (sentence == 53) {
        phrase = "#quest-help";
    }
    if (sentence == 54) {
        phrase = "SaberFactory";
    }
    // Use potential phrases here
    if (sentence == 55) {
        phrase = "Heqq";
    }
    if (sentence == 56) {
        phrase = "wen BMBF???";
    }
    if (sentence == 57) {
        phrase = "BMBF";
    }
    if (sentence == 58) {
        phrase = "william LGBTQ+ (in anime)";
    }




    if(firstActivation){
        text = BeatSaberUI::CreateText(self->get_transform(), phrase);

        text->get_transform()->set_localPosition({ 15.0f, 150.0f, 360.0f });
        text->get_transform()->set_localScale({ 4.0f, 4.0f, 4.0f });

    } else {

    }
}

void LaunchQuotes::Hooks::MainMenuViewController() {
  INSTALL_HOOK(getLogger(), MainMenuViewController_DidActivate);
}