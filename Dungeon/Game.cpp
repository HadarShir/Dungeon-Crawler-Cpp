#include "Game.h"
#include <fstream>
#include <sstream>
#include <cctype>


// Constructor that initializes the game with a player entity and an empty starting room
Game::Game(Player* player) :StartRoom(new Room("",0,0,0,'N',false)),player(player),
     isRunning(true) , first_round(true) {
    CurrRoom = StartRoom;  // Set the current room to the starting room
}

// Destructor – delete the dynamically allocated StartRoom
Game::~Game() {
    if (StartRoom != nullptr) {
        delete StartRoom;
    }
}


// Game loop that runs the main game flow
void Game::runGame() {
    std::cout<< *player << std::endl; ;

    while (isRunning && player->getCurrLife() >0 ) {  // Game continues while player is alive
        if(CheckIfRoomIsEmpty()) {  // If the room is empty, move or win
            if(WinTheGame()) break;
            MoveRoom();   // Move to the next room
            continue;
        }

        // Heal the player if there's a campfire
        if(CurrRoom->getCampfireHeal() > 0) {
            *player += CurrRoom->getCampfireHeal();  // add life to player
            if (!first_round) player->updateTurnCounter();  // count the turn to decide if we can Activate the special ability
            std::cout<<"You sit by the campfire and heal " << CurrRoom->getCampfireHeal() <<" health"<<std::endl;
        }

        // If there's a monster, fight
        if(CurrRoom->getHasMonster()){
            fight();  // Fight the monster
            if(player->getCurrLife() == 0) break;   // Check if the player is dead after the fight
            if(WinTheGame()) break;   // Check if the player won after the fight
            MoveRoom();  // Move to the next room after the fight
            continue;

        } else {
            if(WinTheGame()) break;
            MoveRoom();  // Move to the next room if no monster is present
            continue;
        }
    }
}

// Checks if the current room is empty (no monster and no campfire healing)
bool Game::CheckIfRoomIsEmpty() const {
    if(CurrRoom->getCampfireHeal()==0 && CurrRoom->getHasMonster()==false) {
        std::cout<<"You arrive to an empty room"<<std::endl;
        return true;
    }
    return false;
}

// Handles the fight between the player and the monster
void Game::fight() {
    // convert the upper letter to lower
    std::string temp = CurrRoom->getMonster().getName();
    temp[0] = static_cast<char>(std::tolower(static_cast<unsigned char>(temp[0])));
    // Compare the monster’s power with the player
    if(CurrRoom->getMonster() > *player) std::cout<< "You encounter a larger " << temp <<std::endl;
    if(*player > CurrRoom->getMonster()) std::cout<< "You encounter a smaller "<< temp << std::endl;
    if (*player==CurrRoom->getMonster()) std::cout<< "You encounter a equally sized "<<temp<<std::endl;

    std::cout<<CurrRoom->getMonster()<<std::endl;  // Print monster details

    while (true) {
        // to calculate the attack we save the life before the attack and after
        int before = CurrRoom->getMonster().getCurrLife();
        int after = (CurrRoom->getMonster().operator-=(*player)).getCurrLife();  // Monster takes damage from the player
        if (CurrRoom->getMonster().getCurrLife() < 0) CurrRoom->getMonster().setLife(0);  // set the life to zero if needed
        // print the damage
        std::cout<<"You deal " << before - after <<" damage to the "<< temp<<" and leave it with " << CurrRoom->getMonster().getCurrLife() <<" health" <<std::endl;
        if(CurrRoom->getMonster().getCurrLife() == 0) {  // If monster is defeated
            player->updateTurnCounter();  // update the counter
            std::cout << "You defeat the "<< temp<<" and go on with your journey" << std::endl;
            break;
        } else {
            // to calculate the attack we save the life before the attack and after
            int before = player->getCurrLife();
            int after =(player->operator-=(CurrRoom->getMonster())).getCurrLife();  // Player takes damage from the monsters
            if (player->getCurrLife()<0) player->setLife(0); // set the life to zero if needed
            if (first_round) {
                first_round=false;
                player->updateTurnCounter(); // update the counter
            }
            else player->updateTurnCounter(); // update the counter

            std::cout<<"The "<< temp<<" deals " <<before-after <<" damage to you and leaves you with " << player->getCurrLife() <<" health" <<std::endl;
            if(player->getCurrLife() == 0) {  // If player is defeated
                isRunning = false;
                std::cout << "You lost to the dungeon" << std::endl;
                break;
            }
        }
    }
}

