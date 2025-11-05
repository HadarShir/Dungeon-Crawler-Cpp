
#ifndef GOBLIN_H
#define GOBLIN_H
#include "Monster.h"
#include "Player.h"

// Goblin class inherits from Monster, representing a goblin enemy in the game.
class Goblin : public Monster {
public:
    // Constructor: Initializes the goblin's name, maximum life, and damage.
    Goblin(std::string name, int maxLife, int damage);
    // Returns the name of the monster (always "Goblin").
    virtual std::string getName() const ;
    // Operator -= – subtracts damage from another Entity ( another character's damage reduces the current character's life)
    virtual Entity& operator-=( Entity& other);
    // Calculates damage based on the player type.
    virtual int getDamage(Entity& player) const ;
    // Destructor for Goblin class.
    virtual ~Goblin();
};
#endif //GOBLIN_H
