#include "Board.h"
#include "Piece.h"

Board::Board() {
    for (int x = 0; x < WIDTH; ++x) {
        for (int y = 0; y < HEIGHT; ++y) {
            mGrid[x][y] = {0, sf::Color::Transparent}; // Ustaw wartość i kolor bloku na domyślne
        }
    }
    mBorders.setSize(sf::Vector2f(WIDTH * 30 + 6, HEIGHT * 30 + 6)); // Dostosuj rozmiar granic
    mBorders.setOutlineThickness(3); // Grubość obramowania
    mBorders.setOutlineColor(sf::Color::White);
    mBorders.setFillColor(sf::Color::Transparent);
    mBorders.setPosition(50, 50); // Dostosuj pozycję granic, aby były bardziej widoczne

    mBlock.setSize(sf::Vector2f(30, 30));
}

void Board::draw(sf::RenderWindow& window) {
    window.draw(mBorders);
    for (int x = 0; x < WIDTH; ++x) {
        for (int y = 0; y < HEIGHT; ++y) {
            if (mGrid[x][y].value != 0) {
                mBlock.setPosition(53 + x * 30, 53 + y * 30); // Dopasuj pozycję bloku, aby były wewnątrz granic
                mBlock.setFillColor(mGrid[x][y].color); // Ustaw kolor bloku na odpowiedni
                window.draw(mBlock);
            }
        }
    }
}

bool Board::isCollision(const Piece& piece) const {
    for (int x = 0; x < Piece::SIZE; ++x) {
        for (int y = 0; y < Piece::SIZE; ++y) {
            if (piece.mGrid[x][y] != 0) {
                int boardX = piece.mPosition.x + x;
                int boardY = piece.mPosition.y + y;
                if (boardX < 0 || boardX >= WIDTH || boardY >= HEIGHT || (boardY >= 0 && mGrid[boardX][boardY].value != 0)) {
                    return true;
                }
            }
        }
    }
    return false;
}

void Board::mergePiece(const Piece& piece) {
    for (int x = 0; x < Piece::SIZE; ++x) {
        for (int y = 0; y < Piece::SIZE; ++y) {
            if (piece.mGrid[x][y] != 0) {
                mGrid[piece.mPosition.x + x][piece.mPosition.y + y] = {piece.mGrid[x][y], piece.mColor};
            }
        }
    }
}

void Board::clearLines(int& score) {
    for (int y = HEIGHT - 1; y >= 0; --y) {
        bool isLineFull = true;
        for (int x = 0; x < WIDTH; ++x) {
            if (mGrid[x][y].value == 0) {
                isLineFull = false;
                break;
            }
        }
        if (isLineFull) {
            for (int moveY = y; moveY > 0; --moveY) {
                for (int x = 0; x < WIDTH; ++x) {
                    mGrid[x][moveY] = mGrid[x][moveY - 1];
                }
            }
            for (int x = 0; x < WIDTH; ++x) {
                mGrid[x][0] = {0, sf::Color::Transparent};
            }
            score += 100;
            ++y; // Sprawdź ponownie tę linię, ponieważ przesunięto linie w dół.
        }
    }
}
