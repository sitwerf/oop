#include "Documents.h"

#include <iostream>

int main() {
    std::cout << "--- diamond problem ---\n";
    problem::StyledImageDocument bad(20, "bold", "cat.png");
    const problem::TextDocument* left =
        static_cast<const problem::RtfDocument*>(&bad);
    const problem::TextDocument* right =
        static_cast<const problem::ImageDocument*>(&bad);
    std::cout << "rtf size: " << left->getSize() << '\n';
    std::cout << "image size: " << right->getSize() << '\n';
    std::cout << "two base addresses: " << left << " and " << right << '\n';

    std::cout << "\n--- virtual inheritance ---\n";
    solution::StyledImageDocument good(20, "bold", "cat.png");
    const solution::TextDocument* fromRtf =
        static_cast<const solution::RtfDocument*>(&good);
    const solution::TextDocument* fromImage =
        static_cast<const solution::ImageDocument*>(&good);
    std::cout << "size: " << good.getSize() << '\n';
    std::cout << "style: " << good.getStyle() << '\n';
    std::cout << "image: " << good.getImage() << '\n';
    std::cout << "one base address: " << fromRtf << " and " << fromImage << '\n';
    return 0;
}
