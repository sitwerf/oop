#include "TextDocument.h"

#include <iostream>
#include <utility>

int main() {
    std::cout << "\n--- constructors ---\n";
    TextDocument source("first version");
    source.setContent("second version");

    TextDocument copied(source);
    TextDocument moved(std::move(source));

    copied.print();
    moved.print();
    source.print();

    std::cout << "\n--- assignment ---\n";
    TextDocument copyTarget;
    copyTarget = copied;

    TextDocument moveTarget;
    moveTarget = std::move(moved);

    copyTarget.print();
    moveTarget.print();
    moved.print();

    std::cout << "\ncopy keeps the source, move leaves it empty\n";
    return 0;
}
