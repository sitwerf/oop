#include <iostream>
#include "TextDocument.h"

int main() {
    std::cout << "--- a: default\n";
    TextDocument a;
    a.print();

    std::cout << "--- b: initialization (with extra spaces)\n";
    TextDocument b("  Hello,    world  ");
    b.print();

    std::cout << "--- c = b: copy (new object)\n";
    TextDocument c = b;
    c.print();

    std::cout << "--- d(b): copy (new object)\n";
    TextDocument d(b);
    d.print();

    std::cout << "--- a = b: assignment (a already exists)\n";
    a = b;
    a.print();

    std::cout << "--- a = a: self-assignment\n";
    a = a;

    std::cout << "--- setContent: history\n";
    a.setContent("Second version");
    a.setContent("Third");
    a.print();

    std::cout << "--- end\n";
    return 0;
}
