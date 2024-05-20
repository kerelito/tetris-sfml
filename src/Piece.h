#pragma once
#include <SFML/Graphics.hpp>
#include "Utils.h"

class Board;

/**
 * @class Piece
 * @brief Klasa reprezentująca pojedynczy klocek w grze Tetris.
 */
class Piece {
public:
    static const int SIZE = 4; ///< Rozmiar klocka (4x4).

    /**
     * @brief Konstruktor klasy Piece. Inicjalizuje kształt i pozycję klocka.
     * @param type Typ klocka (0-6).
     */
    Piece(int type = 0);

    /**
     * @brief Rysuje klocek na podanym oknie.
     * @param window Okno SFML, na którym rysowany jest klocek.
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Przesuwa klocek o podane wartości.
     * @param dx Przesunięcie w osi X.
     * @param dy Przesunięcie w osi Y.
     * @param board Plansza gry.
     * @return true, jeśli przesunięcie się powiodło, false w przeciwnym razie.
     */
    bool move(int dx, int dy, const Board& board);

    /**
     * @brief Obraca klocek.
     * @param board Plansza gry.
     */
    void rotate(const Board& board);

private:
    /**
     * @brief Ustawia kształt klocka na podstawie jego typu.
     * @param type Typ klocka (0-6).
     */
    void setShape(int type);

    int mGrid[SIZE][SIZE]; ///< Siatka reprezentująca kształt klocka.
    sf::RectangleShape mShape; ///< Kształt pojedynczego bloku klocka.
    sf::Vector2i mPosition; ///< Pozycja klocka na planszy.
    sf::Color mColor; ///< Kolor klocka.

    friend class Board;
};
