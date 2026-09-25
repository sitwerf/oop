#include <array>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <random>
#include "header.h"
#include <fstream>
#include <string>

int main() {
    const int M = 12;

    std::array<float, M> arr;
    std::vector<long> arrres(M);

    std::vector<float> v(M);
    std::list<long> vres;

    std::list<float> lst(M);
    std::deque<long> lstres;

    std::deque<float> d(M);
    std::array<long, M> dres;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> n(-40, 40);

    for (int i = 0; i < M; i++) {     // array - классический for
        arr[i] = n(gen);
    }

    for (std::list<float>::iterator it = lst.begin();
         it != lst.end();
         ++it) {                       // list - итераторы

        *it = n(gen);
    }

    for (float& x : v) {               // vector - range-based
        x = n(gen);
    }

    for (float& x : d) {               // deque - range-based
        x = n(gen);
    }

    for (int i = 0; i < M; i++) {      // array -> vector
        arrres[i] = temper_mod<long, float>(arr[i]);
    }

    for (float x : v) {                // vector -> list
        vres.push_back(temper_mod<long, float>(x));
    }

    for (std::list<float>::iterator it = lst.begin();
         it != lst.end();
         ++it) {                        // list -> deque

        lstres.push_back(
            temper_mod<long, float>(*it)
        );
    }

    for (int i = 0; i < M; i++) {      // deque -> array
        dres[i] = temper_mod<long, float>(d[i]);
    }
    
    std::vector<std::string> rows;

    std::list<float>::iterator lstIt = lst.begin();
    std::list<long>::iterator vresIt = vres.begin();

    for (int i = 0; i < M; i++) {

        std::string row =
            std::to_string(arr[i]) + " | " +
            std::to_string(arrres[i]) + " | " +

            std::to_string(v[i]) + " | " +
            std::to_string(*vresIt) + " | " +

            std::to_string(*lstIt) + " | " +
            std::to_string(lstres[i]) + " | " +

            std::to_string(d[i]) + " | " +
            std::to_string(dres[i]);

        rows.push_back(row);

        ++lstIt;
        ++vresIt;
    }

    std::ofstream file("table.md");

    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла\n";
        return 1;
    }

    file << "| array | array result | vector | vector result | "
            "list | list result | deque | deque result |\n";

    file << "|---|---|---|---|---|---|---|---|\n";

    for (const std::string& row : rows) {
        file << "| " << row << " |\n";
    }

    file.close();

    std::cout << "Таблица записана в файл table.md\n";

    return 0;
}