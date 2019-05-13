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
                           const std::string & model,           const std::string & tip)
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
    auto found_element = std::find_if(repository.getCarList().begin(), repository.getCarList().end(),       // vector range
                         [nrInmatriculare](Car a) { return a.getNRInmatriculare() == nrInmatriculare; });   // lambda function

    // If iterator==last, return nullptr, else return *found_element
    return found_element == repository.getCarList().end() ? std::make_unique<Car>(nullptr) : std::make_unique<Car>(*found_element);
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
