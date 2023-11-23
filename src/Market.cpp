#include "Market.hpp"

#include <iomanip>
#include <iostream>
#include <stdexcept>

#include "Chalk.hpp"
#include "Console.hpp"

using namespace ember;

std::chrono::duration<double> Market::refresh_rate{180};  // seconds
int Market::store_capacity{10};

Market::Market() : last_refresh{std::chrono::steady_clock::now()} {
    this->stockUpStore();
}

Market::~Market() { this->depleteStore(); }

// controller takes care of figuring out the indexes?
void Market::addToCart(int index) {
    if (index > Market::store_capacity || index <= 0) {
        throw std::invalid_argument("Index of Market Store is out of range: " +
                                    std::to_string(index));
    }

    this->cart[this->store.at(index - 1)] += 1;
}
void Market::removeFromCart(int index) {
    if (index > Market::store_capacity || index <= 0) {
        throw std::invalid_argument("Index of Market Store is out of range: " +
                                    std::to_string(index));
    }

    int quantity = this->cart[this->store.at(index - 1)];
    if (quantity == 0) {
        std::cout << "Cannot remove Item from cart, current quantity is " +
                         std::to_string(quantity);
        return;
    }

    this->cart[this->store.at(index - 1)] -= 1;
}
int Market::getCartCost() {
    int cost = 0;
    std::map<Material*, int>::const_iterator it = this->cart.begin();
    for (; it != this->cart.end(); ++it) {
        cost += ((*it).first->getCost()) * (*it).second;
    }

    return cost;
}

std::map<Material*, int>& Market::getCart() { return this->cart; }

// returns cost of cart
// void Market::finalizeBuy(Warehouse& warehouse, Smithy* smithy) {}

void Market::finalizeMaterialSell(Warehouse& warehouse, Smithy* smithy) {
    // add to card Item* from warehouse
}

void Market::finalizeCraftSell(Warehouse& warehouse, Smithy* smithy) {
    // add to card Item* from warehouse
}

void Market::clearCart() { this->cart.clear(); }

void Market::stockUpStore() {
    this->depleteStore();

    for (int i = 0; i < Market::store_capacity; i++) {
        this->store.push_back(new Material{});
    }

    this->last_refresh = std::chrono::steady_clock::now();
}

void Market::depleteStore() {
    std::vector<Material*>::iterator it;
    Material* ptr;
    // remove items from store
    for (it = this->store.begin(); it != this->store.end();) {
        ptr = *it;
        it = this->store.erase(it);
        delete ptr;
    }

    // remove cart maps
    this->cart.clear();
}

void Market::updatesStore() {
    // clang-format off

    // Compare with the current time to calculate the difference in seconds
    std::chrono::time_point<std::chrono::steady_clock> now = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsedSeconds = now - this->last_refresh;

    if (this->refresh_rate < elapsedSeconds) {
        this->stockUpStore();
    }

    // Print the time difference in seconds
    std::cout << "Time until refresh: " << Market::refresh_rate.count() - elapsedSeconds.count() << " seconds" << std::endl;
    // clang-format on
}

void Market::listStore() {
    std::cout << "LIST STORE\n";
    updatesStore();

    std::vector<Material*>::const_iterator it = this->store.begin();
    int i = 1;
    for (; it != this->store.end(); ++it) {
        Material* index = *it;
        std::string qty = this->cart[index] > 0
                              ? color::Chalk{}.bold().str(this->cart[index])
                              : "0";

        std::cout << std::setw(2) << std::setfill(' ') << i << ". "
                  << Console::displayMarketItem(**it) << "x " << qty << '\n';
        ++i;
    }

    std::cout << "-----------------------------------------------------------------"
                 "-----------------------------------------------------------------";
    std::cout << "  " << color::Chalk{}.bold().inverse().str("Total:") << ' '
              << Console::displayMoney(this->getCartCost());
    std::cout << std::endl;
}