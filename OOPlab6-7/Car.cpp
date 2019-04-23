#include "Car.h"
#include <string>
#include <iostream>

Car::Car(const std::string& NRInmatriculare, const std::string& producator,
	const std::string& model, const std::string& tip)
{
	this->NRInmatriculare = NRInmatriculare;
	this->producator = producator;
	this->model = model;
	this->tip = tip;
}

Car::Car(const Car & other)
{
	std::cout << "Un car a fost copiat";
	this->model = other.model;
	this->NRInmatriculare = other.NRInmatriculare;
	this->producator = other.producator;
	this->tip = other.tip;
}


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

bool Car::operator<(const Car & other) noexcept {
	if (this->NRInmatriculare < other.NRInmatriculare)
		return true;
	else if (this->NRInmatriculare == other.NRInmatriculare) {
		if (this->producator < other.producator)
			return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, const Car& masina) {
	out << masina.NRInmatriculare << ' ' << masina.producator << ' ' << masina.model << ' ' << masina.tip;
	return out;
}