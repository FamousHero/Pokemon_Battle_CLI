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
	// Attack_Type m_attack_type;
	float m_power;
	float m_crit_multiplier;
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
	// Maybe return references to avoid copy but
	// "C++ return optimization" might already do it
	// test w/ debugger
	std::vector<std::string> SplitString(const std::string& line, char delimiter);
	Stats CreatePokemonStats(const std::vector<std::string>& pokemon_info);
	Move CreatePokemonMove(const std::vector<std::string>& move_info);
	void GenerateAllPokemonMoves(std::vector<Move>& pokemon_move_vector, const std::string& pokemon_id);
	void PrintPokedexEntry(const std::string& entry_name);
private:
	std::unordered_map<std::string, Stats> m_pokedex;

};