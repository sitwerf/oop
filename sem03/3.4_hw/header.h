#ifndef HEADER1_H
#define HEADER1_H

#include <random>

template <typename T1, typename T2>
T1 temper(T2 x) {
    return x * 9.0 / 5.0 + 32;
}

template <typename T1, typename T2>
T1 temper_mod(T2 x) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> chance(0, 1);
    std::uniform_int_distribution<int> randomadd(1, 50);

    T1 result = temper<T1, T2>(x);

    if (chance(gen) == 1) {
        result += randomadd(gen);
    }

    return result;
}

#endif