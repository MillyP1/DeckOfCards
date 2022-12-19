#ifndef RANDOMNUMBERGENERATOR_H
#define RANDOMNUMBERGENERATOR_H

#include <random>

int generate (const int from, const int to) {
    std::random_device rd;
    std::mt19937_64 gen (rd ());
    std::uniform_int_distribution <> distribution (from, to);
    return distribution (gen);
}

#endif
