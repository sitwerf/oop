#include "toFahrenheit_mod.h"
#include "toFahrenheit.h"
#include <random>

int toFahrenheit_mod(int temp){
    std::random_device rd;
    std:: mt19937 gen(rd());

    std::uniform_int_distribution<int> chance(0, 1);
    std::uniform_int_distribution<int> randomadd(1, 50);

    int result = toFahrenheit(temp);

    if (chance(gen) == 1)
    {
        result += randomadd(gen);
    }

    return result;
}
