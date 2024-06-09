#include "Utils.h"
#include <cstdlib>
#include <ctime>

int Utils::getRandomNumber(int min, int max) {
    static bool first = true;
    if (first) {
        srand(static_cast<unsigned int>(time(nullptr)));
        first = false;
    }
    return min + rand() % ((max + 1) - min);
}
