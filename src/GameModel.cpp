#include "GameModel.hpp"

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
        this->warehouse->addMaterial((*it).first);
    }

    this->smithy->subtractCoins(cost);
}

bool GameModel::isGameOver() const {
    return this->gameState == EnumGameState::OVER;
}