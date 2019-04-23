#pragma once
#include <string>

class Car
{
	std::string NRInmatriculare;
	std::string producator;
	std::string model;
	std::string tip;
public:
	Car(const std::string& NRInmatriculare, const std::string& producator,
		const std::string& model, const std::string& tip);

	Car(const Car& other);

	const std::string& getNRInmatriculare() const noexcept;
	const std::string& getproducator() const noexcept;
	const std::string& getmodel() const noexcept;
	const std::string& gettip() const noexcept;

	bool operator<(const Car& other) noexcept;

	friend std::ostream& operator<<(std::ostream&, const Car&);
};
