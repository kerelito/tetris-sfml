#include "Game.h"
#include <iostream>

Game::Game()
        : mWindow(sf::VideoMode(1920, 1080), "Tetris SFML"), mBoard(), mCurrentPiece(Utils::getRandomNumber(0, 6)),
          mNextPiece(Utils::getRandomNumber(0, 6)), mIsMovingLeft(false), mIsMovingRight(false), mIsRotating(false),
          mIsFastDropping(false), mScore(0), mGameOver(false), mMoveDownDelay(0.5f), mOriginalMoveDownDelay(0.5f) {

    if (!mFont.loadFromFile("resources/Arial.ttf")) {
        std::cerr << "Failed to load font resources/Arial.ttf" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    mScoreText.setFont(mFont);
    mScoreText.setCharacterSize(20);
    mScoreText.setFillColor(sf::Color::White);
    mScoreText.setPosition(650, 50);
    mScoreText.setString("Score: 0");

    mGameOverText.setFont(mFont);
    mGameOverText.setCharacterSize(100);
    mGameOverText.setFillColor(sf::Color::Red);
    mGameOverText.setPosition(650, 250);
    mGameOverText.setString("Game Over!");

    mAuthorText.setFont(mFont);
    mAuthorText.setCharacterSize(20);
    mAuthorText.setFillColor(sf::Color::White);
    mAuthorText.setPosition(650, 100);
    mAuthorText.setString("Autor: Karol Lempicki");
}

void Game::run() {
    sf::Clock clock;
    while (mWindow.isOpen()) {
        processEvents();
        sf::Time deltaTime = clock.restart();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
}

void Game::update() {
    if (mGameOver) return;

    float currentMoveDownDelay = mIsFastDropping ? mMoveDownDelay / 10 : mMoveDownDelay;

    if (mClock.getElapsedTime().asSeconds() > currentMoveDownDelay) {
        if (!mCurrentPiece.move(0, 1, mBoard)) {
            mBoard.mergePiece(mCurrentPiece);
            mBoard.clearLines(mScore);
            if (mBoard.isCollision(mNextPiece)) {
                mGameOver = true;
            } else {
                mCurrentPiece = mNextPiece;
                mNextPiece = Piece(Utils::getRandomNumber(0, 6));
            }
        }
        mClock.restart();
    }

    if (mIsMovingLeft) {
        mCurrentPiece.move(-1, 0, mBoard);
        mIsMovingLeft = false;
    }
    if (mIsMovingRight) {
        mCurrentPiece.move(1, 0, mBoard);
        mIsMovingRight = false;
    }
    if (mIsRotating) {
        mCurrentPiece.rotate(mBoard);
        mIsRotating = false;
    }

    mScoreText.setString("Wynik: " + std::to_string(mScore));
}

void Game::render() {
    mWindow.clear();
    mBoard.draw(mWindow);
    mCurrentPiece.draw(mWindow);
    mWindow.draw(mScoreText);
    if (mGameOver) {
        mWindow.draw(mGameOverText);
    }
    mWindow.draw(mAuthorText);
    mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::Left) {
        mIsMovingLeft = isPressed;
    } else if (key == sf::Keyboard::Right) {
        mIsMovingRight = isPressed;
    } else if (key == sf::Keyboard::Up) {
        mIsRotating = isPressed;
    } else if (key == sf::Keyboard::Down) {
        mIsFastDropping = isPressed;
    }
}
