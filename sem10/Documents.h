#pragma once

#include <string>

class TextDocument {
public:
    explicit TextDocument(std::string text);

    int getSize() const { return size_; }
    const std::string& getText() const { return text_; }

private:
    std::string text_;
    int size_;
};

class RtfDocument : public TextDocument {
public:
    RtfDocument(std::string text, std::string style);

    void showStyle() const;

private:
    std::string style_;
};

class StyledImageDocument final : private RtfDocument {
public:
    StyledImageDocument(std::string text,
                        std::string style,
                        std::string image);

    using RtfDocument::showStyle;
    void showImage() const;

private:
    std::string image_;
};
