#ifndef HEADER1_H
#define HEADER1_H

#include <random>

template <typename T>
T temper(T x) {
   return (x * 9 / 5 + 32);
}

template <typename T>
T temper_mod(T x) {
        std::random_device rd;
        std:: mt19937 gen(rd());

        std::uniform_int_distribution<int> chance(0, 1);
        std::uniform_int_distribution<int> randomadd(1, 50);

        T result = temper(x);

        if (chance(gen) == 1)
        {
            result += randomadd(gen);
        }

        return result;
}

#endif