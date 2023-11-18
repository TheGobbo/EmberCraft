#include "GameModel.hpp"

using namespace ember;

GameModel::GameModel() {
    this->smithy = new Smithy();
    this->warehouse = new Warehouse(5, 0);
}
GameModel::~GameModel() {
    delete this->smithy;
    delete this->warehouse;
}

EnumGameState GameModel::getGameState() const { return this->gameState; }

bool GameModel::isGameOver() const { return gameState == EnumGameState::OVER; }