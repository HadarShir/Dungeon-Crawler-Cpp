#ifndef ROOM_H
#define ROOM_H
#include "Dragon.h"
#include "Goblin.h"
#include <vector>
#include <string>

// The Room class represents a room in the game that may contain monsters and connected rooms.
class Room {
private:
    std::string RoomName;  // The name of the room
    int campfireHeal;  // Amount of health the player can heal if they rest by the campfire
    int numConnectedRooms;  // Number of connected rooms
    std::vector<Room*> connectedRooms;  // Array of pointers to connected rooms
    Monster *monster = nullptr;  // Monster present in the room
    char monsterType; // represent the Monster type that we need to create
    bool hasMonster;  // Flag indicating whether the room has a monster

public:
    // Constructor that initializes a room with the given parameters
    Room(std::string  RoomName, int campfireHeal, int monsterLife, int monsterDamage,char monsterType, bool hasMonster);

    // Copy constructor for creating a copy of another room
    Room(const Room& otherRoom);

    // Destructor to release allocated memory
    ~Room();

    // Checks if the room has no connected rooms
    bool isEmptyArray() const;

    // Index operator to access connected rooms
    Room* operator[](int index) const;

    // Index operator to assign connected rooms
    Room* operator[](int index);

    // Assignment operator to copy a room's data
    Room& operator=(const Room& otherRoom);

    // Getter functions
    std::string getRoomName() const;
    int getCampfireHeal() const;
    int getSizeConnectedRooms() const;
    bool getHasMonster() const;
    Monster& getMonster() const;

    // Friend function to allow printing room details to the output -  for DEBUG
    friend std::ostream& operator<<(std::ostream& os, const Room& room);

    // Adds a new connected room to the current room at a specified index
    void addConnectedRoom(Room* newRoom, int index);

};
#endif