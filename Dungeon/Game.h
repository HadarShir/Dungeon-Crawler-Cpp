#ifndef GAME_H
#define GAME_H
#include <string>
#include "Room.h"
#include <iostream>
#include "GameException.h"
// The Game class manages the entire game flow, including the player and the rooms.
class Game {
private:
    Room* StartRoom;  // Pointer to the starting room
    Room* CurrRoom;  // Pointer to the current room the player is in
    Player *player;   // The player in the game
    bool isRunning;  // Flag indicating whether the game is running
    bool first_round; // Flag for first round

    // Checks if the current room is empty (has no connected rooms)
    bool CheckIfRoomIsEmpty() const;

    // Manages the fight process
    void fight();

    // Handles moving between rooms
    void MoveRoom();

    // Determines if the player has won the game
    bool WinTheGame();

public:
    // Constructor that initializes the game with a player entity
    Game( Player* player); // Initial room is empty (not connected yet)

    // Destructor
    ~Game();

    // Initializes the game by reading room data from a configuration file
    void initializeGame(const std::string& confiFile) const;
    // Starts the game loop
    void runGame();


};
#endif