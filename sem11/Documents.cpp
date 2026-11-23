#include "Documents.h"

#include <utility>

namespace problem {

TextDocument::TextDocument(int size) : size_(size > 0 ? size : 1) {}

RtfDocument::RtfDocument(int size, std::string style)
    : TextDocument(size), style_(std::move(style)) {}

ImageDocument::ImageDocument(int size, std::string image)
    : TextDocument(size), image_(std::move(image)) {}

StyledImageDocument::StyledImageDocument(int size,
                                         std::string style,
                                         std::string image)
    : RtfDocument(size, std::move(style)),
      ImageDocument(size, std::move(image)) {}

}

namespace solution {

TextDocument::TextDocument(int size) : size_(size > 0 ? size : 1) {}

RtfDocument::RtfDocument(int size, std::string style)
    : TextDocument(size), style_(std::move(style)) {}

ImageDocument::ImageDocument(int size, std::string image)
    : TextDocument(size), image_(std::move(image)) {}

StyledImageDocument::StyledImageDocument(int size,
                                         std::string style,
                                         std::string image)
    : TextDocument(size),
      RtfDocument(size, std::move(style)),
      ImageDocument(size, std::move(image)) {}

}
