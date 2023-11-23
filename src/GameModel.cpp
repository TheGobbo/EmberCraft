#include "GameModel.hpp"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <set>

using namespace ember;

GameModel::GameModel() {
    this->smithy = new Smithy();
    this->market = new Market();
    this->warehouse = new Warehouse(5, 3);
    this->gameState = EnumGameState::MENU;
}

GameModel::~GameModel() {
    delete this->smithy;
    delete this->warehouse;
    delete this->market;
}

void GameModel::update() {}

EnumGameState GameModel::getGameState() const { return this->gameState; }

int GameModel::getBalance() const { return this->smithy->getCoins(); }

void GameModel::marketBuyItem(int id) { this->market->addToCart(id); }

void GameModel::applyMarketBuy() {
    int cost = this->market->getCartCost();

    std::map<Material*, int> cart = this->market->getCart();
    std::map<Material*, int>::iterator it = cart.begin();

    for (; it != cart.end(); ++it) {
        for (int i = 0; i < (*it).second; ++i) {
            this->warehouse->addMaterial(new Material{*(*it).first});
        }
    }

    this->smithy->subtractCoins(cost);
}

// void GameModel::applyMarketSell() {}

void GameModel::sellMaterial(const std::string& input) {
    std::istringstream iss{input};
    int bought_id;
    int profits = 0;
    std::set<int, std::greater<int>> selling;
    while (iss >> bought_id) {
        try {
            profits += this->warehouse->getMaterial(bought_id).getCost();
            selling.insert(bought_id);
        } catch (const std::exception& e) {
            std::cerr << e.what() << " - Unable to sell id " << bought_id
                      << ", moving on\n";
        }
    }

    for (const int& id : selling) {
        this->warehouse->removeMaterial(id);
    }

    this->smithy->addCoins(profits);
}
void GameModel::sellCrafted(const std::string& input) {
    std::istringstream iss{input};
    int bought_id;
    int profits = 0;
    std::set<int, std::greater<int>> selling;

    while (iss >> bought_id) {
        try {
            profits += this->warehouse->getCrafted(bought_id).getCost();
            selling.insert(bought_id);

        } catch (const std::exception& e) {
            std::cerr << e.what() << " - Unable to sell id " << bought_id
                      << ", moving on\n";
        }
    }

    for (const int& id : selling) {
        std::cout << "Selling " << id << '\n';
        this->warehouse->removeCrafted(id);
    }

    this->smithy->addCoins(profits);
}

bool GameModel::isGameOver() const { return this->gameState == EnumGameState::OVER; }