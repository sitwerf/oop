#include "TextDocument.h"

#include <iostream>
#include <stdexcept>
#include <utility>

const std::string TextDocument::CLASS_NAME = "TextDocument";
int TextDocument::count_ = 0;
int TextDocument::idCounter_ = 0;

std::string TextDocument::normalize(const std::string& text) {
    std::string result;
    for (char c : text) {
        if (c == ' ' && (result.empty() || result.back() == ' ')) {
            continue;
        }
        result += c;
    }
    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }
    if (result.empty()) {
        throw std::invalid_argument("text is empty");
    }
    if (static_cast<int>(result.size()) > MAX_SIZE) {
        throw std::invalid_argument("text is too long");
    }
    return result;
}

void TextDocument::ensureHistory() {
    if (history_ == nullptr) {
        history_ = new int[HISTORY_SIZE]{};
    }
}

TextDocument::TextDocument()
    : id_("doc-" + std::to_string(++idCounter_)),
      size_(0),
      content_(""),
      history_(new int[HISTORY_SIZE]{}),
      historyCount_(0) {
    ++count_;
    std::cout << "+ default  " << id_ << " | objects: " << count_ << '\n';
}

TextDocument::TextDocument(const std::string& content)
    : id_("doc-" + std::to_string(++idCounter_)),
      size_(0),
      content_(normalize(content)),
      history_(new int[HISTORY_SIZE]{}),
      historyCount_(0) {
    size_ = static_cast<int>(content_.size());
    ++count_;
    std::cout << "+ init     " << id_ << " | objects: " << count_ << '\n';
}

TextDocument::TextDocument(const TextDocument& other)
    : id_("doc-" + std::to_string(++idCounter_)),
      size_(other.size_),
      content_(other.content_),
      history_(new int[HISTORY_SIZE]{}),
      historyCount_(other.historyCount_) {
    for (int i = 0; i < historyCount_; ++i) {
        history_[i] = other.history_[i];
    }
    ++count_;
    std::cout << "+ copy     " << id_ << " <- " << other.id_
              << " | objects: " << count_ << '\n';
}

TextDocument::TextDocument(TextDocument&& other) noexcept
    : id_("doc-" + std::to_string(++idCounter_)),
      size_(other.size_),
      content_(std::move(other.content_)),
      history_(other.history_),
      historyCount_(other.historyCount_) {
    other.size_ = 0;
    other.history_ = nullptr;
    other.historyCount_ = 0;
    ++count_;
    std::cout << "+ move     " << id_ << " <- " << other.id_
              << " | objects: " << count_ << '\n';
}

TextDocument& TextDocument::operator=(const TextDocument& other) {
    std::cout << "= copy     " << id_ << " <- " << other.id_
              << " | objects: " << count_ << '\n';
    if (this == &other) {
        return *this;
    }
    ensureHistory();
    size_ = other.size_;
    content_ = other.content_;
    historyCount_ = other.historyCount_;
    for (int i = 0; i < historyCount_; ++i) {
        history_[i] = other.history_[i];
    }
    return *this;
}

TextDocument& TextDocument::operator=(TextDocument&& other) noexcept {
    std::cout << "= move     " << id_ << " <- " << other.id_
              << " | objects: " << count_ << '\n';
    if (this == &other) {
        return *this;
    }
    delete[] history_;
    size_ = other.size_;
    content_ = std::move(other.content_);
    history_ = other.history_;
    historyCount_ = other.historyCount_;
    other.size_ = 0;
    other.history_ = nullptr;
    other.historyCount_ = 0;
    return *this;
}

TextDocument::~TextDocument() {
    delete[] history_;
    --count_;
    std::cout << "- destroy  " << id_ << " | objects: " << count_ << '\n';
}

void TextDocument::setContent(const std::string& content) {
    const std::string clean = normalize(content);
    ensureHistory();
    if (historyCount_ == HISTORY_SIZE) {
        for (int i = 1; i < HISTORY_SIZE; ++i) {
            history_[i - 1] = history_[i];
        }
        --historyCount_;
    }
    history_[historyCount_++] = size_;
    content_ = clean;
    size_ = static_cast<int>(content_.size());
}

int TextDocument::getHistory(int index) const {
    if (index < 0 || index >= historyCount_) {
        return -1;
    }
    return history_[index];
}

void TextDocument::print() const {
    std::cout << id_ << ": content=\"" << content_ << "\", size=" << size_
              << ", history=" << historyCount_ << '\n';
}
