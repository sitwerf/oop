#include<iostream>
#include <random>

template <typename T>
T temper(const T& x) {
   return (x * 9 / 5 + 32);
}

template <typename T>
T temper_mod(const T& x) {
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

int main(){
    int znach = 0;
    std::cout << "1 - int, 2 - double";
    std::cin >> znach;
    if (znach == 1){
        int temp = 0;
        std::cout << "Введите температуру: ";
        std::cin >> temp;

        std::cout << "В градусах Фаренгейта: " << temper(temp) << std::endl;
        std::cout << "Модифицированная: " << temper_mod(temp) << std::endl;
    } if (znach == 2) {
        double temp;
        std::cout << "Введите температуру: ";
        std::cin >> temp;

        std::cout << "В градусах Фаренгейта: " << temper(temp) << std::endl;
        std::cout << "Модифицированная: " << temper_mod(temp) << std::endl;
    } else {
        std::cout << "Ошибка";
    }
    
    return 0;
}