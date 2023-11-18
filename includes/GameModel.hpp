#ifndef GAME_MODEL_HPP
#define GAME_MODEL_HPP

#include "Smithy.hpp"
#include "Warehouse.hpp"

namespace ember {
// Possible game states
enum class EnumGameState { MENU, WORKSHOP, MERCHANT, BUY, SELL, OVER };

// Define methods to manage game state, materials, crafting, and player
// interactions.
class GameModel {
    friend class GameController;

   public:
    GameModel();
    ~GameModel();

    EnumGameState getGameState() const;

    bool isGameOver() const;

   private:
    EnumGameState gameState;

    Smithy* smithy;
    Warehouse* warehouse;
    // void setGameState(const EnumGameState& gameState);
};
}  // namespace ember

#endif  // GAME_MODEL_HPP
