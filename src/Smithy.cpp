#include "Smithy.hpp"

using namespace ember;

Smithy::Smithy(/* args */) : coins{1000} {}

Smithy::~Smithy() {}

int Smithy::getCoins() const { return this->coins; }

// every transaction increments the exp by the traded amount
void Smithy::addCoins(const int coins) {
    //  assert + coins is still positive (same sign)
    this->coins += coins;
}

// every transaction increments the exp by the traded amount,
// if subtracts results in balance < 0, returns false (game over!)
bool Smithy::subtractCoins(const int coins) {
    this->coins -= coins;
    return this->coins > 0;
}