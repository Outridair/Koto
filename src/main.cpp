#include <iostream>

#include "../includes/Game.hpp";

int main() {
    Game game;
    if (!game.init("Koto", 800, 600)) return -1;
    game.run();
    game.cleanup();

    return 0;
}