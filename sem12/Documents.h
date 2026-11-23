#pragma once

#include <string>

/// abstract file with size output.
class File {
public:
    /// destroys a file through a base pointer.
    virtual ~File() = default;

    /// prints the size for the actual file type.
    virtual void show_size() const = 0;
};

/// plain text document.
class TextDocument : public File {
public:
    /// creates a document with a positive size.
    explicit TextDocument(int size);

    /// prints plain text size.
    void show_size() const override;

protected:
    int size_;
};

/// text document with one style.
class RtfDocument : public TextDocument {
public:
    /// creates a styled document.
    RtfDocument(int size, std::string style);

    /// prints rtf size.
    void show_size() const override;

protected:
    std::string style_;
};

/// rtf document with an image.
class StyledImageDocument : public RtfDocument {
public:
    /// creates a styled document with an image.
    StyledImageDocument(int size, std::string style, std::string image);

    /// prints styled image size.
    void show_size() const override;

private:
    std::string image_;
};
