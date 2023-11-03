#include "Game.hpp"

#include <iostream>

#include "GameController.hpp"
#include "GameModel.hpp"
#include "GameView.hpp"

using namespace ember;

void Game::run() {
    // Initialize the Model, View, and Controller
    GameModel model;
    GameView view;
    GameController controller(&model, &view);
    // view.setListener(&controller);

    // Main game loop
    bool isGameOver = false;
    while (!isGameOver) {
        // Display the appropriate view to the player
        view.displayGameScreen();  // Custom method in GameView

        // Get user input through the controller
        // Custom method in GameController
        std::string userInput = controller.getUserInput();

        // Process user input and update the game state
        controller.processUserInput(userInput);

        // Check for game over conditions (e.g., player wins, loses, or quits)
        isGameOver = model.isGameOver();  // Custom method in GameModel
    }

    // Display the game over screen or results
    view.displayGameOver();
}
