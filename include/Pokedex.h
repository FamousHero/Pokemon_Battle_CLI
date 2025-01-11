#include <string>
#include <vector>
#include <unordered_map>

enum class Attack_Type {
	NORMAL,
	FIGHTING,
	FLYING,
	POISION,
	GROUND,
	ROCK,
	BUG,
	GHOST,
	STEEL,
	FIRE,
	WATER,
	GRASS,
	ELECTRIC,
	PSYCHIC,
	ICE,
	DRAGON,
	DARK,
	FAIRY,
	UNKNOWN,
	SHADOW,

};

struct Move {
	std::string m_name;
	Attack_Type m_attack_type;

	float m_damage;
};
struct Stats {
	float m_health;
	float m_speed;
	std::vector<Move> m_moves;
};

class Pokedex {
public:
	Pokedex();
	~Pokedex();
	void CreatePokedex();
	bool Search(std::string name);

private:
	std::unordered_map<std::string, Stats> m_pokedex;

};