#include <iostream>
#include <vector>
#include "4.h"

int main() {

    std::vector<int> v1 = readf("s04_v1_44_1.txt");
    std::vector<int> v2 = readf("s04_v1_44_2.txt");

    std::cout << "v1 размер: " << v1.size() << '\n';
    std::cout << "v2 размер: " << v2.size() << '\n';

    std::cout << "\nПодсчет с циклом for\n";
    std::cout << "\nv1:\n";
    countfor(v1);
    std::cout << "\nv2:\n";
    countfor(v2);

    std::cout << "\nПодсчет алгоритмом\n";
    std::cout << "\nv1:\n";
    countalg(v1);
    std::cout << "\nv2:\n";
    countalg(v2);

    std::cout << "\nСумма\n";
    std::cout << "v1 сумма algorithm: " << sumalg(v1) << '\n';
    std::cout << "v2 сумма algorithm: " << sumalg(v2) << '\n';
    std::cout << "v1 сумма numeric: " << sumnum(v1) << '\n';
    std::cout << "v2 сумма numeric: " << sumnum(v2) << '\n';

    std::cout << "\nCумма первых 10\n";
    std::cout << "v1 первые 10: " << sum10(v1) << '\n';
    std::cout << "v2 первые 10: " << sum10(v2) << '\n';

    std::cout << "\n4.2 homework\n";

    std::cout << "\nбинарная операция\n";        //1. бинарная операция
    std::cout << "v1: " << binacc(v1) << '\n';
    std::cout << "v2: " << binacc(v2) << '\n';

    std::cout << "\nПовторяющиеся числа\n";      // 2. повторяющиеся числа
    finddups(v1, v2);

    std::cout << "\nПовторяющиеся числа\n"; 
    dupfor(v1, v2);     // 3a. через for
    dupalg(v1, v2);     // 3b. через algorithm + lambda
    return 0;
}