#include<iostream>
#include <random>
#include "header1.h"


int main(){
    int temp = 0;
    std::cout << "Введите температуру: ";
    std::cin >> temp;

        std::cout << "В градусах Фаренгейта: " << temper<float, int>(temp) << std::endl;
        std::cout << "Модифицированная: " << temper_mod<float, int>(temp) << std::endl;

    double temp;
    std::cout << "Введите температуру: ";
    std::cin >> temp;

    std::cout << "В градусах Фаренгейта: " << temper<int, double>(temp) << std::endl;
    std::cout << "Модифицированная: " << temper_mod<int, double>(temp) << std::endl;

    return 0;
}