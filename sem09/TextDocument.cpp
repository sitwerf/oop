#include "TextDocument.h"

#include <iostream>
#include <stdexcept>
#include <utility>

std::string TextDocument::validText(const std::string& text) {
    if (text.empty()) {
        throw std::invalid_argument("text is empty");
    }
    return text;
}

TextDocument::TextDocument()
    : id_("doc"), author_("unknown"), text_("empty"), size_(5) {
    std::cout << "+ document " << id_ << '\n';
}

TextDocument::TextDocument(std::string id, std::string author, std::string text)
    : id_(id.empty() ? "doc" : std::move(id)),
      author_(author.empty() ? "unknown" : std::move(author)),
      text_(validText(text)),
      size_(static_cast<int>(text_.size())) {
    std::cout << "+ document " << id_ << '\n';
}

TextDocument::TextDocument(const TextDocument& other)
    : id_(other.id_),
      author_(other.author_),
      text_(other.text_),
      size_(other.size_) {
    std::cout << "+ copy " << id_ << '\n';
}

TextDocument::~TextDocument() {
    std::cout << "- document " << id_ << '\n';
}

TextDocument& TextDocument::operator=(const TextDocument& other) {
    if (this != &other) {
        id_ = other.id_;
        author_ = other.author_;
        text_ = other.text_;
        size_ = other.size_;
    }
    return *this;
}

void TextDocument::print() const {
    std::cout << id_ << ": author=" << author_ << ", text=\"" << text_
              << "\", size=" << size_ << '\n';
}

void setCreatorName(TextDocument& document, const std::string& name) {
    document.author_ = name.empty() ? "unknown" : name;
}

void Creator::setAll(TextDocument& document,
                     const std::string& id,
                     const std::string& author,
                     const std::string& text) const {
    document.id_ = id.empty() ? "doc" : id;
    document.author_ = author.empty() ? "unknown" : author;
    document.text_ = TextDocument::validText(text);
    document.size_ = static_cast<int>(document.text_.size());
}

void Administrator::setAuthor(TextDocument& document,
                              const std::string& author) const {
    document.author_ = author.empty() ? "unknown" : author;
}

void Administrator::setText(TextDocument& document,
                            const std::string& text) const {
    document.text_ = TextDocument::validText(text);
    document.size_ = static_cast<int>(document.text_.size());
}
