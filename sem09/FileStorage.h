#pragma once

#include "TextDocument.h"

#include <vector>

class CompositionStorage {
public:
    CompositionStorage();
    void add(const TextDocument& document);
    void print() const;

private:
    std::vector<TextDocument> documents_;
};

class AggregationStorage {
public:
    AggregationStorage();
    void add(const TextDocument& document);
    void print() const;

private:
    std::vector<const TextDocument*> documents_;
};
