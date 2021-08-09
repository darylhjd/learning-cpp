#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <string_view>

class Monster {
public:
    enum Type {
        Dragon,
        Goblin,
        Ogre,
        Orc,
        Skeleton,
        Troll,
        Vampire,
        Zombie,
        max_monster_types,
    };

private:
    Type type{};
    std::string name{};
    std::string roar{};
    int hit_points{};

public:
    Monster(Type type, const std::string& name, const std::string& roar, int hit_points);

    // Get the monster type as a string.
    std::string_view get_type_string() const;
    // Print monster.
    void print() const;
};

#endif