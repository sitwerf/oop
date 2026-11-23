#include "Documents.h"

#include <iostream>
#include <utility>

TextDocument::TextDocument(int size) : size_(size > 0 ? size : 1) {}

void TextDocument::show_size() const {
    std::cout << "text document size: " << size_ << '\n';
}

RtfDocument::RtfDocument(int size, std::string style)
    : TextDocument(size), style_(std::move(style)) {}

void RtfDocument::show_size() const {
    std::cout << "rtf document size: " << size_
              << ", style: " << style_ << '\n';
}

StyledImageDocument::StyledImageDocument(int size,
                                         std::string style,
                                         std::string image)
    : RtfDocument(size, std::move(style)), image_(std::move(image)) {}

void StyledImageDocument::show_size() const {
    std::cout << "styled image document size: " << size_
              << ", style: " << style_
              << ", image: " << image_ << '\n';
}
