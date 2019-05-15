#pragma once
#include <string>

class Car {
	std::string registration_number;
	std::string producer;
	std::string model;
	std::string type;
public:
	Car(const std::string& registration_number,
        const std::string& producer,
		const std::string& model,
        const std::string& type);

    // Getters
	const std::string& get_registration_number() const noexcept;
	const std::string& get_producer() const noexcept;
	const std::string& get_model() const noexcept;
	const std::string& get_type() const noexcept;

	bool operator<(const Car& other) noexcept;

    // stream operator, for printing
	friend std::ostream& operator<<(std::ostream&, const Car&);
};
