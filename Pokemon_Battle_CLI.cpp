// Pokemon_Battle_CLI.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "include/Pokedex.h"

// Could store in a db but thats too complicated for rn
// Creating a hash set to live in RAM since its only 35kb
// Means file must be included with binary

// May make hash map with values being possible moves to 

std::unordered_set<std::string> CreatePokedex() {
	std::ifstream pokemon("pokemon.csv");
	std::ifstream pokemon_stats("pokemon_stats.csv");
	
	std::string line;
	while(pokemon.good()) {
		std::getline(pokemon, line);
		std::cout << line << "\n";
	}
	std::cout << std::flush;
	std::unordered_set<std::string> test_pokedex{"test", "pokedex"};
	pokemon.close();
	return test_pokedex;

}


void GameLoop() {
	bool running = true;
	std::unordered_set<std::string> pokedex = CreatePokedex();
	while (running) {
		std::string next_move = "none";
		std::cout << "Please type your next move" << std::endl;
		std::cin >> next_move;
		if (next_move == "none") {
			std::cout << "No move selected, Game will terminate" << std::endl;
			return;
		}
		std::cout << "Your next move is: " << next_move << std::endl;
	}
}


int main()
{
	std::cout << "Hello CMake." << std::endl;
	std::cout << "Starting from day 1" << std::endl;
	GameLoop();
	return 0;
}
