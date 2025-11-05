#include "Room.h"
#include "GameException.h"
#include <iostream>
#include <utility>

// Constructor to initialize a room with the specified attributes
Room::Room(std::string  RoomName, int campfireHeal, int monsterLife, int monsterDamage,char monsterType, bool hasMonster):
     RoomName(std::move(RoomName)), campfireHeal(campfireHeal),monsterType(monsterType),hasMonster(hasMonster) {
    this->numConnectedRooms = 0;
    // create the monster
    if (hasMonster) {
        try {  // raise error if needed
            if ((monsterType == 'D')) {
                monster = new Dragon("Dragon",monsterLife,monsterDamage);
            } else if((monsterType == 'G')){
                monster = new Goblin("Goblin",monsterLife,monsterDamage);
            }
        }catch(const std::bad_alloc&) {  // problem in new
            throw MemoryException();
        }
    }else{
        if ((monsterType != 'N')){
            throw ValueException();
        }
    }
}

// Copy constructor to create a new room by copying an existing room
Room::Room(const Room &otherRoom)
    : RoomName(otherRoom.RoomName),campfireHeal(otherRoom.campfireHeal),numConnectedRooms(otherRoom.numConnectedRooms),
    monsterType(otherRoom.monsterType),hasMonster(otherRoom.hasMonster) {
    // If the room has connected rooms, we need to copy them
    if (otherRoom.hasMonster) {
        try {
            if ((otherRoom.monsterType == 'D')) {
                monster = new Dragon(*dynamic_cast<Dragon*>(otherRoom.monster));
            } else if((otherRoom.monsterType == 'G')){
                monster = new Goblin(*dynamic_cast<Goblin*>(otherRoom.monster));
            }
        }catch(const std::bad_alloc&) {
            throw MemoryException();
        }
    }else{
        if ((monsterType != 'N')){
            throw ValueException();
        }
    }
    connectedRooms.reserve(otherRoom.connectedRooms.size());
    for (Room* room : otherRoom.connectedRooms) {
        if (room!=nullptr) {
            connectedRooms.push_back(room);
        }else {
            connectedRooms.push_back(nullptr);
        }
    }
}

// Destructor that frees allocated memory for connected rooms
Room::~Room() {
    for (Room* room : connectedRooms) {
        delete room;
    }
    delete monster;
}

// Checks if the room has no connected rooms
bool Room::isEmptyArray() const {
    return connectedRooms.empty();
}

// Index operator to access connected rooms (read-only)
Room* Room::operator[](int index) const {
    if(index >= 0 && index < connectedRooms.size()) {
        return connectedRooms[index];
    }
    throw RoomException(); // Return nullptr if index is invalid
}

// Index operator to assign connected rooms
Room* Room::operator[](int index) {
    if(index >= 0 && index < connectedRooms.size()) {
        return connectedRooms[index];
    }
    throw RoomException(); // Return nullptr if index is invalid
}

// Assignment operator to copy a room's attributes
Room& Room::operator=(const Room& otherRoom) {
    if (this != &otherRoom) {// If it's self-assignment, just return the same object
        Room temp(otherRoom);
        std::swap(*this, temp);
    }
   return *this;
}

// Getter function
std::string Room::getRoomName() const {
    return RoomName;
}

int Room::getCampfireHeal() const {
    return campfireHeal;
}

int Room::getSizeConnectedRooms() const {
    return connectedRooms.size();
}


bool Room::getHasMonster() const {
    return hasMonster;
}

 Monster & Room::getMonster() const {
    return *monster;
}

// Adds a connected room at a specified index
void Room::addConnectedRoom(Room *newRoom, int index) {
    // If the room index is beyond the current array size, we need to resize the array
    if (index >= connectedRooms.size()) {
        connectedRooms.resize(index + 1, nullptr);// Initialize new rooms to nullptr if needed
    }

    if (connectedRooms[index] != nullptr) {
        delete connectedRooms[index]; // Delete any room that was previously at the index
    }
    // Add the new room at the specified index
    connectedRooms[index]=newRoom;
    numConnectedRooms++; // Increment the number of connected rooms

}


// Friend function to print room details  -  for DEBUG
std::ostream& operator<<(std::ostream& os, const Room& room) {
    os << "Room Name: " << room.RoomName << "\n"
       << "Campfire Heal: " << room.campfireHeal << "\n"
       << "Has Monster: " << (room.hasMonster ? "Yes" : "No") << "\n"
       << "Connected Rooms: " << room.numConnectedRooms;
    return os;
}

