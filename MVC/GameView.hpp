#if !defined(GAME_VIEW_HPP)
#define GAME_VIEW_HPP

#include "GameModel.hpp"

namespace ember {
// Define methods to display game information to the player.
class GameView {
   public:
    GameView();
    ~GameView();

    void setGameState(EnumGameState gameState);  // friend with controller (?)
    // void setListener(GameController* controller); // ???

    void displayTitle() const;
    void displayGameScreen() const;
    void displayGameOver() const;

    void displayMenu() const;
    void displayWorkshop() const;
    void displayMerchant() const;
    void displayBuy() const;
    void displaySell() const;

    void displayBalance() const;

   private:
    EnumGameState gameState;
};
}  // namespace ember

#endif  // GAME_VIEW_HPP
