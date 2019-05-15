#include "Car.h"
#include <string>
#include <iostream>

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

bool Car::operator<(const Car & other) noexcept {
	if (this->registration_number < other.registration_number)
		return true;
	else if (this->registration_number == other.registration_number) {
		if (this->producer < other.producer)
			return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, const Car& masina) {
	out << masina.registration_number << ' ' << masina.producer << ' ' << masina.model << ' ' << masina.type;
	return out;
}