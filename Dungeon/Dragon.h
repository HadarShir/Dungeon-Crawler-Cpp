
#ifndef DRAGON_H
#define DRAGON_H
#include "Monster.h"
#include "Player.h"

// Dragon class inherits from Monster, representing a dragon enemy in the game.
class Dragon : public Monster {
public:
    // Constructor: Initializes the dragon's name, maximum life, and damage.
    Dragon(std::string name, int maxLife, int damage);
    // Returns the name of the monster (always "Dragon").
    virtual std::string getName() const ;
    // Overloaded operator to handle interaction with another entity.
    virtual Entity& operator-=( Entity& other);
    // Calculates damage based on the player type.
    virtual int getDamage( Entity& player) const ;
    // Destructor for Dragon class.
    virtual ~Dragon();
};
#endif //DRAGON_H
