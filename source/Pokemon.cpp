#include "../include/Pokemon.h"

Pokemon::Pokemon(std::string name, Stats stats) {

}

Pokemon::~Pokemon() {

}

float Pokemon::setHealth(float damage, Attack_Type attack_type)
{
	this->m_stats.m_health -= damage;
	return this->m_stats.m_health;
}

bool Pokemon::isAlive() {
	if this->m_stats.m_health <= 0.0f{
		return false;
	}
	return true;
}