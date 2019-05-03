#pragma once
#include <exception>
#include <string>

// Custom exception for the repository

class repository_exception : public std::exception {
private:
    std::string error_message;
public:
    repository_exception(std::string message) : error_message(message) {  }

    const char* what() const noexcept { return error_message.c_str(); }
};