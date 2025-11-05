
#ifndef MONSTER_H
#define MONSTER_H
#include "Entity.h"

// Monster class inherits from Entity, representing a monster enemy in the game.
class Monster : public Entity {
public:
    // Constructor: Initializes the monster's name, maximum life, and damage.
    Monster(std::string name, int maxLife, int damage);

    // Overloaded operator for interaction between the monster and another entity.
    virtual Entity& operator-=( Entity& other)=0;
    // Calculates damage against a player
    virtual int getDamage(Entity& player) const = 0;
    // Destructor for the Monster class.
    virtual ~Monster();
};
#endif //MONSTER_H
