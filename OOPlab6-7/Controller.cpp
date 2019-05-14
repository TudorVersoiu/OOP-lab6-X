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
	auto found_element = std::find_if(
		repository.getCarList().begin(),
		repository.getCarList().end(), // range(first, last)
		[nr_inmatriculare](const Car& a) -> bool // Lambda function | checks if reg number is same
		{
			return nr_inmatriculare == a.getNRInmatriculare();
		} );
	return found_element==getCarList().end()?
			std::make_unique<Car>(nullptr):
			std::make_unique<Car>(*found_element);
}

void Controller::getFilteredCars(const std::string& producator, const std::string& tip, std::vector<Car>& output) const
{
	const std::vector<Car>& allCars = repository.getCarList();
    
    std::copy_if(allCars.begin(),
                 allCars.end(),
                 output.begin(),
                 // range[first, last], output
                [producator, tip](Car a) -> bool 
                { return (tip.size() && tip == a.gettip()) || (producator.size() && producator == a.getproducator()); });
                // condition to copy
}

std::unique_ptr<std::vector<Car>> Controller::getSortedCars() const
{
	std::unique_ptr<std::vector<Car>> masini( std::make_unique<std::vector<Car>>( repository.getCarList() ) );
	std::sort(masini->begin(), masini->end());

	return masini;
}
