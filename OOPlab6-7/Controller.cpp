#include <algorithm>
#include "Controller.h"
#include "CarValidator.h"


void Controller::addCar(
	    const std::string & registration_number,
	    const std::string & producer,
	    const std::string & model,
	    const std::string & type ) {
	Car new_car = Car(registration_number, producer, model, type);
    repository.InsertCar(new_car);
}

void Controller::removeCar(const std::string & registration_number) {
	repository.DeleteCar(registration_number);
}

void Controller::modifyCar(
	    const std::string & registration_number,
	    const std::string & producer,
        const std::string & model,
	    const std::string & type ) {
	Car newCar = Car(registration_number, producer, model, type);
	repository.DeleteCar(registration_number);
	repository.InsertCar(newCar);
}

const std::vector<Car>& Controller::getCarList() const noexcept {
	return repository.getCarList();
}

std::unique_ptr<Car> Controller::searchCar(const std::string& registration_number) const
{
	for (const auto& masina : repository.getCarList())
		if (masina.get_registration_number() == registration_number)
			return std::unique_ptr<Car>( std::make_unique<Car>(masina) );
	return std::unique_ptr<Car>(nullptr);
}

std::unique_ptr<std::vector<Car>> Controller::getFilteredCars(const std::string& producer, const std::string& type) const
{
	std::unique_ptr<std::vector<Car>> masini(std::make_unique<std::vector<Car>>());
	const std::vector<Car>& allCars = repository.getCarList();
	for (const auto& car : allCars) {
		if (producer.size() and car.get_producer() != producer) continue;
		if (type.size() and car.get_type() != type) continue;
        // Filter options
        
		masini->push_back(car);
	}

	return masini;
}

std::unique_ptr<std::vector<Car>> Controller::getSortedCars() const
{
	std::unique_ptr<std::vector<Car>> masini( std::make_unique<std::vector<Car>>( repository.getCarList() ) );
	std::sort(masini->begin(), masini->end());

	return masini;
}

