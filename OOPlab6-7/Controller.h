#pragma once
#include <string>
#include <memory>
#include <vector>
#include "Repository.h"
#include "Car.h"


class Controller
{
private:
	Repository repository;

public:
	// Functie care adauga o masina in repository
	//     parameters - all const string - date masina
	void addCar(
		const std::string& nrInmatriculare,
		const std::string& producator,
		const std::string& model,
		const std::string& tip
		);

	// Functie care cauta si sterge o masina dupa numarul de inmatriculare
	// nrInmatriculare const std::string
	void removeCar(const std::string& nrInmatriculare);


	// Inlocuieste masina care are nrInmatriculare egal cu parametrul
	// cu o masina cu acelasi numar de inmatriculare si noile campuri
	// poate arunca repository_exception
	void modifyCar(
		const std::string& nrInmatriculare,
		const std::string& producator,
		const std::string& model,
		const std::string& tip
		);
	
	// Returneaza o referinta const catre lista cu toate masinile
	const std::vector<Car>& getCarList() const noexcept;

    // Cauta masina cu nrInmatriculare precizat
	// In cazul in care nu gaseste o asemenea masina, returneaza un unique_ptr(nullptr)
	std::unique_ptr<Car> searchCar(const std::string& nrInmatriculare) const;

	// Returneaza o lista care contine masinile care satisfac parametrii
	// Daca un parametru este 0-length, nu este luat in considerare
	void Controller::getFilteredCars(
		const std::string& producator,
		const std::string& tip,
		std::vector<Car>& output
		) const;

	// Returneaza o lista cu toate masinile sortate crescator in functie
	// de parametri in ordine
	std::unique_ptr< std::vector<Car> > getSortedCars() const;
};
