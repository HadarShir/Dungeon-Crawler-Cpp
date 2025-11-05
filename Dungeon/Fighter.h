
#ifndef FIGHTER_H
#define FIGHTER_H
#include "Player.h"

// Fighter class inherits from Player.
class Fighter : public Player {
public:
    // Constructor: Initializes the fighter's name, maximum life, and damage.
    Fighter(std::string name, int maxLife,int damage);

    // Returns the name of the player type (always "Fighter").
    virtual std::string getName() const;
    // Calculates the damage dealt to a monster.
    virtual int getDamage(Entity & monster) const;
    // Returns 0 damage for the fighter's special ability (no damage increase).
    virtual int getSpecialDamage() {return 0;}
    // Overloaded operator to handle interaction with another entity.
    virtual Entity& operator-=( Entity& other);
    // Checks if the fighter's special ability can be activated.
    bool CanUseSpecial();
    // Returns the damage modifier when fighting a dragon.
    virtual double getDamageModeDragon() const {return 0.5;}
    // Returns the damage modifier when fighting a goblin.
    virtual double getDamageModeGoblin() const {return  2.0;}
    // Destructor for Fighter class.
    virtual ~Fighter();
};














#endif //FIGHTER_H
