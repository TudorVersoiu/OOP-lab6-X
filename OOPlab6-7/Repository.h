#pragma once
#include <vector>
#include <memory>
#include <exception>
#include "Car.h"

class RepoException : std::exception {
private:
	std::string error_message;
public:
	RepoException(std::string message) : error_message(message) {  }

	const char* what() const noexcept { return error_message.c_str(); }
};

class Repository
{
private:
	std::vector< Car > masini;

	typedef std::vector<Car>::iterator repoReference;

public:
	void InsertCar(const Car& masina);
	void DeleteCar(const std::string nrInmatriculare);

	// Finds and returns a reference to the object
	// Returns end() if no such element is found
	Repository::repoReference findElement(std::string NrInmatriculare);

	const std::vector< Car >& getCarList() const noexcept;
};
