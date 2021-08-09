#include "monster.h"
#include <string>
#include <string_view>
#include <iostream>

Monster::Monster(Monster::Type type, const std::string& name, const std::string& roar, int hit_points)
    : type{type}, name{name}, roar{roar}, hit_points{hit_points}
{}

std::string_view Monster::get_type_string() const {
    switch (type) {
    case Dragon:
        return "Dragon";
    case Goblin:
        return "Goblin";
    case Ogre:
        return "Ogre";
    case Orc:
        return "Orc";
    case Skeleton:
        return "Skeleton";
    case Troll:
        return "Troll";
    case Vampire:
        return "Vampire";
    case Zombie:
        return "Zombie";
    }
    return "???";
}

void Monster::print() const {
    std::cout << name << " the " << get_type_string() << " has "
    << hit_points << " hit points and says " << roar << '\n';
}