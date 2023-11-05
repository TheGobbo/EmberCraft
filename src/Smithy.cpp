/*#include "Player.hpp"

#include <iostream>
#include <string>

using namespace ember;

Player::Player() {
    std::cout << "Adventurer, please tell me your name, so that I can register "
                 "it into the smithy ownwers catalogue:\n-> ";
    std::string name;

    std::getline(std::cin, name);
    this->name = name;

    std::cout << "\nThank you `" << this->getName()
              << "`, you are now officialy registered!\n\n";

    this->exp = 0;
    this->money = 0;
    this->level = 0;
}

Player::~Player() {}

void Player::setName(const std::string& name) { this->name = name; }

const std::string& Player::getName() const { return this->name; }*/