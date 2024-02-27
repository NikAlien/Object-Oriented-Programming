#pragma once
#include "exception"
#include "string"

class RepoException : public std::exception
{
private:
    std::string errors;

public:
    RepoException(const std::string& e);
    std::string getErrors() const;
};

class FileException : public std::exception
{
private:
    std::string errors;

public:
    FileException(const std::string& e);
    std::string getErrors() const;
};

