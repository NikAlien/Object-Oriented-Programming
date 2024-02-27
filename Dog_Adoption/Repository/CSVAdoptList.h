#pragma once
#include "FileAdoptList.h"
#include <string>

class CSVAdoptList :
        public FileAdoptList{
public:
    CSVAdoptList(const std::string &_filename, const std::string &_repofilename);
    void writeToFile() const override;
    void displayList() const override;
};

