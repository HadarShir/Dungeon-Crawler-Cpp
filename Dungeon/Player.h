
#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"

// PLayer class inherits from Entity
class Player : public Entity {

protected:
    bool canActivate;  // Whether the special ability can be activated
    int turnCounter;  // Counter for turns until the ability can be used again

public:
    // Constructor: Initializes the players name maxlife and damage
    Player(std::string name, int maxLife, int damage) ;

    // Updates the turn counter after each turn.
    void updateTurnCounter();

    // Checks if the special ability can be used (implemented in derived classes).
    virtual bool CanUseSpecial()=0 ;
    // Virtual function for applying special ability damage (to be defined in derived classes).
    virtual int getSpecialDamage()  = 0;
    // Overloaded operator to handle interaction between the player and another entity.
    virtual Entity& operator-=( Entity& other)=0;

    // Determines the damage modifier when fighting a dragon (defined in derived classes).
    virtual double getDamageModeDragon() const = 0;
    // Determines the damage modifier when fighting a goblin (defined in derived classes).
    virtual double getDamageModeGoblin() const = 0;

    // Destructor for the Player class.
    virtual  ~Player();

};



#endif //PLAYER_H
