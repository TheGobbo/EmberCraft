#ifndef GAME_VIEW_HPP
#define GAME_VIEW_HPP

// #include "GameController.hpp"
#include "GameModel.hpp"

namespace ember {
// class GameController;
// Define methods to display game information to the player.
class GameView {
    // friend GameController;
    friend class GameController;
    // friend void GameController::setGameState(EnumGameState gameState);

   public:
    GameView();
    ~GameView();

    // void setListener(GameController* controller); // ???

    void displayTitle() const;
    void displayEnd() const;

    void displayGameScreen() const;
    void displayGameOver() const;

    void displayMenu() const;
    void displayWorkshop() const;
    void displayMerchant() const;
    void displayBuy() const;
    void displaySell() const;

    void displayBalance(int balance) const;

   private:
    EnumGameState gameState;
};
}  // namespace ember

#endif  // GAME_VIEW_HPP
