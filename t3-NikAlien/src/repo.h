#pragma once
#include "domain.h"
#include "vector"

class Repository {

private:
    std::vector<Document> docs;
    void readFile();

public:
    Repository();
    std::vector<Document> getAll() const {return this->docs;}
};
