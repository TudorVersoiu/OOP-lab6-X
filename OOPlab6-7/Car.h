#pragma once
#include <string>

class Car {
	std::string NRInmatriculare;
	std::string producator;
	std::string model;
	std::string tip;
public:
	Car(const std::string& NRInmatriculare, const std::string& producator,
		const std::string& model, const std::string& tip);

    // Getters
	const std::string& getNRInmatriculare() const noexcept;
	const std::string& getproducator() const noexcept;
	const std::string& getmodel() const noexcept;
	const std::string& gettip() const noexcept;

	bool operator<(const Car& other) noexcept;

    // output car
	friend std::ostream& operator<<(std::ostream&, const Car&);
};
