#include <iostream>
#include <vector>
#include "4.h"

int main() {
    
    std::vector<int> v1 = readf("s04_v1_44_1.txt");
    std::vector<int> v2 = readf("s04_v1_44_2.txt");

    std::cout << "v1 size: " << v1.size() << '\n';
    std::cout << "v2 size: " << v2.size() << '\n';

    std::cout << "\ncount with for\n";
    std::cout << "\nv1:\n";
    countfor(v1);
    std::cout << "\nv2:\n";
    countfor(v2);

    std::cout << "\ncount with algorithm\n";
    std::cout << "\nv1:\n";
    countalg(v1);
    std::cout << "\nv2:\n";
    countalg(v2);

    std::cout << "\nsum\n";
    std::cout << "v1 sum algorithm: " << sumalg(v1) << '\n';
    std::cout << "v2 sum algorithm: " << sumalg(v2) << '\n';
    std::cout << "v1 sum numeric: " << sumnum(v1) << '\n';
    std::cout << "v2 sum numeric: " << sumnum(v2) << '\n';

    std::cout << "\nfirst 10 sum\n";
    std::cout << "v1 first 10: " << sum10(v1) << '\n';
    std::cout << "v2 first 10: " << sum10(v2) << '\n';

    std::cout << "4.2 homework\n";

    std::cout << "\nbinary operation\n";        //1. бинарная операция
    std::cout << "v1: " << binacc(v1) << '\n';
    std::cout << "v2: " << binacc(v2) << '\n';

    std::cout << "\nduplicates\n";      // 2. повторяющиеся числа
    finddups(v1, v2);

    std::cout << "\ncommon duplicates\n"; 
    dupfor(v1, v2);     // 3a. через for
    dupalg(v1, v2);     // 3b. через algorithm + lambda
    return 0;
}