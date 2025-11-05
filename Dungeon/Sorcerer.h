

#ifndef SORCERER_H
#define SORCERER_H
#include "Player.h"

// Sorcerer class inherits from Player, representing a magic user with special abilities.
class Sorcerer : public Player {
    public:
    // Constructor: Initializes the sorcerer with its name, maximum life, and damage.
    Sorcerer(std::string name, int maxLife, int damage);

    // Returns the name of the player type (always "Sorcerer").
    virtual std::string getName() const;
    // Calculates the damage dealt to a monster.
    virtual int getDamage(Entity & monster) const;
    // Returns the damage multiplier for the sorcerer's special ability.
    virtual int getSpecialDamage() {return 2*damage;};
    // Operator -= – subtracts damage from another Entity ( another character's damage reduces the current character's life)
    virtual Entity& operator-=( Entity& other);
    // Checks if the sorcerer's special ability can be activated.
    bool CanUseSpecial();

    // Returns the damage modifier when fighting a dragon.
    virtual double getDamageModeDragon() const { return 2.0;}
    // Returns the damage modifier when fighting a goblin.
    virtual double getDamageModeGoblin() const { return 0.5;}

    // Destructor for Sorcerer class.
    virtual ~Sorcerer();
};
#endif //SORCERER_H
