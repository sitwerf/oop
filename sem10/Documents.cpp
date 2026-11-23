#include "Documents.h"

#include <iostream>
#include <utility>

TextDocument::TextDocument(std::string text)
    : text_(std::move(text)), size_(static_cast<int>(text_.size())) {}

RtfDocument::RtfDocument(std::string text, std::string style)
    : TextDocument(std::move(text)), style_(std::move(style)) {}

void RtfDocument::showStyle() const {
    std::cout << "style: " << style_ << '\n';
}

StyledImageDocument::StyledImageDocument(std::string text,
                                         std::string style,
                                         std::string image)
    : RtfDocument(std::move(text), std::move(style)),
      image_(std::move(image)) {}

void StyledImageDocument::showImage() const {
    std::cout << "image: " << image_ << '\n';
}
