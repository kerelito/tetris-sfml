#include "Utils.h"
#include <cstdlib>
#include <ctime>

/**
 * @brief Generuje losową liczbę w zadanym przedziale.
 * @param min Minimalna wartość.
 * @param max Maksymalna wartość.
 * @return Losowa liczba w przedziale [min, max].
 */
int Utils::getRandomNumber(int min, int max) {
    static bool first = true;
    if (first) {
        srand(static_cast<unsigned int>(time(nullptr)));
        first = false;
    }
    return min + rand() % ((max + 1) - min);
}
