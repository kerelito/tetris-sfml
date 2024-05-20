#include <SFML/Graphics.hpp>
#include "Game.h"

/**
 * @brief Główna funkcja uruchamiająca grę Tetris.
 * @return Kod zakończenia programu.
 */
int main() {
    // Utworzenie obiektu gry
    Game game;

    // Uruchomienie pętli głównej gry
    game.run();

    return 0;
}
