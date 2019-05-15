#include "Car.h"
#include <string>
#include <iostream>
#include <tuple>

Car::Car(
        const std::string& registration_number,
        const std::string& producer,
        const std::string& model,
        const std::string& type ) {
	this->registration_number = registration_number;
	this->producer = producer;
	this->model = model;
	this->type = type;
}


const std::string & Car::get_registration_number() const noexcept {
	return registration_number;
}

const std::string & Car::get_producer() const noexcept {
	return producer;
}

const std::string & Car::get_model() const noexcept {
	return model;
}

const std::string & Car::get_type() const noexcept {
	return type;
}

// Car comparison operator
bool Car::operator<(const Car & other) noexcept {
	return std::tie(this->registration_number, this->producer, this->type, this->model)
			< std::tie(other.registration_number, other.producer, other.type, other.model);
}

// operator for printing a car to stdout
std::ostream& operator<<(std::ostream& out, const Car& masina) {
	out << masina.registration_number << ' ' << masina.producer << ' ' << masina.model << ' ' << masina.type;
	return out;
}