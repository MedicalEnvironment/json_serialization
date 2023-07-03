#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    // Create a JSON object to hold the movie information
    json movieJson;

    // Add the movie details
    movieJson["title"] = "Source Code";
    movieJson["country"] = "United States";
    movieJson["release_date"] = "2011-04-01";
    movieJson["studio"] = "Vendome Pictures";
    movieJson["scriptwriter"] = "Ben Ripley";
    movieJson["director"] = "Duncan Jones";
    movieJson["producer"] = "Mark Gordon";

    // Create a JSON array for main characters
    json charactersJson;

    // Add the information for each character
    json character1;
    character1["name"] = "Captain Colter Stevens";
    character1["actor"] = "Jake Gyllenhaal";

    json character2;
    character2["name"] = "Christina Warren";
    character2["actor"] = "Michelle Monaghan";

    json character3;
    character3["name"] = "Dr. Rutledge";
    character3["actor"] = "Jeffrey Wright";

    // Add the characters to the array
    charactersJson.push_back(character1);
    charactersJson.push_back(character2);
    charactersJson.push_back(character3);

    // Add the characters array to the movie JSON
    movieJson["characters"] = charactersJson;

    // Save the JSON document to a file
    std::ofstream outputFile("source_code.json");
    outputFile << movieJson.dump(4);  // dump(4) for pretty formatting
    outputFile.close();

    std::cout << "JSON document created successfully." << std::endl;

    return 0;
}
