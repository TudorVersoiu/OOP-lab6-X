#include "Repository.h"

void Repository::InsertCar(const Car & masina)
{
	if ( findElement(masina.get_registration_number()) != masini.end() )
		throw
            repository_exception( std::string("Masina ") + masina.get_registration_number() +
			std::string(" deja se afla in baza de date!!!") );

	masini.push_back(masina);
}

void Repository::DeleteCar(const std::string nrInmatriculare)
{
	iterator element = findElement(nrInmatriculare);
	if (element == masini.end())
		throw repository_exception("Masina nu se afla in repository!");
	else
		masini.erase(element);
}

Repository::iterator Repository::findElement(std::string NrInmatriculare)
{
	std::vector<Car>::iterator it;
	for (it = masini.begin(); it != masini.end(); it++)
		if (it->get_registration_number() == NrInmatriculare)
			break;

	return it;
}

const std::vector<Car>& Repository::getCarList() const noexcept { return masini; }