// Moves the player to a new connected room
void Game::MoveRoom() {
    // update the counter
    if (!first_round) player->updateTurnCounter();
    // If there's only one connected room
    if(CurrRoom->getSizeConnectedRooms()==1) {
        std::cout<<"You see a single corridor ahead of you labeled 0" <<std::endl;
        int choose;
        std::cin>>choose;
        CurrRoom = CurrRoom->operator[](choose); // Move to the chosen room
        std::cout<< *player << std::endl;



    } else {  // If there are multiple connected rooms, let the player choose
        std::cout<<"You see corridors labeled from 0 to "<<CurrRoom->getSizeConnectedRooms() -1 <<". Which one will you choose?"<<std::endl;
        int choose;
        std::cin>>choose;
        CurrRoom = CurrRoom->operator[](choose); // Move to the chosen room
        std::cout<< *player << std::endl;

    }
}

// Checks if the player won the game (if the current room is empty and leads outside)
bool Game::WinTheGame() {
    if(CurrRoom->isEmptyArray()) {
        isRunning = false;
        std::cout<<"The room continues and opens up to the outside. You won against the dungeon"<<std::endl;
        return true;
    }
    return false;
}

// Initializes the game by reading a configuration file and setting up the rooms
void Game::initializeGame(const std::string& confiFile) const {
    std::ifstream file(confiFile);    // Open the configuration file
    if(!file) { // error while opening the file
        throw ValueException();
    }
    std::string line;
    while(std::getline(file, line)) {  // Read each line from the file
        std::istringstream stream(line);
        std::string RoomName;
        int campfireHeal,monsterLife=0, monsterDamage=0;
        bool hasMonster;
        char monsterType;
        if(!(stream >> RoomName >> campfireHeal >>  monsterType)) {  // Parse room details
            throw ValueException();
        }
        if(campfireHeal<0) {
            throw ValueException();
        }

        if(monsterType == 'N') {
          hasMonster = false;

        } else if(monsterType == 'D' || monsterType == 'G') {
            hasMonster = true;// Determine if the room has a monster
            if(!(stream >> monsterLife  >> monsterDamage )) {  // Parse room details
                throw ValueException();
            }
            if (monsterDamage<0 || monsterLife<0) {
                throw ValueException();
            }
        }

        Room *curr= StartRoom;  // Start from the initial room

        for(size_t i = 0; i < RoomName.size()- 1; ++i) {
            int roomNum = RoomName[i] - '0';  // Convert the character to an integer index
            Room* next =(*curr)[roomNum]; // Set the next connected room
            if (roomNum > i + 1) {
                throw ValueException();  // Illegal order of rooms
            }
            while(next == nullptr) {   // If the room doesn’t exist, create one
                Room* newEmptyRoom = new Room("",0,0,0,'N',false);
                curr->addConnectedRoom(newEmptyRoom,roomNum);
                next=newEmptyRoom;
            }
            curr=next;  // Move to the next room
        }

        // Create the final room and add it to the connected rooms
        char lastChar = RoomName.back();
        int lastRoomNum = lastChar - '0';
        Room *newRoom = new Room(RoomName, campfireHeal,monsterLife, monsterDamage,monsterType,hasMonster);
        curr->addConnectedRoom(newRoom,lastRoomNum);   // Add the room at the correct index

    }

    file.close();  // Close the file

}


