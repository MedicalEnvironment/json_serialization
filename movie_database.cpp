#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// Function to search for films and roles of an actor
void searchActor(const json& movieDatabase, const std::string& actorName) {
    std::cout << "Searching for actor: " << actorName << std::endl;

    // Iterate over each movie in the database
    for (const auto& [title, movie] : movieDatabase.items()) {
        // Check if the movie contains the actor
        for (const auto& character : movie["characters"]) {
            if (character["actor"] == actorName) {
                std::cout << "Film: " << title << ", Role: " << character["name"] << std::endl;
            }
        }
    }
}

int main() {
    // Create a JSON object to hold the movie database
    json movieDatabase;

    // Add movie information for "Source Code"
    json movie1;
    movie1["country"] = "United States";
    movie1["release_date"] = "2011-04-01";
    movie1["studio"] = "Vendome Pictures";
    movie1["scriptwriter"] = "Ben Ripley";
    movie1["director"] = "Duncan Jones";
    movie1["producer"] = "Mark Gordon";

    json characters1;
    json character1_1;
    character1_1["name"] = "Captain Colter Stevens";
    character1_1["actor"] = "Jake Gyllenhaal";
    characters1.push_back(character1_1);

    movie1["characters"] = characters1;
    movieDatabase["Source Code"] = movie1;

    //"Spider-Man 3"
    json movie2;
    movie2["country"] = "United States";
    movie2["release_date"] = "2007-05-04";
    movie2["studio"] = "Columbia Pictures";
    movie2["scriptwriter"] = "Sam Raimi";
    movie2["director"] = "Sam Raimi";
    movie2["producer"] = "Laura Ziskin, Avi Arad";
    
    json characters2;
    json character2_1;
    character2_1["name"] = "Peter Parker / Spider-Man";
    character2_1["actor"] = "Tobey Maguire";
    characters2.push_back(character2_1);
    
    movie2["characters"] = characters2;
    movieDatabase["Spider-Man 3"] = movie2;

    //"John Wick"
    json movie3;
    movie3["country"] = "United States";
    movie3["release_date"] = "2014-10-24";
    movie3["studio"] = "Thunder Road Pictures";
    movie3["scriptwriter"] = "Derek Kolstad";
    movie3["director"] = "Chad Stahelski";
    movie3["producer"] = "Basil Iwanyk, David Leitch";
    
    json characters3;
    json character3_1;
    character3_1["name"] = "John Wick";
    character3_1["actor"] = "Keanu Reeves";
    characters3.push_back(character3_1);
    
    movie3["characters"] = characters3;
    movieDatabase["John Wick"] = movie3;

    //"Warcraft"
    json movie4;
    movie4["country"] = "United States";
    movie4["release_date"] = "2016-06-10";
    movie4["studio"] = "Legendary Pictures";
    movie4["scriptwriter"] = "Charles Leavitt, Duncan Jones";
    movie4["director"] = "Duncan Jones";
    movie4["producer"] = "Thomas Tull, Jon Jashni, Charles Roven, Alex Gartner, Stuart Fenegan";

    json characters4;
    json character4_1;
    character4_1["name"] = "Anduin Lothar";
    character4_1["actor"] = "Travis Fimmel";
    characters4.push_back(character4_1);
    
    movie4["characters"] = characters4;
    movieDatabase["Warcraft"] = movie4;

    //"Steve Jobs"
    json movie5;
    movie5["country"] = "United States";
    movie5["release_date"] = "2015-10-23";
    movie5["studio"] = "Universal Pictures";
    movie5["scriptwriter"] = "Aaron Sorkin";
    movie5["director"] = "Danny Boyle";
    movie5["producer"] = "Scott Rudin, Danny Boyle, Christian Colson, Mark Gordon";
    
    json characters5;
    json character5_1;
    character5_1["name"] = "Steve Jobs";
    character5_1["actor"] = "Michael Fassbender";
    characters5.push_back(character5_1);
    
    movie5["characters"] = characters5;
    movieDatabase["Steve Jobs"] = movie5;

    // Save the JSON database to a file
    std::ofstream outputFile("movie_database.json");
    outputFile << movieDatabase.dump(4);
    outputFile.close();

    // Load the JSON database from the file
    std::ifstream inputFile("movie_database.json");
    json loadedDatabase = json::parse(inputFile);
    inputFile.close();

    // Search for an actor in the loaded database
    searchActor(loadedDatabase, "Jake Gyllenhaal");

    return 0;
}
