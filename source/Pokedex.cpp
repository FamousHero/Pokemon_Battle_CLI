#include "../include/Pokedex.h"

Pokedex::Pokedex() {

}

Pokedex::~Pokedex() {

}

void Pokedex::CreatePokedex() {
	//Open Pokemon.csv, get the name
}

bool Pokedex::Search(std::string name) {
	if (auto requested_pokemon = this->m_pokedex[name]; requested_pokemon != this->m_pokedex.end()) {
		return true;
	}
	return false;
}