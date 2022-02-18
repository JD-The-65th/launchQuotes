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

#include "custom-json-data/shared/JSONWrapper.hpp"

using namespace QuestUI;
using namespace UnityEngine;
using namespace UnityEngine::UI;
using namespace GlobalNamespace;



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
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "every single night im on rule 34, beating my dick to some anime whore"
};

std::string randomQuote() {
    quotePool = quotePool + loadFromJson();
    int index = rand() % quotePool.size();
    return quotePool[index];
}

// Create a function to save a quote to a json file

void saveToJson(std::string quote)
{
    // Create a new document
    rapidjson::Document doc;
    doc.SetObject();

    // Create a new value
    rapidjson::Value value(rapidjson::kStringType);
    value.SetString(quote.c_str(), doc.GetAllocator());

    // Add the value to the document
    doc.AddMember("quote", value, doc.GetAllocator());

    // Create a string stream
    std::stringstream ss;

    // Create a writer
    rapidjson::Writer<std::stringstream> writer(ss);

    // Write the document to the stream
    doc.Accept(writer);

    // Get the string from the stream
    std::string json = ss.str();

    // Save the string to a file
    std::ofstream file("quotes.json");
    file << json;
    file.close();
    getLogger().info("Quote saved to json");
}

// make a function to load the quotes from the json file

std::array<std::string, 10> loadFromJson()
{
    // Create a new document
    rapidjson::Document doc;

    // Create a string stream
    std::stringstream ss;

    // Load the file
    std::ifstream file("quotes.json");

    // Put the file into the string stream
    ss << file.rdbuf();

    // Close the file
    file.close();

    // Parse the string stream
    doc.Parse(ss.str().c_str());

    // Create an array to hold the quotes
    std::array<std::string, 10> quotes;

    // Loop through the quotes
    for (int i = 0; i < 10; i++)
    {
        // Get the quote
        quotes[i] = doc["quote"].GetString();
    }

    // Return the quotes
    getLogger().info("Quotes Returned.");
    return quotes;
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

    
    




    if(firstActivation){
        saveToJson("Let's try this...");
        text = BeatSaberUI::CreateText(self->get_transform(), randomQuote());

        text->get_transform()->set_localPosition({ 15.0f, 150.0f, 360.0f });
        text->get_transform()->set_localScale({ 4.0f, 4.0f, 4.0f });

    } else {

    }
}

void LaunchQuotes::Hooks::MainMenuViewController() {
  INSTALL_HOOK(getLogger(), MainMenuViewController_DidActivate);
}