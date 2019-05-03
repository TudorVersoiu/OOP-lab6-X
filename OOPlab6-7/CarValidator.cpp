#include "CarValidator.h"



// Validation functions
// Check car registration format
void ValidateCarRegistration(const std::string& registration_number) {
    std::regex registration_regex("[A-Z]{2}(-| )[0-9]{2}(-| )[A-Z]{3}");
    std::cmatch registration_match;

    if (!std::regex_match(registration_number.c_str(), registration_regex))
        throw validation_exception("Format numar inmatriculare incorect");
}

// Helper function; checks length
bool CheckStringLength2_15(const std::string check_string) {
    return (2 <= check_string.length() and check_string.length() <= 15);
}

void ValidateCarModel(const std::string& model) {
    CheckStringLength2_15(model) ? 0 : throw validation_exception("Lungime nume model incorecta!");
}

void ValidateCarType(const std::string& type) {
    CheckStringLength2_15(type) ? 0 : throw validation_exception("Lungime nume tip incorecta!");
}

void ValidateCarProducer(const std::string& producer) {
    CheckStringLength2_15(producer) ? 0 : throw validation_exception("Lungime nume producator incorecta");
}
