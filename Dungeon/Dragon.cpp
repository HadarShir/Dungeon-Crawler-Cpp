

#include "Dragon.h"
#include <cmath>

// Constructor: Initializes the dragon's name, maximum life, and damage.
Dragon::Dragon(std::string name, int maxLife, int damage)
    :Monster(std::move(name), maxLife, damage){}

// Returns the name of the dragon.
std::string Dragon::getName() const {
    return "Dragon";
}

// Operator -= – subtracts damage from another Entity ( another character's damage reduces the current character's life)
Entity & Dragon::operator-=(Entity &other) {
    // We will convert the character into a player type knowing that in a monster game you always fight against a player
     Player* playerPtr = dynamic_cast<Player*>(&other);
    if (playerPtr) {
        // We will check if the player in front of us has a special ability to use against us
        if (playerPtr->CanUseSpecial()) {
            int temp = playerPtr->getSpecialDamage();
            if (temp != 0) {
                this->currLife -= temp;
            } else {
                this->currLife-= other.getDamage(*this);
            }
        }
        else {
            this->currLife-= other.getDamage(*this);
        }
    }
    return *this;
}


// Calculate damage
int Dragon::getDamage(Entity &entity) const {
    // We will convert the character into a player type knowing that in a monster game you always fight against a player
    const Player* playerPtr = dynamic_cast<Player*>(&entity);
    if (playerPtr) {
        double res =  this->damage * playerPtr->getDamageModeDragon() ;
        return static_cast<int>(std::round(res));
    }
    return this->damage;
}

// Default destructor for Dragon class.
Dragon::~Dragon() = default;
