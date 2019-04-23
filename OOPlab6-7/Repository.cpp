#include "Repository.h"

void Repository::InsertCar(const Car & masina)
{
	if ( findElement(masina.getNRInmatriculare()) != masini.end() )
		throw	RepoException( std::string("Masina ") +
				masina.getNRInmatriculare() +
				std::string("deja se afla in baza de date!!!") );

	masini.push_back(masina);
}

void Repository::DeleteCar(const std::string nrInmatriculare)
{
	repoReference element = findElement(nrInmatriculare);
	if (element == masini.end())
		throw RepoException("Masina nu se afla in repository!");
	else
		masini.erase(element);
}

Repository::repoReference Repository::findElement(std::string NrInmatriculare)
{
	std::vector<Car>::iterator it;
	for (it = masini.begin(); it != masini.end(); it++)
		if (it->getNRInmatriculare() == NrInmatriculare)
			break;

	return it;
}

const std::vector<Car>& Repository::getCarList() const noexcept { return masini; }
