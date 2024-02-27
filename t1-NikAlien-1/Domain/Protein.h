#pragma once
#include <string>

class Protein {
private:
    std::string organism;
    std::string name;
    std::string sequence;
public:
    Protein();
    Protein(const std::string org, const std::string name, const std::string seq);

    std::string getOrganism() const;
    std::string getName() const;
    std::string getSequence() const;


};



