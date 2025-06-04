#include <iostream>

#include "../includes/Game.hpp"

int main() {
    Game game;

    std::cout << "[main] Calling game.init()...\n";
    if (!game.init("Koto", 800, 600)) {
        std::cerr << "[main] game.init() failed!\n";
        return -1;
    }

    std::cout << "[main] Starting game.run()...\n";
    game.run();

    std::cout << "[main] Cleaning up...\n";
    game.cleanup();

    return 0;
}