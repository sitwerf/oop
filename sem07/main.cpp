#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <stdexcept>
#include "TextDocument.h"
#include "TextDocumentT.h"

void line(const std::string& title) {
    std::cout << "\n========== " << title << " ==========\n";
}

// 1: создание, копирование, область видимости
void demo() {
    std::cout << "static values: " << std::endl;
    TextDocument::printCount();
    std::cout << TextDocument::CLASS_NAME << std::endl;
    std::cout << std::endl;

    std::cout << "Document creation: " << std::endl;
    TextDocument my_first_doc("The Wizard of Oz");
    my_first_doc.print();
    my_first_doc.printCount();
    std::cout << my_first_doc << std::endl;

    std::cout << "Second document: " << std::endl;
    TextDocument my_second_doc{my_first_doc};
    std::cout << my_second_doc << std::endl;
    my_second_doc.setContent("The Wizard of Oz, part 2");
    my_first_doc.setContent("The Wizard of Oz, edited");
    my_second_doc.print();

    {
        std::cout << " inside {} " << std::endl;
        TextDocument my_second_doc{my_first_doc};
        std::cout << my_second_doc << std::endl;
        my_second_doc.setContent("Inner copy");
        my_first_doc.setContent("Edited again");
        my_second_doc.print();
    }

    std::cout << " outside {} " << std::endl;
    my_second_doc.print();
}

// 2: объекты в vector, list, set
void containers() {
    line("vector");
    {
        std::vector<TextDocument> v;
        for (int i = 1; i <= 4; ++i) v.push_back(TextDocument("vec " + std::to_string(i)));
        line("vector destroyed");
    }

    line("list");
    {
        std::list<TextDocument> l;
        for (int i = 1; i <= 4; ++i) l.push_back(TextDocument("list " + std::to_string(i)));
        line("list destroyed");
    }

    line("set");
    {
        std::set<TextDocument> s;
        s.insert(TextDocument("banana"));
        s.insert(TextDocument("apple"));
        s.insert(TextDocument("cherry"));
        s.insert(TextDocument("apple"));
        std::cout << "set size: " << s.size() << '\n';
        line("set destroyed");
    }

    line("end");
    std::cout << "objects: " << TextDocument::getCount() << '\n';
}

// 3: исключения при нормализации, операторы >> и <<
void input() {
    line("input");
    TextDocument doc("First draft");
    std::cout << doc << '\n';

    while (true) {
        std::cout << "enter text (1.." << TextDocument::MAX_SIZE << " chars): ";
        try {
            std::cin >> doc;
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << "error: " << e.what() << ", try again\n";
        }
    }
    std::cout << doc << '\n';

    line("end");
}

// 4: шаблонный класс
void templ() {
    line("TextDocumentT<unsigned>");
    TextDocumentT<unsigned> a("Hello template");
    TextDocumentT<unsigned> b = a;
    b.setContent("Changed text");
    std::cout << a << '\n';
    std::cout << b << '\n';

    line("assignment");
    TextDocumentT<unsigned> c;
    c = b;
    std::cout << c << '\n';

    line("TextDocumentT<long>");
    TextDocumentT<long> d("Other type");
    std::cout << d << '\n';

    line("end");
}

int main(int argc, char* argv[]) {
    int task = (argc > 1) ? std::stoi(argv[1]) : 0;
    switch (task) {
        case 1: demo(); break;
        case 2: containers(); break;
        case 3: input(); break;
        case 4: templ(); break;
        default: std::cout << "usage: ./app 1|2|3|4\n";
    }
    return 0;
}
