#include <string>
#include "Room.h"
#include "Fighter.h"
#include "Sorcerer.h"
#include <iostream>
#include "Game.h"
#include "GameException.h"

int main( int argc, char* argv[]) {
    // Check if enough arguments were passed to the program.
    if(argc<5) {  // valid of argc
        return 1;
    }
    // Parse command-line arguments.
    char *type = argv[1];  // Player type (Fighter or Sorcerer).
    int life = atoi(argv[2]);    // Convert the first argument (player life) to an integer
    int damage = atoi(argv[3]);  // Convert the second argument (player damage) to an integer
    std::string path = argv[4];  // Get the path to the configuration file from the third argument
    Player *player=nullptr;

        try {
            // Check for invalid life or damage values.
            if (life<0) throw ValueException();
            if (damage<0) throw ValueException();

            // Create the player Entity with the parsed life, damage, and the name "Player"
            try{
            if(*type=='F') {
                player = new Fighter("Player",life,damage);
            } else if(*type=='S') {
                player = new Sorcerer("Player",life,damage);

            } else{
                throw ValueException();  // Invalid player type.
                exit(1);
            }
            } catch(const std::bad_alloc&) { // Handle memory allocation failure.
            throw MemoryException();
        }

            // Create a Game instance and initialize it with the player
            Game game{player};
            // Initialize the game using the configuration file
            game.initializeGame(path);

            // Run the game if initialization was successful
            game.runGame();
        } catch (const GameException& e) {
            delete player; // Clean up allocated memory on exception.
                std::cout << e.what() << std::endl;
                return 1;
        } catch (...) { // Handle any unknown exceptions.
            delete player; // Clean up allocated memory on exception.
            std::cout << "Unknown error occurred" << std::endl;
            return 1;
        }
        // Clean up allocated memory after the game ends.
        delete player;
        return 0;
}
