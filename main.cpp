#include <iostream>
#include "toFahrenheit.h"
#include "toFahrenheit_mod.h"

int main()
{
    int temp = 0;

    std::cout << "Введите температуру: ";
    std::cin >> temp;

    std::cout << "В градусах Фаренгейта: "
              << toFahrenheit(temp)
              << std::endl;                 //перевод строки

    std::cout << "Модифицированная: "
              << toFahrenheit_mod(temp)
              << std::endl;

    return 0;
}