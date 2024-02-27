//
// Created by Carp Nicoleta on 25.05.2023.
//

#include "repo.h"
#include "sstream"
#include "fstream"
#include "vector"

Repository::Repository() {
    this->readFile();
}

void Repository::readFile() {
    std::string line;
    std::vector<std::string> result;
    std::ifstream fin("/Users/carpnicoleta/Documents/GitHub/t3-NikAlien/src/doc.txt");

    while(getline(fin, line)) {
        std::stringstream ss(line);
        std::string take;
        while (getline(ss, take, '|')) {
            result.push_back(take);
        }
        Document d(result[0], result[1], result[2]);
        this->docs.push_back(d);
        result.clear();
    }
}
