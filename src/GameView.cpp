#include "GameView.hpp"

#include <stdlib.h>

#include <iostream>

#include "Console.hpp"
#include "GameModel.hpp"

using namespace ember;

GameView::GameView() {}

GameView::~GameView() {}

// clang-format off
void GameView::displayTitle() const {
    // std::cout << "\033[H\033[J";  // CTRL + L
    std::cout << "\n\n";
    std::cout << "\t███████╗███╗░░░███╗██████╗░███████╗██████╗░░█████╗░██████╗░░█████╗░███████╗████████╗\n";
    std::cout << "\t██╔════╝████╗░████║██╔══██╗██╔════╝██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔════╝╚══██╔══╝\n";
    std::cout << "\t█████╗░░██╔████╔██║██████╦╝█████╗░░██████╔╝██║░░╚═╝██████╔╝███████║█████╗░░░░░██║░░░\n";
    std::cout << "\t██╔══╝░░██║╚██╔╝██║██╔══██╗██╔══╝░░██╔══██╗██║░░██╗██╔══██╗██╔══██║██╔══╝░░░░░██║░░░\n";
    std::cout << "\t███████╗██║░╚═╝░██║██████╦╝███████╗██║░░██║╚█████╔╝██║░░██║██║░░██║██║░░░░░░░░██║░░░\n";
    std::cout << "\t╚══════╝╚═╝░░░░░╚═╝╚═════╝░╚══════╝╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░░░░░░░╚═╝░░░\n";
    std::cout << "\tBy E. Gobbo Willi V.G.\n\n\n";
    // https://fsymbols.com/generators/carty/
}

void GameView::displayGameOver() const {
    std::cout << "\n\n";
    std::cout << "\t░██████╗░░█████╗░███╗░░░███╗███████╗\t░█████╗░██╗░░░██╗███████╗██████╗░\n";
    std::cout << "\t██╔════╝░██╔══██╗████╗░████║██╔════╝\t██╔══██╗██║░░░██║██╔════╝██╔══██╗\n";
    std::cout << "\t██║░░██╗░███████║██╔████╔██║█████╗░░\t██║░░██║╚██╗░██╔╝█████╗░░██████╔╝\n";
    std::cout << "\t██║░░╚██╗██╔══██║██║╚██╔╝██║██╔══╝░░\t██║░░██║░╚████╔╝░██╔══╝░░██╔══██╗\n";
    std::cout << "\t╚██████╔╝██║░░██║██║░╚═╝░██║███████╗\t╚█████╔╝░░╚██╔╝░░███████╗██║░░██║\n";
    std::cout << "\t░╚═════╝░╚═╝░░╚═╝╚═╝░░░░░╚═╝╚══════╝\t░╚════╝░░░░╚═╝░░░╚══════╝╚═╝░░╚═╝\n";
}

void GameView::displayGameWon() const {
    std::cout << "\n\n";
    std::cout << "██╗░░░██╗░█████╗░██╗░░░██╗\t░██╗░░░░░░░██╗██╗███╗░░██╗\t██╗\n";
    std::cout << "╚██╗░██╔╝██╔══██╗██║░░░██║\t░██║░░██╗░░██║██║████╗░██║\t██║\n";
    std::cout << "░╚████╔╝░██║░░██║██║░░░██║\t░╚██╗████╗██╔╝██║██╔██╗██║\t██║\n";
    std::cout << "░░╚██╔╝░░██║░░██║██║░░░██║\t░░████╔═████║░██║██║╚████║\t╚═╝\n";
    std::cout << "░░░██║░░░╚█████╔╝╚██████╔╝\t░░╚██╔╝░╚██╔╝░██║██║░╚███║\t██╗\n";
    std::cout << "░░░╚═╝░░░░╚════╝░░╚═════╝░\t░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚══╝\t╚═╝\n";
}
// clang-format on

