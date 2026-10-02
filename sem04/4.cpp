#include "4.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric>


std::vector<int> readf(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<int> numbers;
    std::string line;

    while (std::getline(file, line)) {
        for (char& c : line) {
            if (c == ',') {
                c = ' ';
            }
        }

        std::stringstream ss(line);
        int value;
        while (ss >> value) {
            numbers.push_back(value);
        }
    }
    return numbers;
}

void countfor(const std::vector<int>& v) {
    std::vector<int> processed;

    for (int x : v) {
        bool already = false;

        for (int p : processed) {
            if (p == x) {
                already = true;
                break;
            }
        }
        if (already) continue;

        int count = 0;
        for (int y : v) {
            if (y == x) {
                count++;
            }
        }
        std::cout << x << " - " << count << '\n';
        processed.push_back(x);
    }
}

void countalg(const std::vector<int>& v) {
    std::vector<int> processed;

    for (int x : v) {
        if (std::find(processed.begin(), processed.end(), x) != processed.end()) continue;

        int count = std::count(v.begin(), v.end(), x);
        std::cout << x << " - " << count << '\n';
        processed.push_back(x);
    }
}

int sumalg(const std::vector<int>& v) {
    int sum = 0;

    std::for_each(v.begin(), v.end(), [&sum](int x) {sum += x;});
    return sum;
}


int sumnum(const std::vector<int>& v) {
    return std::accumulate(v.begin(), v.end(), 0);
}


int sum10(const std::vector<int>& v) {
    return std::accumulate(v.begin(), v.begin() + 10, 0);
}

//4.2
int binacc(const std::vector<int>& v) {
    return std::accumulate(v.begin(), v.end(), 0, [](int sum, int x) {
            if (std::abs(x) > 22) return sum + x;
            return sum;
        }
    );
}

void finddups(const std::vector<int>& v1, const std::vector<int>& v2) {

    std::vector<int> processed;
    std::cout << "\nЧисла v2 повторяющиеся >= 2 раз:\n";

    for (int x : v2) {

        if (std::find(processed.begin(), processed.end(), x) != processed.end()) continue;
        int count = std::count(v2.begin(), v2.end(), x);
        if (count >= 2) {
            std::cout << x << " -> " << count << '\n';
        }
        processed.push_back(x);
    }
    processed.clear();

    std::cout << "\nЧисла в v1 повторяющиеся > 3 раз:\n";

    for (int x : v1) {

        if (std::find(processed.begin(), processed.end(), x) != processed.end()) continue;

        int count = std::count(v1.begin(), v1.end(), x);

        if (count > 3) {
            std::cout << x << " -> " << count << '\n';
        }
        processed.push_back(x);
    }
}

void dupfor(const std::vector<int>& v1, const std::vector<int>& v2) {

    std::vector<int> processed;
    std::cout << "\nFOR:\n";

    for (int x : v2) {
        bool already = false;

        for (int p : processed) {
            if (p == x) {
                already = true;
                break;
            }
        }

        if (already) continue;

        int count2 = 0;

        for (int y : v2) {
            if (y == x) {
                count2++;
            }
        }

        int count1 = 0;

        for (int y : v1) {
            if (y == x) {
                count1++;
            }
        }

        if (count2 >= 2 && count1 > 3) {
            std::cout << x << " | v1: " << count1 << " | v2: " << count2 << '\n';
        }
        processed.push_back(x);
    }
}

void dupalg(const std::vector<int>& v1, const std::vector<int>& v2) {

    std::vector<int> processed;
    std::cout << "\nalgorithm + lambda:\n";

    std::for_each(v2.begin(), v2.end(), [&](int x) {
            if (std::find(processed.begin(), processed.end(),x) != processed.end()) {
                return;
            }
            int count2 = std::count(v2.begin(), v2.end(), x);
            int count1 = std::count(v1.begin(), v1.end(), x);

            if (count2 >= 2 && count1 > 3) {
                std::cout << x << " | v1: " << count1 << " | v2: " << count2 << '\n';
            }
            processed.push_back(x);
        }
    );
}