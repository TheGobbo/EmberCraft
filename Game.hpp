#ifndef GAME_HPP
#define GAME_HPP

// #include "bank.hpp"
// #include "factory.hpp"
// #include "market.hpp"
// #include "menu.hpp"
// #include "merchant.hpp"
// #include "Player.hpp"

namespace ember {

// enum class GameState { EXIT, WORKSHOP, MERCHANT };

class Game {
   public:
    Game() = default;
    ~Game() = default;
    void run();

   private:
    // ember::Player* player;
    // Merchant* merchant;
    // Market* market;
    // Factory* factory;
    // Bank* bank;
    // Menu* menu;
};
}  // namespace ember

#endif