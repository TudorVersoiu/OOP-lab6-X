#include <algorithm>
#include "Controller.h"
#include "CarValidator.h"


void Controller::addCar(const std::string & nrInmatriculare, const std::string & producator,
						const std::string & model,           const std::string & tip) {
	Car newMasina = Car(nrInmatriculare, producator, model, tip);
    
    repository.InsertCar(newMasina);
}

void Controller::removeCar(const std::string & nrInmatriculare) {
	repository.DeleteCar(nrInmatriculare);
}

void Controller::modifyCar(const std::string & nrInmatriculare, const std::string & producator,
                           const std::string & model,            const std::string & tip)
{
	Car newCar = Car(nrInmatriculare, producator, model, tip);
	repository.DeleteCar(nrInmatriculare);
	repository.InsertCar(newCar);
}

const std::vector<Car>& Controller::getCarList() const noexcept
{
	return repository.getCarList();
}

std::unique_ptr<Car> Controller::searchCar(const std::string& nrInmatriculare) const
{
	for (const auto& masina : repository.getCarList())
		if (masina.getNRInmatriculare() == nrInmatriculare)
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

