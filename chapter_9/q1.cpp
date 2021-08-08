#include <iostream>
#include <string>

enum class MonsterType {
    ogre,
    dragon,
    orc,
    giant_spider,
    slime,
};

struct Monster {
    std::string name{};
    int health{};
    MonsterType m_type{};
};

void printMonster(Monster monster) {
    std::string m_type{};
    switch (monster.m_type) {
    case MonsterType::ogre:
        m_type = "Ogre";
        break;
    case MonsterType:: dragon:
        m_type = "Dragon";
        break;
    case MonsterType::orc:
        m_type = "Orc";
        break;
    case MonsterType::giant_spider:
        m_type = "Giant Spider";
        break;
    case MonsterType::slime:
        m_type = "Slime";
        break;
    default:
        m_type = "Unknown Monster";
        break;
    }

    std::cout << "This " << m_type << " is named " << monster.name 
    << " and has " << monster.health << " health.\n";
}

int main() {
    Monster torg{"Torg", 145, MonsterType::ogre};
    Monster slime{"Slime", 23, MonsterType::slime};
    printMonster(torg);
    printMonster(slime);
}