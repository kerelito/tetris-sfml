#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Piece.h"

/**
 * @class Game
 * @brief Klasa zarządzająca główną logiką gry Tetris.
 */
class Game {
public:
    /**
     * @brief Konstruktor klasy Game. Inicjalizuje wszystkie zmienne.
     */
    Game();

    /**
     * @brief Uruchamia główną pętlę gry.
     */
    void run();

private:
    /**
     * @brief Przetwarza zdarzenia wejściowe gracza.
     */
    void processEvents();

    /**
     * @brief Aktualizuje stan gry.
     */
    void update();

    /**
     * @brief Renderuje wszystkie elementy gry.
     */
    void render();

    /**
     * @brief Obsługuje wejście klawiatury gracza.
     * @param key Klawisz wciśnięty przez gracza.
     * @param isPressed Określa, czy klawisz jest wciśnięty.
     */
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    sf::RenderWindow mWindow; ///< Główne okno gry.
    Board mBoard; ///< Plansza gry.
    Piece mCurrentPiece; ///< Aktualnie kontrolowany klocek.
    Piece mNextPiece; ///< Następny klocek, który pojawi się w grze.
    bool mIsMovingLeft; ///< Flaga określająca, czy klocek porusza się w lewo.
    bool mIsMovingRight; ///< Flaga określająca, czy klocek porusza się w prawo.
    bool mIsRotating; ///< Flaga określająca, czy klocek jest obracany.
    bool mIsFastDropping; ///< Flaga określająca, czy klocek szybko opada.
    int mScore; ///< Aktualny wynik gry.
    bool mGameOver; ///< Flaga określająca, czy gra jest zakończona.
    sf::Clock mClock; ///< Zegar do mierzenia czasu między aktualizacjami.
    sf::Clock mMoveDownClock; ///< Zegar do mierzenia czasu między opadaniem klocka.
    float mMoveDownDelay; ///< Opóźnienie między kolejnymi opadnięciami klocka.
    float mOriginalMoveDownDelay; ///< Oryginalne opóźnienie między opadnięciami klocka.
    sf::Font mFont; ///< Czcionka używana w grze.
    sf::Text mScoreText; ///< Tekst wyświetlający aktualny wynik.
    sf::Text mGameOverText; ///< Tekst wyświetlający komunikat o końcu gry.
    sf::Text mAuthorText; ///< Tekst wyświetlający autora gry.
};
