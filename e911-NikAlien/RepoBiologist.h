#pragma once
#include "vector"
#include "Biologist.h"


class RepoBiologist {

private:
    std::vector<Biologist> bios;

public:
    RepoBiologist();
    void readFromFile();
    std::vector<Biologist> getList() {return bios;}

};
