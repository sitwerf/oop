#include<iostream>
#include <random>
#include "header1.h"


int main(){
    int znach = 0;
    std::cout << "1 - int, 2 - double " ;
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
    } if (znach !=1 && znach != 2) {
        std::cout << "Ошибка";
    }
    
    return 0;
}