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
		const std::string& registration_number,
		const std::string& producer,
		const std::string& model,
		const std::string& type
		);

	// Functie care cauta si sterge o masina dupa numarul de inmatriculare
	// registration_number const std::string
	void removeCar(const std::string& registration_number);


	// Inlocuieste masina care are registration_number egal cu parametrul
	// cu o masina cu acelasi numar de inmatriculare si noile campuri
	// poate arunca repository_exception
	void modifyCar(
		const std::string& registration_number,
		const std::string& producer,
		const std::string& model,
		const std::string& type
		);
	
	// Returneaza o referinta const catre lista cu toate masinile
	const std::vector<Car>& getCarList() const noexcept;

    // Cauta masina cu registration_number precizat
	// In cazul in care nu gaseste o asemenea masina, returneaza un unique_ptr(nullptr)
	std::unique_ptr<Car> searchCar(const std::string& registration_number) const;

	// Returneaza o lista care contine masinile ce satisfac parametrii
	// Daca un parametru este 0-length, nu este luat in considerare
	std::unique_ptr< std::vector<Car> > getFilteredCars(
		const std::string& producer,
		const std::string& type
		) const;

	// Returneaza o lista cu toate masinile sortate crescator in functie
	// de parametri in ordine
	std::unique_ptr< std::vector<Car> > getSortedCars() const;
};
