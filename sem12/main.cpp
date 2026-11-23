#include "Documents.h"

#include <array>
#include <iostream>

int main() {
    TextDocument text(10);
    RtfDocument rtf(20, "bold");
    StyledImageDocument rich(30, "italic", "cat.png");

    std::cout << "--- polymorphic array ---\n";
    const std::array<const File*, 3> files{&text, &rtf, &rich};
    for (const File* file : files) {
        file->show_size();
    }

    std::cout << "\n--- non-polymorphic array ---\n";
    const std::array<TextDocument, 3> sliced{text, rtf, rich};
    for (const TextDocument& document : sliced) {
        document.show_size();
    }

    std::cout << "\nthe abstract File class cannot have its own object\n";
    return 0;
}
