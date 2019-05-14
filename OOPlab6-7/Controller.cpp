#include <algorithm>
#include "Controller.h"
#include "CarValidator.h"


void Controller::addCar(
	const std::string & nr_inmatriculare,
	const std::string & producator,
	const std::string & model,
	const std::string & tip
	) {
	Car new_car = Car(nr_inmatriculare, producator, model, tip);
    
    repository.InsertCar(new_car);
}

void Controller::removeCar(const std::string & nr_inmatriculare) {
	repository.DeleteCar(nr_inmatriculare);
}

void Controller::modifyCar(
	const std::string & nr_inmatriculare,
	const std::string & producator,
    const std::string & model,
	const std::string & tip
	) {
	Car newCar = Car(nr_inmatriculare, producator, model, tip);
	repository.DeleteCar(nr_inmatriculare);
	repository.InsertCar(newCar);
}

const std::vector<Car>& Controller::getCarList() const noexcept {
	return repository.getCarList();
}

std::unique_ptr<Car> Controller::searchCar(const std::string& nr_inmatriculare) const
{
	for (const auto& masina : repository.getCarList())
		if (masina.getNRInmatriculare() == nr_inmatriculare)
			return std::unique_ptr<Car>( std::make_unique<Car>(masina) );
	return std::unique_ptr<Car>(nullptr);
}

std::unique_ptr<std::vector<Car>> Controller::getFilteredCars(const std::string& producator, const std::string& tip) const
{
	std::unique_ptr<std::vector<Car>> masini(std::make_unique<std::vector<Car>>());
	const std::vector<Car>& allCars = repository.getCarList();
	for (const auto& car : allCars) {
		if (producator.size() and car.getproducator() != producator) continue;
		if (tip.size() and car.gettip() != tip) continue;
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

