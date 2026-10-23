#pragma once
#include <string>

class TextDocument {
public:
    static constexpr int HISTORY_SIZE = 10;     // сколько прошлых размеров храним
    static constexpr int MAX_SIZE = 50;         // максимальная длина текста

    TextDocument();
    explicit TextDocument(const std::string& content);
    TextDocument(const TextDocument& other);
    TextDocument& operator=(const TextDocument& other);
    ~TextDocument();

    // геттеры
    const std::string& getId() const { return id_; }
    int getSize() const { return size_; }
    const std::string& getContent() const { return content_; }
    int getHistoryCount() const { return historyCount_; }
    int getHistory(int i) const;

    // сеттер: размер и история меняются вместе с текстом
    void setContent(const std::string& content);

    void print() const;

private:
    const std::string id_;          // уникальный, не меняется
    int size_;                      // длина текста, >= 0
    std::string content_;           // текст
    int* history_;                  // массив из HISTORY_SIZE прошлых размеров
    int historyCount_;              // сколько из них заполнено

    static int counter_;            // для генерации уникальных id

    void normalize();               // приводит поля к правильным значениям
};
