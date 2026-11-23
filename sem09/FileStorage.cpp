#include "FileStorage.h"

#include <iostream>

CompositionStorage::CompositionStorage() {
    documents_.reserve(2);
}

void CompositionStorage::add(const TextDocument& document) {
    documents_.push_back(document);
}

void CompositionStorage::print() const {
    std::cout << "composition owns " << documents_.size() << " document(s)\n";
    for (const TextDocument& document : documents_) {
        document.print();
    }
}

AggregationStorage::AggregationStorage() {
    documents_.reserve(2);
}

void AggregationStorage::add(const TextDocument& document) {
    documents_.push_back(&document);
}

void AggregationStorage::print() const {
    std::cout << "aggregation refers to " << documents_.size() << " document(s)\n";
    for (const TextDocument* document : documents_) {
        document->print();
    }
}
