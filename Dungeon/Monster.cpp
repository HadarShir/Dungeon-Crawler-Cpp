
#include "Monster.h"

// Constructor: Initializes the monster's name, maximum life, and damage.
Monster::Monster(std::string name, int maxLife, int damage)
    :Entity(std::move(name), maxLife, damage){}

Monster::~Monster() = default;
