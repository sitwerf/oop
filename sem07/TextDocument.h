#pragma once
#include <iostream>
#include <string>

class TextDocument {
public:
    static constexpr int HISTORY_SIZE = 10;     // сколько прошлых размеров храним
    static constexpr int MAX_SIZE = 50;         // максимальная длина текста
    static const std::string CLASS_NAME;    // имя класса

    TextDocument();
    explicit TextDocument(const std::string& content);
    TextDocument(const TextDocument& other);
    TextDocument& operator=(const TextDocument& other);
    ~TextDocument();

    void setContent(const std::string& content);

    // геттеры
    const std::string& getId() const { return id_; }
    int getSize() const { return size_; }
    const std::string& getContent() const { return content_; }
    int getHistoryCount() const { return historyCount_; }
    int getHistory(int i) const;
    static int getCount() { return count_; }

    void print() const;             // вывод всех полей
    static void printCount();       // вывод количества объектов

    // нужен для std::set
    bool operator<(const TextDocument& other) const { return content_ < other.content_; }

    friend std::ostream& operator<<(std::ostream& out, const TextDocument& doc);

private:
    const std::string id_;          // уникальный, не меняется
    int size_;                      // длина текста
    std::string content_;           // текст
    int* history_;                  // массив из HISTORY_SIZE прошлых размеров
    int historyCount_;              // сколько из них заполнено

    static int count_;              // сколько объектов существует сейчас
    static int idCounter_;          // сколько id уже выдано

    static std::string normalize(const std::string& text);
};

std::istream& operator>>(std::istream& in, TextDocument& doc);
