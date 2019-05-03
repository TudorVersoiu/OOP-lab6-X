#include <regex>
#include "Car.h"
#include "validation_exception.h"

// Checks registration number format
// Throws Validation error on incorrect format
void ValidateCarRegistration(const std::string& registration_number);

// Checks Car model name length
// Throws ValidationError on incorrect length
void ValidateCarModel(const std::string& model);

// Checks Car type name length
// Throws validation error on incorrect length
void ValidateCarType(const std::string& type);

// Checks car producer name length
// Throws validation error on incorret length
void ValidateCarProducer(const std::string& producer);
