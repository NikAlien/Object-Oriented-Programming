#pragma once
#include "repo.h"

class Service {

private:
    Repository* repo;
public:
    Service(Repository* r) : repo(r) {};
    std::vector<Document> getDocList() const;
    std::vector<Document> filterDocList(std::string fil) const;
    Document bestMatching(std::string name);

};
