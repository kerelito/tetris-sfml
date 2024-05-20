#pragma once

/**
 * @class Utils
 * @brief Klasa pomocnicza zawierająca funkcje narzędziowe.
 */
class Utils {
public:
    /**
     * @brief Generuje losową liczbę w zadanym przedziale.
     * @param min Minimalna wartość.
     * @param max Maksymalna wartość.
     * @return Losowa liczba w przedziale [min, max].
     */
    static int getRandomNumber(int min, int max);
};
