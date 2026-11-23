#include "FileStorage.h"
#include "TextDocument.h"

#include <iostream>

int main() {
    TextDocument document("doc-1", "alice", "first text");
    TextDocument second("doc-3", "eve", "second text");

    std::cout << "\n--- friend function ---\n";
    setCreatorName(document, "bob");
    document.print();

    std::cout << "\n--- friend class ---\n";
    Creator creator;
    creator.setAll(document, "doc-2", "carol", "created text");
    document.print();

    std::cout << "\n--- friend methods ---\n";
    Administrator administrator;
    administrator.setAuthor(document, "dave");
    administrator.setText(document, "edited text");
    document.print();

    std::cout << "\n--- composition ---\n";
    CompositionStorage owned;
    owned.add(document);
    owned.add(second);
    owned.print();

    std::cout << "\n--- aggregation ---\n";
    AggregationStorage linked;
    linked.add(document);
    linked.add(second);
    linked.print();

    std::cout << "\ncomposition stores a copy; aggregation stores an external address\n";
    return 0;
}
