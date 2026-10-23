#include "TextDocument.h"
#include <stdexcept>

const std::string TextDocument::CLASS_NAME = "TextDocument";
int TextDocument::count_ = 0;
int TextDocument::idCounter_ = 0;

// убирает лишние пробелы; пустой или слишком длинный текст -> исключение
std::string TextDocument::normalize(const std::string& text) {
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

TextDocument::TextDocument()
    : id_("doc-" + std::to_string(++idCounter_)), size_(0), content_(""),
      history_(new int[HISTORY_SIZE]{}), historyCount_(0) {
    ++count_;
    std::cout << "  + default ctor  " << id_ << " | objects: " << count_ << '\n';
}

TextDocument::TextDocument(const std::string& content)
    : id_("doc-" + std::to_string(++idCounter_)), size_(0), content_(normalize(content)),
      history_(new int[HISTORY_SIZE]{}), historyCount_(0) {
    size_ = (int)content_.size();
    ++count_;
    std::cout << "  + init ctor     " << id_ << " | objects: " << count_ << '\n';
}

TextDocument::TextDocument(const TextDocument& other)
    : id_("doc-" + std::to_string(++idCounter_)), size_(other.size_), content_(other.content_),
      history_(new int[HISTORY_SIZE]), historyCount_(other.historyCount_) {
    for (int i = 0; i < HISTORY_SIZE; ++i) history_[i] = other.history_[i];
    ++count_;
    std::cout << "  + copy ctor     " << id_ << " <- " << other.id_ << " | objects: " << count_ << '\n';
}

TextDocument& TextDocument::operator=(const TextDocument& other) {
    std::cout << "  = assignment    " << id_ << " <- " << other.id_ << " | objects: " << count_ << '\n';
    if (this == &other) return *this;
    size_ = other.size_;
    content_ = other.content_;
    historyCount_ = other.historyCount_;
    for (int i = 0; i < HISTORY_SIZE; ++i) history_[i] = other.history_[i];
    return *this;
}

TextDocument::~TextDocument() {
    delete[] history_;
    --count_;
    std::cout << "  - destructor    " << id_ << " | objects: " << count_ << '\n';
}

int TextDocument::getHistory(int i) const {
    if (i < 0 || i >= historyCount_) return -1;
    return history_[i];
}

void TextDocument::setContent(const std::string& content) {
    std::string clean = normalize(content);
    if (historyCount_ == HISTORY_SIZE) {
        for (int i = 1; i < HISTORY_SIZE; ++i) history_[i - 1] = history_[i];
        --historyCount_;
    }
    history_[historyCount_++] = size_;
    content_ = clean;
    size_ = (int)content_.size();
}

void TextDocument::print() const {
    std::cout << "  id: " << id_ << '\n'
              << "  content: \"" << content_ << "\"\n"
              << "  size: " << size_ << '\n'
              << "  history: {";
    for (int i = 0; i < historyCount_; ++i) std::cout << (i ? ", " : "") << history_[i];
    std::cout << "}\n";
}

void TextDocument::printCount() {
    std::cout << "Totally documents: " << count_ << '\n';
}

std::ostream& operator<<(std::ostream& out, const TextDocument& doc) {
    out << TextDocument::CLASS_NAME << " [" << doc.id_ << "] \"" << doc.content_
        << "\" size=" << doc.size_ << " history={";
    for (int i = 0; i < doc.historyCount_; ++i) out << (i ? ", " : "") << doc.history_[i];
    out << "} | objects: " << TextDocument::getCount();
    return out;
}

std::istream& operator>>(std::istream& in, TextDocument& doc) {
    std::string line;
    if (std::getline(in, line)) doc.setContent(line);
    return in;
}
