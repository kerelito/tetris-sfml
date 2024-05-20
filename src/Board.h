#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include "Piece.h"

/**
 * @class Board
 * @brief Klasa odpowiedzialna za zarządzanie siatką gry Tetris.
 */
class Board {
public:
    /**
     * @brief Konstruktor klasy Board. Inicjalizuje siatkę i granice planszy.
     */
    Board();

    /**
     * @brief Rysuje planszę na podanym oknie.
     * @param window Okno SFML, na którym rysowana jest plansza.
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Sprawdza, czy dany klocek koliduje z blokami na planszy.
     * @param piece Klocek do sprawdzenia.
     * @return true, jeśli występuje kolizja, false w przeciwnym razie.
     */
    bool isCollision(const Piece& piece) const;

    /**
     * @brief Łączy klocek z planszą, dodając jego bloki do siatki.
     * @param piece Klocek do dodania.
     */
    void mergePiece(const Piece& piece);

    /**
     * @brief Usuwa pełne linie z planszy i aktualizuje wynik.
     * @param score Aktualny wynik gry.
     */
    void clearLines(int& score);

private:
    static const int WIDTH = 10; ///< Szerokość planszy.
    static const int HEIGHT = 20; ///< Wysokość planszy.

    struct Block {
        int value; ///< Wartość bloku (0 - pusty, 1 - zapełniony).
        sf::Color color; ///< Kolor bloku.
    };

    Block mGrid[WIDTH][HEIGHT]; ///< Siatka bloków na planszy.
    sf::RectangleShape mBlock; ///< Kształt pojedynczego bloku.
    sf::RectangleShape mBorders; ///< Kształt granic planszy.
};

#endif // BOARD_H
