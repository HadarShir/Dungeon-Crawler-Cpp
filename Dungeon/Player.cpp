#include "Player.h"
// Constructor: Initializes the player's name, maximum life, and damage.
Player::Player(std::string name, int maxLife, int damage)
    : Entity(std::move(name), maxLife, damage),canActivate(true),turnCounter(0) {}

// update the counter
void Player::updateTurnCounter() {
    turnCounter++;

}



Player:: ~Player() = default;
