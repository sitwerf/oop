#pragma once

#include <string>

namespace problem {

class TextDocument {
public:
    explicit TextDocument(int size);
    int getSize() const { return size_; }

private:
    int size_;
};

class RtfDocument : public TextDocument {
public:
    RtfDocument(int size, std::string style);
    const std::string& getStyle() const { return style_; }

private:
    std::string style_;
};

class ImageDocument : public TextDocument {
public:
    ImageDocument(int size, std::string image);
    const std::string& getImage() const { return image_; }

private:
    std::string image_;
};

class StyledImageDocument : public RtfDocument, public ImageDocument {
public:
    StyledImageDocument(int size, std::string style, std::string image);
};

}

namespace solution {

class TextDocument {
public:
    explicit TextDocument(int size);
    int getSize() const { return size_; }

private:
    int size_;
};

class RtfDocument : virtual public TextDocument {
public:
    RtfDocument(int size, std::string style);
    const std::string& getStyle() const { return style_; }

private:
    std::string style_;
};

class ImageDocument : virtual public TextDocument {
public:
    ImageDocument(int size, std::string image);
    const std::string& getImage() const { return image_; }

private:
    std::string image_;
};

class StyledImageDocument : public RtfDocument, public ImageDocument {
public:
    StyledImageDocument(int size, std::string style, std::string image);
};

}
