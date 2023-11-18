#include <unistd.h>

#include <iostream>

#include "Market.hpp"

using namespace ember;

int main() {
    Market m = Market{};

    m.listStore();
    // sleep(1); // change Market::refresh_rate
    // m.listStore();

    m.addToCart(1);
    m.addToCart(4);
    m.addToCart(4);
    // m.addToCart(0);  // exception
    // m.addToCart(11); // exception

    m.listStore();

    m.removeFromCart(4);
    m.removeFromCart(4);
    m.removeFromCart(1);
    // m.removeFromCart(0);
    // m.removeFromCart(11);

    m.addToCart(5);
    m.addToCart(5);
    m.addToCart(5);
    m.addToCart(5);
    m.addToCart(5);
    m.addToCart(5);
    m.addToCart(5);
    m.addToCart(5);

    // m.cancel();

    m.listStore();

    std::cout << "MARKET TEST DONE\n";
    return 0;
}