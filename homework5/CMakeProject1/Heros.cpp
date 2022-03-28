// CMakeProject1.cpp: определяет точку входа для приложения.
//

#include "CMakeProject1.h"

using namespace std;

class Hero {

private:
	const string name;
	int health;
	const int strength;
public:
	Hero(const string& str, int hp, int st) : name(str), health(hp), strength(st) {}
	~Hero() {};
	void strike(Hero& OtherHero) {
		OtherHero.health -= strength;
	}
	bool is_alive() {
		if (health > 0)
			return true;
		else {
			cout << "Hero " << name << " is defeated!";
			return false;
		}
		
	}
};

int main()
{
	Hero Garrosh("Garrosh", 100, 10);
	Hero Valira("Valira", 50, 25);
	while (Garrosh.is_alive() && Valira.is_alive()) {
		Valira.strike(Garrosh);
		Garrosh.strike(Valira);
	}
	return 0;
}
