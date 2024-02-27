#pragma once
#include "string"

class Document {

private:
    std::string name;
    std::string keywords;
    std::string content;

public:
    Document(std::string n, std::string k, std::string c) : name(n), keywords(k), content(c) {};
    std::string getName() const {return this->name;}
    std::string getKeywords() const {return this->keywords;}
    std::string getContent() const {return this->content;}

    std::string toString();
};
