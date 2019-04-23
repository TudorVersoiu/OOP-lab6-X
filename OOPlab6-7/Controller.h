#pragma once
#include <string>
#include "Car.h"
#include "Repository.h"
#include <memory>
#include <vector>


class Controller
{
private:
	Repository repository;

public:
	// Functie care adauga o masina in repository
	//     parameters - all const string - date masina
	void addCar(const std::string& nrInmatriculare, const std::string& producator,
		        const std::string& model,           const std::string& tip);

	// Functie care cauta si sterge o masina dupa numarul de inmatriculare
	// nrInmatriculare const std::string
	void removeCar(const std::string& nrInmatriculare);
	void modifyCar(const std::string& nrInmatriculare, const std::string& producator, const std::string& mode, const std::string& tip);
	const std::vector<Car>& getCarList() const noexcept;
	std::unique_ptr<Car> searchCar(const std::string nrInmatriculare) const;
	std::unique_ptr< std::vector<Car> > getFilteredCars(const std::string& producator, const std::string& tip) const;
	std::unique_ptr< std::vector<Car> > getSortedCars() const;
};
