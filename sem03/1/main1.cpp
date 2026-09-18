#include<iostream>
#include <random>
#include "header1.h"


int main(){
    int znach = 0;
    std::cout << "1 - int, 2 - double " ;
    std::cin >> znach;
    if (znach == 2){
        int temp = 0;
        std::cout << "Введите температуру: ";
        std::cin >> temp;

        std::cout << "В градусах Фаренгейта: " << temper<double, int>(temp) << std::endl;
        std::cout << "Модифицированная: " << temper_mod<double, int>(temp) << std::endl;
    } if (znach == 1) {
        double temp;
        std::cout << "Введите температуру: ";
        std::cin >> temp;

        std::cout << "В градусах Фаренгейта: " << temper<int, double>(temp) << std::endl;
        std::cout << "Модифицированная: " << temper_mod<int, double>(temp) << std::endl;
    } if (znach !=1 && znach != 2) {
        std::cout << "Ошибка";
    }
    
    return 0;
}