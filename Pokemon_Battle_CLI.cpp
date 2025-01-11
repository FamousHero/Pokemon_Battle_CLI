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

//std::unordered_set<std::string> CreatePokedex() {
//	std::ifstream pokemon("pokemon.csv");
//	std::ifstream pokemon_stats("pokemon_stats.csv");
//	
//	std::string line;
//	while(pokemon.good()) {
//		std::getline(pokemon, line);
//		std::cout << line << "\n";
//	}
//	std::cout << std::flush;
//	std::unordered_set<std::string> test_pokedex{"test", "pokedex"};
//	pokemon.close();
//	return test_pokedex;
//
//}

void PrintPokemonWithMove(std::string& move, Pokedex& pokedex) {
	std::cout << "--------------\nYour next move is: " << move << std::endl;
	int matches = 0;
	for (auto pokemon : pokedex.m_pokedex) {
		for (auto possible_match : pokemon.second.m_moves) {
			if (possible_match.m_name == move) {
				std::cout << "\t" << pokemon.first << " has "
					<< move << "\n";
				++matches;
			}
		}
	}
	std::cout << "total pokemon with move: " << matches
		<< "\n--------------" << std::endl;
}
void GameLoop() {
	bool running = true;
	std::cout << "Creating Pokedex" << std::endl;
	Pokedex pokedex;
	pokedex.CreatePokedex();
	while (running) {
		std::string next_move = "exit";
		std::cout << "Please type your next move(\"exit\" to exit)\n" << std::endl;
		std::cin >> next_move;
		if (next_move == "exit") {
			std::cout << "No move selected, Game will terminate" << std::endl;
			return;
		}
		PrintPokemonWithMove(next_move, pokedex);
	}
}


int main()
{
	std::cout << "Hello CMake. " << std::endl;
	std::cout << "Starting from day 1" << std::endl;
	GameLoop();

	return 0;
}
