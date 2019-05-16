#include "UI.h"
#include "Car.h"
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <exception>
#include <functional>
#include <algorithm>

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
        { Exit, "Exit" } };

    std::cout << "Comenzi disponibile: \n";
    // Print avaible commands
    std::for_each(menu.begin(), menu.end(), [](auto a) {std::cout << a.first << ". " << a.second << '\n'; });

	// Read user input and display prompt
    int user_input; std::cout << ">>: "; std::cin >> user_input; std::cin.get();
    

	try {
		switch (user_input) {
            case Commands_t::AddCar:            addCar();           break;
            case Commands_t::RemoveCar:         removeCar();        break;
            case Commands_t::UpdateCar:         updateCar();        break;
            case Commands_t::PrintAllCars:      printAllCars();     break;
            case Commands_t::SearchCar:         searchCar();        break;
            case Commands_t::FilteredPrint:     filteredPrint();    break;
            case Commands_t::SortedPrint:       sortedPrint();      break;
            case Commands_t::Exit:              std::cerr << "Inchidere aplicatie!!!";   return 0;
            default:                            std::cerr << "Comanda invalida!";       break;
		}
	}
	catch (const repository_exception& repository_error) {
		std::cerr << repository_error.what() << '\n';
	}


	return 1; // Continue to run
}

// Functii ajutatoare pentru citirea datelor despre masina //
void readField(std::string& field, const std::string& prompt, std::function<void(const std::string&)> validate) {
    while ( true )
    {
        std::cout << prompt << ": ";
        std::getline(std::cin, field);
        try {
            validate(field);
            return;
        }
        catch (const validation_exception& validation_error) {
            std::cout << validation_error.what() << '\n';
        }
    }
}


void UI::addCar()
{
	std::string registration_number, producer, model, type;
	readField(registration_number, "Introduceti numarul de inmatriculare", ValidateCarRegistration);
	readField(producer, "Introduceti nume de producator", ValidateCarProducer);
	readField(model, "Introduceti nume model masina", ValidateCarModel);
	readField(type, "Introduceti tip masina", ValidateCarType);

	controller.addCar(registration_number, producer, model, type);
}

void UI::removeCar()
{
	std::string registration_number;
    readField(registration_number, "Introduceti numarul de inmatriculare", ValidateCarRegistration);

	controller.removeCar(registration_number);
}

void UI::printAllCars() const
{
	const std::vector<Car>& all_car_list = controller.getCarList();

	for ( const auto& car : all_car_list) std::cout << car << '\n';
}

void UI::updateCar()
{
	std::string registration_number, producer, model, type;
    readField(registration_number, "Introduceti numarul de inmatriculare", ValidateCarRegistration);
    readField(producer, "Introduceti nume de producator", ValidateCarProducer);
    readField(model, "Introduceti nume model masina", ValidateCarModel);
    readField(type, "Introduceti tip masina", ValidateCarType);

	controller.modifyCar(registration_number, producer, model, type);
}

void UI::searchCar() const
{
	std::string registration_number;
    readField(registration_number, "Introduceti numarul de inmatriculare", ValidateCarRegistration);

	std::unique_ptr<Car> found_car = controller.searchCar(registration_number);
    if (found_car == nullptr) {
        std::cerr << "Masina nu a fost gasita!\n";
        return;
    }
	std::cout << *found_car << '\n';
}

void UI::filteredPrint() const
{
	std::cout << "Sortati dupa producator(Y, N)?";
	std::string user_producer_answer;  std::cin >> user_producer_answer;

	std::string producer;
	if (user_producer_answer == "Y")
	{
		std::cout << "Introduceti producator cautare";
		std::cin >> producer;
	}

	std::cout << "Sortati dupa tip(Y, N)?";
	std::string user_type_answer;  std::cin >> user_type_answer;

	std::string type;
	if (user_type_answer == "Y")
	{
		std::cout << "Introduceti tip cautare";
		std::cin >> type;
	}

	std::unique_ptr< std::vector<Car> > p_filter_results( controller.getFilteredCars(producer, type) );
	for (const auto& car : *p_filter_results) {
		std::cout << car << '\n';
	}
}

void UI::sortedPrint() const
{
	std::unique_ptr< std::vector<Car> > p_sort_results(controller.getSortedCars());
	for (const auto& masinutza : *p_sort_results) {
		std::cout << masinutza << '\n';
	}
}
