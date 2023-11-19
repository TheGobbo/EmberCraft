#include "GameController.hpp"

#include <cassert>
#include <iostream>
#include <regex>
#include <stdexcept>

using namespace ember;

// static members
short GameController::MAX_NUM{32767};

std::string GameController::warn_invalid_option{
    "Option not available, please try again!\n\n"};

std::string GameController::warn_only_numbers{
    "Only a single whole number is expected.\n"};

// Constructor
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
    // sanity check
    assert(this->model->gameState == this->view->gameState);

    if (input == "menu") {
        moveToMenu();
        return;
    } else if (input == "exit") {
        // saveGame();
        this->setGameState(EnumGameState::OVER);
        return;
    }

    short num_input{parseNumericInput(input)};

    EnumGameState currentState = this->model->getGameState();
    switch (currentState) {
        case EnumGameState::MENU:
            processMenuInput(num_input);
            break;
        case EnumGameState::WORKSHOP:
            processSmithyInput(num_input);
            break;
        case EnumGameState::MERCHANT:
            processMerchantInput(num_input);
            break;
        case EnumGameState::BUY:
            processBuyInput(input);
            break;
        case EnumGameState::SELL:
            processSellInput(input);
            break;

        default:
            throw std::runtime_error("Impossible game state was reached: " +
                                     std::to_string((int)currentState));
            break;
    }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            Validade User Input
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void GameController::processMenuInput(const short& input) {
    switch (input) {
        case 1:
            moveToMerchant();
            break;
        case 2:
            moveToSmithy();
            break;
        case 3:
            this->view->displayBalance(this->model->getBalance());
            break;
        default:
            std::cout << GameController::warn_invalid_option;
            break;
    }
}

void GameController::processSmithyInput(const short& input) {
    switch (input) {
        case 1:
            moveToMerchant();
            break;
        case 2:
            std::cout << "createNewItem\n";
            // this->model->createNewItem();
            break;
        case 3:
            std::cout << "listSmithyMaterials\n";
            // this->model->listSmithyMaterials();
            break;
        case 4:
            std::cout << "destroyMaterial\n";
            // this->model->listSmithyMaterials();
            break;
        default:
            std::cout << GameController::warn_invalid_option;
            break;
    }
}

void GameController::processMerchantInput(const short& input) {
    switch (input) {
        case 1:
            moveToSmithy();
            break;
        case 2:
            moveToBuy();
            break;
        case 3:
            moveToSell();
        case 4:
            this->view->displayBalance(this->model->getBalance());
            break;

        default:
            std::cout << GameController::warn_invalid_option;
            break;
    }
}

void GameController::processBuyInput(const std::string& input) {
    if (input == "a") {
        this->model->applyMarketBuy();
        this->view->displayBalance(this->model->getBalance());
        if (this->model->smithy->getCoins() < 0) {
            std::cout << "YOU WENT BANKRUPT!\n";
            this->setGameState(EnumGameState::OVER);
        } else {
            moveToMerchant();
        }
        this->model->market->clearCart();
        return;
    }

    // go back
    if (input == "b") {
        moveToMerchant();
        this->model->market->clearCart();
        return;
    }

    std::istringstream iss(input);
    int bought_id;
    while (iss >> bought_id) {
        // std::cout << "You just bought a " << bought_id << "\n";
        try {
            this->model->market->addToCart(bought_id);

        } catch (const std::exception& e) {
            std::cerr << e.what() << " - Please try again\n";
            this->model->market->clearCart();
        }
    }
    // std::cout << " Your ballance is now ";
    // this->view->displayBalance(this->model->getBalance());
    std::cout << "\n";
    this->model->market->listStore();
}

void GameController::processSellInput(const std::string& input) {
    short option{parseNumericInput(input)};

    // go back
    if (option == 1) {
        moveToMerchant();
        return;
    }

    std::cout << "You just sold a " << input;
    std::cout << " Your ballance is now $" << 0.0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            Apply State Changes
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void GameController::moveToMerchant() {
    std::cout << "You moved to the merchant's Store!\n";
    // Update the game state to reflect that the player is in the MERCHANT state
    this->setGameState(EnumGameState::MERCHANT);
}

void GameController::moveToSmithy() {
    std::cout << "You moved to the Smithy's Workshop!\n";
    this->setGameState(EnumGameState::WORKSHOP);
}

void GameController::moveToBuy() {
    assert(this->model->gameState == EnumGameState::MERCHANT);
    this->setGameState(EnumGameState::BUY);

    std::cout << "You are now seeing the Merchant's Items for Sale!\n";

    this->model->market->listStore();
}

void GameController::moveToSell() {
    assert(this->model->gameState == EnumGameState::MERCHANT);
    this->setGameState(EnumGameState::SELL);

    std::cout << "You moved to the Merchant's Trading Post!\n";
    this->model->warehouse->listCrafted();
    this->model->warehouse->listMaterials();
}

void GameController::moveToMenu() { this->setGameState(EnumGameState::MENU); }

/*~~~~~~~~~~~~~~~~~~~~~~~~~~
            UTILS
~~~~~~~~~~~~~~~~~~~~~~~~~~*/

short GameController::parseNumericInput(const std::string& input) {
    long int eval{-1};
    if (isWholeNumber(input)) {
        try {
            eval = stoi(input);
        } catch (const std::invalid_argument& e) {
            std::cerr << GameController::warn_only_numbers;
        }

        if (eval > GameController::MAX_NUM) {
            throw std::invalid_argument(
                "Input exceeded maximum allowed integer: " +
                std::to_string(GameController::MAX_NUM));
        }
    }
    return eval;
}

void GameController::setGameState(EnumGameState gameState) {
    this->view->gameState = gameState;
    this->model->gameState = gameState;
}

bool GameController::isWholeNumber(const std::string& input) {
    std::regex number("^(?:\\s*|\\d+)$");
    return std::regex_match(input, number);
}

/*
void GameController::moveToWorkshop() {
    // Update the game state to reflect that the player is in the WORKSHOP
state GameModel::setGameState(GameState::WORKSHOP);
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
