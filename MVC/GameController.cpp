#include "GameController.hpp"

#include <iostream>
#include <regex>
#include <stdexcept>

using namespace ember;

short GameController::MAX_NUM = 32767;

GameController::GameController(GameModel* model, GameView* view) {
    if (model == nullptr) {
        throw std::invalid_argument("GameModel is nullptr, aborting.");
    }
    if (model == nullptr) {
        throw std::invalid_argument("GameView is nullptr, aborting.");
    }

    this->model = model;
    this->view = view;

    this->setGameState(EnumGameState::MENU);
}

const std::string GameController::getUserInput() {
    std::cout << "-> ";
    std::string input;
    std::getline(std::cin, input);
    return input;
}

void GameController::processUserInput(const std::string& input) {
    short num_input = -1;

    if (isWholeNumber(input)) {
        long int eval = 0;

        try {
            eval = stoi(input);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Only a single whole number is expected.\n";
        }

        if (eval > GameController::MAX_NUM) {
            throw std::invalid_argument(
                "Input exceeded maximum allowed integer: " +
                std::to_string(GameController::MAX_NUM));
        }

        num_input = eval;
    }

    EnumGameState currentState = this->model->getGameState();
    switch (currentState) {
        case EnumGameState::MENU:
            processMenuInput(num_input);
            break;

        default:
            throw std::runtime_error("Impossible game state was reached: " +
                                     std::to_string((int)currentState));
            break;
    }
}

void GameController::processMenuInput(const short& input) {
    switch (input) {
        case 1:
            moveToMerchant();
            break;

        case 2:
            moveToSmithy();
            break;

        case 3:
            this->view->displayBalance();
            // moveToBank();
            break;

        default:
            std::cout << "Option not available, please try again!\n\n";
            break;
    }
}

void GameController::moveToMerchant() {
    std::cout << "You moved to the merchant's Store!\n";
    this->setGameState(EnumGameState::MERCHANT);

    // Update the game state to reflect that the player is in the MERCHANT state
    // GameModel::setGameState(GameState::MERCHANT);
}

void GameController::moveToSmithy() {
    std::cout << "You moved to the Smithy's Workshop!\n";
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~
            UTILS
~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void GameController::setGameState(EnumGameState gameState) {
    // this->view->gameState = gameState;
    // this->model->gameState = gameState;
}

bool GameController::isWholeNumber(const std::string& input) {
    std::regex number("^(?:\\s*|\\d+)$");
    return std::regex_match(input, number);
}

/*
void GameController::moveToWorkshop() {
    // Update the game state to reflect that the player is in the WORKSHOP state
    GameModel::setGameState(GameState::WORKSHOP);
}



void GameController::processUserInput(const std::string& userInput) {
    // Check the game state to determine which actions to perform
    EnumGameState currentState = GameModel::getGameState();

    if (currentState == GameState::WORKSHOP) {
        // Logic for the WORKSHOP state
        if (userInput == "list materials") {
            // List the player's materials
            GameModel::listMaterials();
        } else if (userInput == "create item") {
            // Create an item if the player has the required materials
            GameModel::createItem();
        }
    } else if (currentState == GameState::MERCHANT) {
        // Logic for the MERCHANT state
        if (userInput == "buy item") {
            // Logic for buying items from the merchant
            GameModel::buyItem();
        } else if (userInput == "sell item") {
            // Logic for selling items to the merchant
            GameModel::sellItem();
        }
    }
}
*/
