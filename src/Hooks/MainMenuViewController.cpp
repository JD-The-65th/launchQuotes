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
    return rand() % 25;
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
        phrase = "If furries decided to turn off their phones for one day, the Internet would literally crumble";
    }
    if (sentence == 25) {
        phrase = "Furries are a major part of the IT industry";
    }
    if(firstActivation){
        text = BeatSaberUI::CreateText(self->get_transform(), phrase);

        text->get_transform()->set_localPosition({ 0.0f, 65.0f, 360.0f });
        text->get_transform()->set_localScale({ 4.0f, 4.0f, 4.0f });
    } else {

    }
}

void LaunchQuotes::Hooks::MainMenuViewController() {
  INSTALL_HOOK(getLogger(), MainMenuViewController_DidActivate);
}