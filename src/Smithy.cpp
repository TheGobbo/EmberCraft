#include "Smithy.hpp"

using namespace ember;

Smithy::Smithy(/* args */) {}

Smithy::~Smithy() {}

// every transaction increments the exp by the traded amount
void Smithy::addCoins(const int coins) {
    //  assert + coins is still positive (same sign)
}

// every transaction increments the exp by the traded amount,
// if subtracts results in balance < 0, returns false (game over!)
bool Smithy::subtractCoins(const int coins) { return true; }