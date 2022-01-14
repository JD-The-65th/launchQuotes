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

    if (sentence == 0) {
        std::string phrase = "BMBF WHEN";
    }
    if (sentence == 1) {
        std::string phrase = "BMBF NOW";
    }
    if (sentence == 2) {
        std::string phrase = "Just like in minecraft!";
    }
    if (sentence == 3) {
        std::string phrase = "ew u stink";
    }
    if (sentence == 4) {
        std::string phrase = "bandoot known hacker";
    }
    if (sentence == 5) {
        std::string phrase = "you better not be going to play a cametek map";
    }
    if (sentence == 6) {
        std::string phrase = "you better be going to play a cametek map";
    }
    if (sentence == 7) {
        std::string phrase = "JD is sad";
    }
    if (sentence == 8) {
        std::string phrase = "ur mom says Hi.";
    }
    if (sentence == 9) {
        std::string phrase = "ANOMALY DETECTED. BANGING UR MOM.";
    }
    if (sentence == 10) {
        std::string phrase = "hee hee";
    }
    if (sentence == 11) {
        std::string phrase = "the tiny little piece on the quest 2 strap broke ;-;";
    }
    if (sentence == 12) {
        std::string phrase = "sugma";
    }
    if (sentence == 13) {
        std::string phrase = "sugma is a bitch";
    }
    if (sentence == 14) {
        std::string phrase = "Karen said she'd give me the kids back if you S'd the next song";
    }
    if (sentence == 15) {
        std::string phrase = "about soulless 5...";
    }   
    if (sentence == 16) {
        std::string phrase = "pp trash";
    }
    if (sentence == 17) {
        std::string phrase = "acc trach";
    }
    if (sentence == 18) {
        std::string phrase = "ur mom is proud of you";
    }
    if (sentence == 19) {
        std::string phrase = "glad to see you've gotten off twitter";
    }
    if (sentence == 20) {
    std::string phrase = "doot doot";
    }
    if (sentence == 21) {
        std::string phrase = "E A SPORTS!";
    }
    if (sentence == 22) {
        std::string phrase = "It's in the game";
    }
    if (sentence == 23) {
        std::string phrase = "I'm not a fan of you";
    }
    if (sentence == 24) {
        std::string phrase = "If furries decided to turn off their phones for one day, the Internet would literally crumble";
    }
    if (sentence == 25) {
        std::string phrase = "Furries are a major part of the IT industry";
    }
    if(firstActivation){
        text = BeatSaberUI::CreateText(self->get_transform(), phrase);

        text->get_transform()->set_localPosition({ 0.0f, -40.0f, 0.0f });
    } else {

    }
}

void LaunchQuotes::Hooks::MainMenuViewController() {
  INSTALL_HOOK(getLogger(), MainMenuViewController_DidActivate);
}