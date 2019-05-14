#include "Car.h"
#include <string>
#include <iostream>
#include <tuple>

Car::Car(
	const std::string& NRInmatriculare,
	const std::string& producator,
    const std::string& model,
	const std::string& tip
	) {
	this->NRInmatriculare = NRInmatriculare;
	this->producator = producator;
	this->model = model;
	this->tip = tip;
}

// Getters section = = = = = = = = = = = = = = = = = = = = = = =
const std::string & Car::getNRInmatriculare() const noexcept {
	return NRInmatriculare;
}

const std::string & Car::getproducator() const noexcept {
	return producator;
}

const std::string & Car::getmodel() const noexcept {
	return model;
}

const std::string & Car::gettip() const noexcept {
	return tip;
}

// Car comparison operator
bool Car::operator<(const Car & other) noexcept {
	return std::tie(this->NRInmatriculare, this->producator, this->tip, this->model)
			< std::tie(other.NRInmatriculare, other.producator, other.tip, other.model);
}

// operator for printing a car to stdout
std::ostream& operator<<(std::ostream& out, const Car& masina) {
	out << masina.NRInmatriculare << ' ' << masina.producator << ' ' << masina.model << ' ' << masina.tip;
	return out;
}