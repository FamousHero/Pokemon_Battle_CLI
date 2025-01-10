#include <string>
// Created based off info in pokedex not vice-versa
#include "Pokedex.h"

class Pokemon {

private:
	Stats m_stats;
	const std::string m_name;

public:
	Pokemon(std::string name, Stats stats)
		: m_name(name), m_stats(stats);
	~Pokemon();
	float getHealth() { return s_stats.m_health};
	float getSpeed() { return m_status.m_speed};

	float setHealth(float damage, Attack_Type attack_type);
	bool isAlive();
};
