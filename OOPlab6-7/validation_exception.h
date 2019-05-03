#pragma once
#include <exception>
#include <string>

// Custom exception for validation errors

class validation_exception : public std::exception {
private:
    std::string error_message;
public:
    validation_exception(const std::string& message) : error_message(message) {  }
    const char* what() const noexcept { return error_message.c_str(); }
};