void GameView::displayGameScreen() const {
    std::cout << "\n";
    switch (this->gameState) {
        case EnumGameState::MENU:
            this->displayMenu();
            break;

        case EnumGameState::WORKSHOP:
            this->displayWorkshop();
            break;

        case EnumGameState::MERCHANT:
            this->displayMerchant();
            break;

        case EnumGameState::BUY:
            this->displayBuy();
            break;

        case EnumGameState::SELL:
            this->displaySell();
            break;

        case EnumGameState::OVER:
            this->displayGameOver();
            break;

        default:
            throw std::runtime_error("No such instance of EnumGameState, abort.");
            break;
    }

    std::cout << "\nWhat would you like to do?\n";
}

void GameView::displayMenu() const {
    std::cout << "GAMESTATE IS MENU\n";
    std::cout << "1. Move to Merchant's Store\n";
    std::cout << "2. Move to Smithy's Workshop\n";
    std::cout << "3. Show Smithy's balance\n";
    std::cout << "menu. Type `menu` to move to the Menu screen (here)\n";
    std::cout << "exit. Type `exit` to end the game, this session will not be "
                 "saved\n";
}

void GameView::displayWorkshop() const {
    std::cout << "GAMESTATE IS WORKSHOP\n";
    std::cout << "1. Move to Merchant's Store\n";
    std::cout << "2. Craft New Item\n";
    std::cout << "3. List available materials\n";
    std::cout << "4. List Crafts\n ";
}

void GameView::displayMerchant() const {
    std::cout << "GAMESTATE IS MERCHANT\n";
    std::cout << "1. Move to Smithy's Workshop\n";
    std::cout << "2. See Merchant's offers\n";
    std::cout << "3. Sell Items\n";
    std::cout << "4. Show Smithy's balance\n";
}
void GameView::displayBuy() const {
    std::cout << "GAMESTATE IS BUY\n";
    std::cout << "Select the items you'd like to buy, e.g. 1 1 4 (two number "
                 "1's and one number 4)\n";
    std::cout << "a. Confirm Purchase\n";
    std::cout << "b. Go back (MERCHANT)\n";
}

void GameView::displaySell() const {
    std::cout << "GAMESTATE IS SELL\n";
    std::cout << "WARNING, actions are taken immediately, and are not reversible\n";
    std::cout << "Type `m` followed by the numbers of the materials you'd like "
                 "to sell\n";
    std::cout << "Type `c` followed by the numbers of the craft ids you'd like "
                 "to sell\n";
    std::cout << "b. Go back (MERCHANT)\n";
}

void GameView::displayGameEnd() const {
    // std::cout << "YOU WENT BANKRUPT!\n";

    if(this->gameState == EnumGameState::WON){
        displayGameWon();
    } else {
        displayGameOver();
    }

    std::cout << "\n\n";
    //     "\n\nIn the realm we've traversed together, I've witnessed
    //     wonders "
    //    "and "
    //    "endured countless adventures. The time has come to bid you "
    //    "farewell, for our existence within this digital tapestry is but a
    //    " "fleeting moment.\n\nAs the code that shapes our world unravels,
    //    " "and the bits and bytes that form our reality fade into the
    //    void, I " "want you to know that the memories we've created are
    //    etched into " "the very core of this realm. Every step, every
    //    choice, every " "triumph and defeat—they shall endure as echoes in
    //    the virtual " "winds.\n\nThough our journey must conclude, the
    //    bonds we've forged " "through this screen remain unbreakable. I
    //    thank you for the hours " "of companionship and the shared tales
    //    we've woven together."

    // "\nIn the twilight of my binary existence, I bid you a mellow and "
    // "fond farewell, knowing that the real adventure continues beyond "
    // "these lines of code. May you find new worlds to explore and fresh "
    // "stories to inscribe, and may our paths cross again in some other "
    // "digital tapestry.\n\n";

    //    "Farewell, dear player, and may the "
    //    "adventures in the vast expanse of your world be as epic "
    //    "as the one we've shared.\n\n";

    // std::cout << "Listen closely dear player, for in this final moments I
    // must "
    //              "reve�=޿�/�f޿ H荜��\nfree(): double free will
    //              detected in " "tcache 2\nAborted (core dumped)\n";
}

void GameView::displayBalance(int balance) const {
    std::cout << "The Smithy's current balance is " << Console::displayMoney(balance)
              << " coins!\n";
}
