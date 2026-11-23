#pragma once

#include <string>

class TextDocument;

class Administrator {
public:
    void setAuthor(TextDocument& document, const std::string& author) const;
    void setText(TextDocument& document, const std::string& text) const;
};

class Creator {
public:
    void setAll(TextDocument& document,
                const std::string& id,
                const std::string& author,
                const std::string& text) const;
};

class TextDocument {
public:
    TextDocument();
    TextDocument(std::string id, std::string author, std::string text);
    TextDocument(const TextDocument& other);
    ~TextDocument();

    TextDocument& operator=(const TextDocument& other);

    const std::string& getId() const { return id_; }
    const std::string& getAuthor() const { return author_; }
    const std::string& getText() const { return text_; }
    int getSize() const { return size_; }

    void print() const;

    friend void setCreatorName(TextDocument& document, const std::string& name);
    friend class Creator;
    friend void Administrator::setAuthor(TextDocument& document,
                                         const std::string& author) const;
    friend void Administrator::setText(TextDocument& document,
                                       const std::string& text) const;

private:
    std::string id_;
    std::string author_;
    std::string text_;
    int size_;

    static std::string validText(const std::string& text);
};

void setCreatorName(TextDocument& document, const std::string& name);
