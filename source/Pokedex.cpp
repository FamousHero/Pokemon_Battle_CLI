#include <fstream>
#include <iostream>
#include "../include/Pokedex.h"
#include <cinttypes>

Pokedex::Pokedex() {

}

Pokedex::~Pokedex() {

}

void Pokedex::CreatePokedex() {
	std::ifstream pokemon_file("pokemon.csv");
	
	std::string pokemon;
	std::getline(pokemon_file, pokemon); //first line column titles
	while (pokemon_file.good()) {
		std::getline(pokemon_file, pokemon);
		std::vector<std::string> pokemon_tokens = this->SplitString(pokemon, ',');
		
		//Does function copy Stats struct or move
		//Maybe add move semantics to `Stats` constructor
		//that way vector of moves created first then stats passed the vector
		//that way no need to copy one vector to the other
		Stats p_stats = CreatePokemonStats(pokemon_tokens);
		this->GenerateAllPokemonMoves(p_stats.m_moves, pokemon_tokens[0]);
		

		m_pokedex[pokemon_tokens[1]] = p_stats;
		std::cout << "Pokedex entry created" << std::endl;
		this->PrintPokedexEntry(pokemon_tokens[1]);
	}

}

bool Pokedex::Search(std::string name) {
	if (auto requested_pokemon = this->m_pokedex.find(name); requested_pokemon != this->m_pokedex.end()) {
		return true;
	}
	return false;
}

std::vector<std::string> Pokedex::SplitString(const std::string& line, char delimiter) {
	uint32_t last = 0;
	std::vector<std::string> split_string;
	for (uint32_t i = 0; i != line.size(); i++) {
		if (line[i] == delimiter) {
			split_string.push_back(line.substr(last, i-last));
			last = i+1;
		}
	}
	split_string.push_back(line.substr(last));
	return  split_string;
}

Stats Pokedex::CreatePokemonStats(const std::vector<std::string>& pokemon_info)
{
	Stats pokemon_stats;
	pokemon_stats.m_health = std::stof(pokemon_info[2]);
	pokemon_stats.m_speed = std::stof(pokemon_info[3]);
	return pokemon_stats;
}

Move Pokedex::CreatePokemonMove(const std::vector<std::string>& move_info)
{
	Move p_move;
	p_move.m_name = move_info[1];
	p_move.m_power = std::stof(move_info[2]);
	p_move.m_crit_multiplier = std::stof(move_info[3]);

	return p_move;
}

void Pokedex::GenerateAllPokemonMoves(std::vector<Move>& pokemon_move_vector, const std::string& pokemon_id)
{
	std::ifstream pokemon_move_file("pokemon_moves.csv");
	std::string pokemon_move;
	while (pokemon_move_file.good()) {
		std::getline(pokemon_move_file, pokemon_move);
		std::vector<std::string> move_tokens = this->SplitString(pokemon_move, ',');
		if (pokemon_id == move_tokens[0]) {

			Move move_entry = this->CreatePokemonMove(move_tokens);
			pokemon_move_vector.push_back(move_entry);
		}
	}
}

void Pokedex::PrintPokedexEntry(const std::string& entry_name)
{
	std::cout << entry_name << ": hp="
		<< m_pokedex[entry_name].m_health << " speed="
		<< m_pokedex[entry_name].m_speed << " moves=\n";
	for (auto it : m_pokedex[entry_name].m_moves) {
		std::cout << "\tMove Name=" << it.m_name << " Power="
			<< it.m_power << "Crit *=" << it.m_crit_multiplier << "\n";
	}
}
