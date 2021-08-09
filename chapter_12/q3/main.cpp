#include "monster.h"
#include <random>

// Static class for generating a random monster.
class MonsterGenerator {
public:
    static Monster generate_monster() {
        return {
            Monster::Skeleton, "Bones", "*rattle*", 4
        };
    }

    static int get_random_number(int min, int max) {
        static constexpr double fraction{
            1.0 / (static_cast<double>(RAND_MAX) + 1.0)
        };
        return static_cast<int>(
            std::rand() * fraction * (max - min + 1) + min
            );
    }
};

int main() {
	Monster m{ MonsterGenerator::generate_monster() };
	m.print();
 
	return 0;
}