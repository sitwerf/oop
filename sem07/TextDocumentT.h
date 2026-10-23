#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

// шаблонная версия TextDocument: T - тип размера и истории (int, unsigned, long ...)
template <typename T>
class TextDocumentT {
public:
    static constexpr int HISTORY_SIZE = 10;
    static constexpr int MAX_SIZE = 50;
    static const std::string CLASS_NAME;

    TextDocumentT();
    explicit TextDocumentT(const std::string& content);
    TextDocumentT(const TextDocumentT& other);
    TextDocumentT& operator=(const TextDocumentT& other);
    ~TextDocumentT();

    void setContent(const std::string& content);

    // геттеры
    const std::string& getId() const { return id_; }
    T getSize() const { return size_; }
    const std::string& getContent() const { return content_; }
    static int getCount() { return count_; }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const TextDocumentT<U>& doc);

private:
    const std::string id_;
    T size_;
    std::string content_;
    T* history_;                  // массив из HISTORY_SIZE прошлых размеров
    int historyCount_;

    static int count_;
    static int idCounter_;

    static std::string normalize(const std::string& text);
};

// ---------- определения вне класса ----------

template <typename T>
const std::string TextDocumentT<T>::CLASS_NAME = "TextDocumentT";

template <typename T>
int TextDocumentT<T>::count_ = 0;

template <typename T>
int TextDocumentT<T>::idCounter_ = 0;

template <typename T>
std::string TextDocumentT<T>::normalize(const std::string& text) {
    std::string result;
    for (char c : text) {
        if (c == ' ' && (result.empty() || result.back() == ' ')) continue;
        result += c;
    }
    if (!result.empty() && result.back() == ' ') result.pop_back();

    if (result.empty()) throw std::invalid_argument("text is empty");
    if ((int)result.size() > MAX_SIZE) throw std::invalid_argument("text is too long");
    return result;
}

template <typename T>
TextDocumentT<T>::TextDocumentT()
    : id_("tdoc-" + std::to_string(++idCounter_)), size_(0), content_(""),
      history_(new T[HISTORY_SIZE]{}), historyCount_(0) {
    ++count_;
    std::cout << "  + default ctor  " << id_ << " | objects: " << count_ << '\n';
}

template <typename T>
TextDocumentT<T>::TextDocumentT(const std::string& content)
    : id_("tdoc-" + std::to_string(++idCounter_)), size_(0), content_(normalize(content)),
      history_(new T[HISTORY_SIZE]{}), historyCount_(0) {
    size_ = (T)content_.size();
    ++count_;
    std::cout << "  + init ctor     " << id_ << " | objects: " << count_ << '\n';
}

template <typename T>
TextDocumentT<T>::TextDocumentT(const TextDocumentT& other)
    : id_("tdoc-" + std::to_string(++idCounter_)), size_(other.size_), content_(other.content_),
      history_(new T[HISTORY_SIZE]), historyCount_(other.historyCount_) {
    for (int i = 0; i < HISTORY_SIZE; ++i) history_[i] = other.history_[i];
    ++count_;
    std::cout << "  + copy ctor     " << id_ << " <- " << other.id_ << " | objects: " << count_ << '\n';
}

template <typename T>
TextDocumentT<T>& TextDocumentT<T>::operator=(const TextDocumentT& other) {
    std::cout << "  = assignment    " << id_ << " <- " << other.id_ << " | objects: " << count_ << '\n';
    if (this == &other) return *this;
    size_ = other.size_;
    content_ = other.content_;
    historyCount_ = other.historyCount_;
    for (int i = 0; i < HISTORY_SIZE; ++i) history_[i] = other.history_[i];
    return *this;
}

template <typename T>
TextDocumentT<T>::~TextDocumentT() {
    delete[] history_;
    --count_;
    std::cout << "  - destructor    " << id_ << " | objects: " << count_ << '\n';
}

template <typename T>
void TextDocumentT<T>::setContent(const std::string& content) {
    std::string clean = normalize(content);
    if (historyCount_ == HISTORY_SIZE) {
        for (int i = 1; i < HISTORY_SIZE; ++i) history_[i - 1] = history_[i];
        --historyCount_;
    }
    history_[historyCount_++] = size_;
    content_ = clean;
    size_ = (T)content_.size();
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const TextDocumentT<T>& doc) {
    out << TextDocumentT<T>::CLASS_NAME << " [" << doc.id_ << "] \"" << doc.content_
        << "\" size=" << doc.size_ << " history={";
    for (int i = 0; i < doc.historyCount_; ++i) out << (i ? ", " : "") << doc.history_[i];
    out << "} | objects: " << TextDocumentT<T>::getCount();
    return out;
}
