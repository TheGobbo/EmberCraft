#include "GameModel.hpp"

using namespace ember;

GameModel::GameModel() {}
GameModel::~GameModel() {}

EnumGameState GameModel::getGameState() const { return this->gameState; }

bool GameModel::isGameOver() const { return gameState == EnumGameState::OVER; }