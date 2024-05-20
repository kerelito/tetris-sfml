#include "Piece.h"
#include "Board.h"
#include <cstdlib>
#include <ctime>

/**
 * @brief Konstruktor klasy Piece. Inicjalizuje kształt i pozycję klocka.
 * @param type Typ klocka (0-6).
 */
Piece::Piece(int type) : mPosition(3, 0) {
    mShape.setSize(sf::Vector2f(30, 30));
    setShape(type);
    static bool isFirst = true;
    if (isFirst) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        isFirst = false;
    }

    // Define a palette of colors
    static const sf::Color colors[] = {
            sf::Color::Cyan,
            sf::Color::Yellow,
            sf::Color::Green,
            sf::Color::Red,
            sf::Color::Magenta,
            sf::Color::Blue,
            sf::Color::White
    };

    // Randomly select a color
    mColor = colors[std::rand() % (sizeof(colors) / sizeof(colors[0]))];
}

/**
 * @brief Rysuje klocek na podanym oknie.
 * @param window Okno SFML, na którym rysowany jest klocek.
 */
void Piece::draw(sf::RenderWindow& window) {
    for (int x = 0; x < SIZE; ++x) {
        for (int y = 0; y < SIZE; ++y) {
            if (mGrid[x][y] != 0) {
                mShape.setFillColor(mColor);
                mShape.setPosition(50 + (mPosition.x + x) * 30, 50 + (mPosition.y + y) * 30);
                window.draw(mShape);
            }
        }
    }
}

/**
 * @brief Przesuwa klocek o podane wartości.
 * @param dx Przesunięcie w osi X.
 * @param dy Przesunięcie w osi Y.
 * @param board Plansza gry.
 * @return true, jeśli przesunięcie się powiodło, false w przeciwnym razie.
 */
bool Piece::move(int dx, int dy, const Board& board) {
    mPosition.x += dx;
    mPosition.y += dy;
    if (board.isCollision(*this)) {
        mPosition.x -= dx;
        mPosition.y -= dy;
        if (dy != 0) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Obraca klocek.
 * @param board Plansza gry.
 */
void Piece::rotate(const Board& board) {
    int tmp[SIZE][SIZE];
    for (int x = 0; x < SIZE; ++x) {
        for (int y = 0; y < SIZE; ++y) {
            tmp[x][y] = mGrid[SIZE - y - 1][x];
        }
    }
    int backup[SIZE][SIZE];
    std::memcpy(backup, mGrid, sizeof(mGrid));
    std::memcpy(mGrid, tmp, sizeof(mGrid));
    if (board.isCollision(*this)) {
        std::memcpy(mGrid, backup, sizeof(mGrid));
    }
}

/**
 * @brief Ustawia kształt klocka na podstawie jego typu.
 * @param type Typ klocka (0-6).
 */
void Piece::setShape(int type) {
    static const int shapes[7][SIZE][SIZE] = {
            { {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} }, // I
            { {1, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} }, // O
            { {0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} }, // S
            { {1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} }, // Z
            { {1, 1, 1, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} }, // T
            { {1, 1, 1, 0}, {1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} }, // L
            { {1, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} }  // J
    };

    std::memcpy(mGrid, shapes[type], sizeof(mGrid));
}
