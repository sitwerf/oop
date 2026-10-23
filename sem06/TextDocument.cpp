#include "TextDocument.h"
#include <iostream>

int TextDocument::counter_ = 0;

// инвариант: нет лишних пробелов, длина не больше MAX_SIZE, size_ равен длине текста
void TextDocument::normalize() {
    std::string result;
    for (char c : content_) {
        if (c == ' ' && (result.empty() || result.back() == ' ')) continue;
        result += c;
    }
    if (!result.empty() && result.back() == ' ') result.pop_back();
    if ((int)result.size() > MAX_SIZE) result.resize(MAX_SIZE);

    content_ = result;
    size_ = (int)content_.size();
}

// конструктор по умолчанию
TextDocument::TextDocument()
    : id_("doc-" + std::to_string(++counter_)), size_(0), content_(""),
      history_(new int[HISTORY_SIZE]{}), historyCount_(0) {
    std::cout << "default constructor (" << id_ << ")\n";
}

// инициализирующий конструктор
TextDocument::TextDocument(const std::string& content)
    : id_("doc-" + std::to_string(++counter_)), size_(0), content_(content),
      history_(new int[HISTORY_SIZE]{}), historyCount_(0) {
    normalize();
    std::cout << "initialization constructor (" << id_ << ")\n";
}

// конструктор копирования: копия получает свой id и свой массив
TextDocument::TextDocument(const TextDocument& other)
    : id_("doc-" + std::to_string(++counter_)), size_(other.size_), content_(other.content_),
      history_(new int[HISTORY_SIZE]), historyCount_(other.historyCount_) {
    for (int i = 0; i < HISTORY_SIZE; ++i) history_[i] = other.history_[i];
    std::cout << "copy constructor (" << id_ << " <- " << other.id_ << ")\n";
}

// оператор присваивания: id_ не меняется, массив копируется поэлементно
TextDocument& TextDocument::operator=(const TextDocument& other) {
    std::cout << "assignment operator (" << id_ << " <- " << other.id_ << ")\n";
    if (this == &other) return *this;
    size_ = other.size_;
    content_ = other.content_;
    historyCount_ = other.historyCount_;
    for (int i = 0; i < HISTORY_SIZE; ++i) history_[i] = other.history_[i];
    return *this;
}

// деструктор: освобождаем память массива
TextDocument::~TextDocument() {
    delete[] history_;
    std::cout << "destructor (" << id_ << ")\n";
}

int TextDocument::getHistory(int i) const {
    if (i < 0 || i >= historyCount_) return -1;
    return history_[i];
}

void TextDocument::setContent(const std::string& content) {
    if (historyCount_ == HISTORY_SIZE) {
        for (int i = 1; i < HISTORY_SIZE; ++i) history_[i - 1] = history_[i];
        --historyCount_;
    }
    history_[historyCount_++] = size_;
    content_ = content;
    normalize();
}

void TextDocument::print() const {
    std::cout << "  [" << id_ << "] size=" << size_
              << " content=\"" << content_ << "\" history={";
    for (int i = 0; i < historyCount_; ++i) std::cout << (i ? ", " : "") << history_[i];
    std::cout << "}\n";
}
