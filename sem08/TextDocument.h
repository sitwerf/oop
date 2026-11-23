#pragma once

#include <string>

class TextDocument {
public:
    static constexpr int HISTORY_SIZE = 10;
    static constexpr int MAX_SIZE = 50;
    static const std::string CLASS_NAME;

    TextDocument();
    explicit TextDocument(const std::string& content);
    TextDocument(const TextDocument& other);
    TextDocument(TextDocument&& other) noexcept;
    TextDocument& operator=(const TextDocument& other);
    TextDocument& operator=(TextDocument&& other) noexcept;
    ~TextDocument();

    void setContent(const std::string& content);

    const std::string& getId() const { return id_; }
    int getSize() const { return size_; }
    const std::string& getContent() const { return content_; }
    int getHistoryCount() const { return historyCount_; }
    int getHistory(int index) const;
    static int getCount() { return count_; }

    void print() const;

private:
    const std::string id_;
    int size_;
    std::string content_;
    int* history_;
    int historyCount_;

    static int count_;
    static int idCounter_;

    static std::string normalize(const std::string& text);
    void ensureHistory();
};
