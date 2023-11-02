#include "GameView.hpp"

#include <iostream>

#include "GameModel.hpp"

using namespace ember;

GameView::GameView() {}

GameView::~GameView() {}

// clang-format off
void GameView::displayTitle() const {
    std::cout << "\n";
    std::cout << "\t███████╗███╗░░░███╗██████╗░███████╗██████╗░░█████╗░██████╗░░█████╗░███████╗████████╗\n";
    std::cout << "\t██╔════╝████╗░████║██╔══██╗██╔════╝██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔════╝╚══██╔══╝\n";
    std::cout << "\t█████╗░░██╔████╔██║██████╦╝█████╗░░██████╔╝██║░░╚═╝██████╔╝███████║█████╗░░░░░██║░░░\n";
    std::cout << "\t██╔══╝░░██║╚██╔╝██║██╔══██╗██╔══╝░░██╔══██╗██║░░██╗██╔══██╗██╔══██║██╔══╝░░░░░██║░░░\n";
    std::cout << "\t███████╗██║░╚═╝░██║██████╦╝███████╗██║░░██║╚█████╔╝██║░░██║██║░░██║██║░░░░░░░░██║░░░\n";
    std::cout << "\t╚══════╝╚═╝░░░░░╚═╝╚═════╝░╚══════╝╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░░░░░░░╚═╝░░░\n";
    std::cout << "\tBy E. Gobbo Willi V.G.\n\n\n";
}
// clang-format on

void GameView::displayGameScreen() const {
    std::cout << "What would you like to do?\n";

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
            throw std::runtime_error(
                "No such instance of EnumGameState, abort.");
            break;
    }

    std::cout << "\n";
}

void GameView::displayMenu() const {
    std::cout << "GAMESTATE IS MENU\n";
    std::cout << "1. Move to Merchant's Store\n";
    std::cout << "2. Move to Smithy's Workshop\n";
    std::cout << "3. Show Smithy's balance\n";
}
void GameView::displayWorkshop() const {
    std::cout << "GAMESTATE IS WORKSHOP\n";
}
void GameView::displayMerchant() const {
    std::cout << "GAMESTATE IS MERCHANT\n";
}
void GameView::displayBuy() const { std::cout << "GAMESTATE IS BUY\n"; }
void GameView::displaySell() const { std::cout << "GAMESTATE IS SELL\n"; }
void GameView::displayGameOver() const { std::cout << "GAMESTATE IS OVER\n"; }

void GameView::displayBalance() const {
    std::cout << "The Smithy's current balance is: $" << 0.00 << " coins!\n";
}