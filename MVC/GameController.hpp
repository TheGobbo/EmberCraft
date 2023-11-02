#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP

#include <string>

#include "GameModel.hpp"
#include "GameView.hpp"

namespace ember {
// Handles user input and manage interactions between the game's Model and View.
class GameController {
   public:
    GameController(GameModel* model, GameView* view);

    const std::string getUserInput();
    void processUserInput(const std::string& input);

   private:
    GameModel* model;
    GameView* view;

    static short MAX_NUM;

    /*~~~ validade user input ~~~*/
    void processMenuInput(const short& input);
    // void process

    /*~~~ apply state change ~~~*/
    void moveToMerchant();
    void moveToSmithy();

    /*~~~ UTILS ~~~*/
    void setGameState(EnumGameState gameState);
    bool isWholeNumber(const std::string& input);
};
}  // namespace ember

#endif  // GAME_CONTROLLER_HPP
