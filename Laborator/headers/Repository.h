#pragma once
#include <vector>
#include <memory>
#include <exception>
#include "Car.h"
#include "repository_exception.h"


class Repository
{
private:
	std::vector< Car > masini;

	typedef std::vector<Car>::iterator iterator;

public:
	void InsertCar(const Car& masina);
	void DeleteCar(const std::string nrInmatriculare);

	// Finds and returns a reference to the object
	// Returns end() if no such element is found
	Repository::iterator findElement(std::string NrInmatriculare);

	const std::vector< Car >& getCarList() const noexcept;
};
