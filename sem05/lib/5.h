#pragma once
#include <random>

namespace normal {
    // перевод Цельсия в Фаренгейты
    // T1 — тип результата, T2 — тип аргумента
    template <typename T1, typename T2>
    T1 temper(T2 x) {
        return static_cast<T1>(x * 9.0 / 5.0 + 32);
    }
}

namespace modified {
    template <typename T1, typename T2>
    T1 temper(T2 x) {
        static std::mt19937 gen(std::random_device{}());
        std::uniform_int_distribution<int> chance(0, 1);
        std::uniform_int_distribution<int> randomadd(1, 50);

        T1 result = normal::temper<T1, T2>(x);
        if (chance(gen) == 1) {
            result += randomadd(gen);
        }
        return result;
    }
}