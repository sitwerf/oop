#include <iostream>
#include "5.h"

int main() {
    std::cout << "Обычная температура: " << normal::temper<int>(100)
              << " Модифицированная: " << modified::temper<int>(100) << std::endl;

    std::cout << "Обычная температура: " << normal::temper<double>(36.6)
              << " Модифицированная: " << modified::temper<double>(36.6) << std::endl;
}