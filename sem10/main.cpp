#include "Documents.h"

#include <iostream>

int main() {
    RtfDocument rtf("simple text", "bold");
    rtf.showStyle();

    std::cout << "--- private final child ---\n";
    StyledImageDocument document("text with image", "italic", "cat.png");
    document.showStyle();
    document.showImage();
    return 0;
}
