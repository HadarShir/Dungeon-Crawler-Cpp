#ifndef ENTITY_H
#define ENTITY_H
#include <string>

// The Entity class represent a character in the game
class Entity {
    std :: string name;  // name of character
    int maxLife; // max life of character

protected:
    int currLife; // current life of character
    int damage;  // amount of damage

public:
    // Constructor for Entity (creates a new character)
    Entity(std::string name, int maxLife, int damage);

    // Copy constructor (creates a copy of another Entity)
    Entity(const Entity& other);

    //  Operator += (adds life to the character)
    Entity& operator+=(int life);

    // Operator -= (subtracts damage from the character)
     Entity& operator-=(int damage);

    // Operator -= (subtracts curr life from another Entity damage)
    virtual Entity& operator-=( Entity& other)=0;

    // Assignment operator
     Entity& operator=(const Entity& other);

    // Comparison operator (compares if two Entities are equal)
    bool operator==(const Entity& other) const;

    // Comparison operator (compares if one Entity is greater than another based on life and damage)
    bool operator>(const Entity& other) const;

    // Getter functions
    int getMaxLife() const;
    int getCurrLife() const ;
    // Setter functions
    void setLife(int life);


    // Getter for the damage (virtual for polymorphism)
    virtual int getDamage(Entity& e) const = 0;
    // Getter for the  name (virtual for polymorphism)
    virtual std::string getName() const = 0;

    //Destructor – cleans up any allocated memory (if needed)
    virtual ~Entity();

    // Friend function to allow easy printing of an Entity
    friend std::ostream& operator<<(std::ostream& os, const Entity& other);
};

#endif