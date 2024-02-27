//
// Created by Carp Nicoleta on 03.05.2023.
//

#include "RepoException.h"

RepoException::RepoException(const std::string &e) {
    this->errors = e;
}

std::string RepoException::getErrors() const {
    return this->errors;
}

FileException::FileException(const std::string &e) {
    this->errors = e;
}

std::string FileException::getErrors() const {
    return this->errors;
}
