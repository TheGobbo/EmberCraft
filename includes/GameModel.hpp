#ifndef GAME_MODEL_HPP
#define GAME_MODEL_HPP

#include "Market.hpp"
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

    void update();

    EnumGameState getGameState() const;
    int getBalance() const;

    void marketBuyItem(int id);
    void applyMarketBuy();
    // void applyMarketSell();

    void sellMaterial(const std::string& input);
    void sellCrafted(const std::string& input);

    void createNewItem(const int mat_idx);

    bool isGameOver() const;

   private:
    EnumGameState gameState;

    Smithy* smithy;
    Market* market;
    Warehouse* warehouse;
    // void setGameState(const EnumGameState& gameState);
};
}  // namespace ember

#endif  // GAME_MODEL_HPP
