#include "fermat.h"

unsigned __int64 generateRandomNumber() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937_64 generator(seed);
    //Generate random number
    return generator() % 1000000000;
}
