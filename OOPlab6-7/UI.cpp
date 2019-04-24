#include "UI.h"
#include "Car.h"
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <exception>

// Define it here so it's not visible from the header
enum Commands_t {
	AddCar,
	RemoveCar,
	UpdateCar,
	PrintAllCars,
	SearchCar,
	FilteredPrint,
	SortedPrint,
	Exit
};


int UI::runPrompt()
{
	// Commands data structure
	static std::map<Commands_t, std::string> menu = {
		{ AddCar, "AddCar" },
		{ RemoveCar, "RemoveCar" },
		{ UpdateCar, "ModifyCar" },
		{ PrintAllCars, "PrintAllCars" },
		{ SearchCar, "SearchCar" },
		{ FilteredPrint, "FilteredPrint" },
		{ SortedPrint, "SortedPrint"},
		{ Exit, "Exit" }                            };

	std::cout << "Comenzi disponibile: \n";
	// Print avaible commands
	for (std::map<Commands_t, std::string>::iterator it = menu.begin(); it != menu.end(); it++)
		std::cout << it->first << "." << it->second << '\n';

	// Reading user input and display prompt
	int user_input; std::cout << ">>: "; std::cin >> user_input;

	try {
		switch (user_input) {
			case Commands_t::AddCar:			addCar();           break;
			case Commands_t::RemoveCar:			removeCar();        break;
			case Commands_t::UpdateCar:			updateCar();        break;
			case Commands_t::PrintAllCars:		printAllCars();     break;
			case Commands_t::SearchCar:			searchCar();        break;
			case Commands_t::FilteredPrint: 	filteredPrint();    break;
			case Commands_t::SortedPrint:		sortedPrint();      break;
			case Commands_t::Exit:				std::cerr << "Exitting application!";   return 0;
			default:							std::cerr << "Comanda invalida!";       break;
		}
	}
	catch (std::domain_error& Eroare) {
		std::cerr << "Domain error(Element Duplicat/Neexistent)";
	}
	

	return 1; // Continue to run
}

// Functii ajutatoare pentru citirea datelor despre masina //
void readNRInmatriculare(std::string& nrInmatriculare) {
	std::cout << "Introduceti un nr de inmatriculare!\n";
	std::cin >> nrInmatriculare;
}

void readProducator(std::string& producator) {
	std::cout << "Introduceti un nume de producator!\n";
	std::cin >> producator;
}

void readModel(std::string& model) {
	std::cout << "Introduceti un model de masina!\n";
	std::cin >> model;
}

void readType(std::string& type) {
	std::cout << "Introduceti un tip de masina!\n";
	std::cin >> type;
}
// The end //

void UI::addCar()
{
	std::string NrInmatriculare, Producator, Model, Tip;
	readNRInmatriculare(NrInmatriculare);
	readProducator(Producator);
	readModel(Model);
	readType(Tip);

	controller.addCar(NrInmatriculare, Producator, Model, Tip);
}

void UI::removeCar()
{
	std::string nrInmatriculare;
	readNRInmatriculare(nrInmatriculare);

	controller.removeCar(nrInmatriculare);
}


void UI::printAllCars() const
{
	const std::vector<Car>& masini = controller.getCarList();

	for ( const auto& car : masini) {
		std::cout << car << '\n';
	}
}

void UI::updateCar()
{
	std::string NrInmatriculare, Producator, Model, Tip;
	readNRInmatriculare(NrInmatriculare);
	readProducator(Producator);
	readModel(Model);
	readType(Tip);

	controller.modifyCar(NrInmatriculare, Producator, Model, Tip);
}

void UI::searchCar() const
{
	std::string NrInmatriculare;

	std::unique_ptr<Car> masinutza = controller.searchCar(NrInmatriculare);
	std::cout << masinutza;
}

void UI::filteredPrint() const
{
	std::cout << "Sortati dupa producator(Y, N)?";
	std::string raspuns;  std::cin >> raspuns;

	std::string producator;
	if (raspuns == "Y")
	{
		std::cout << "Introduceti producator cautare";
		std::cin >> producator;
	}

	std::cout << "Sortati dupa tip(Y, N)?";
	std::string raspuns2;  std::cin >> raspuns2;

	std::string tip;
	if (raspuns2 == "Y")
	{
		std::cout << "Introduceti tip cautare";
		std::cin >> tip;
	}

	std::unique_ptr< std::vector<Car> > pSearchResult( controller.getFilteredCars(producator, tip) );
	for (const auto& masinutza : *pSearchResult) {
		std::cout << masinutza << '\n';
	}
}

void UI::sortedPrint() const
{
	std::unique_ptr< std::vector<Car> > pSearchResult(controller.getSortedCars());
	for (const auto& masinutza : *pSearchResult) {
		std::cout << masinutza << '\n';
	}
}
