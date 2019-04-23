#include "TestCar.h"
#include <cassert>
#include <sstream>


void TestGetters()
{
	Car masina("1", "2", "3", "4");
	assert(masina.getNRInmatriculare() == "1");
	assert(masina.getproducator() == "2");
	assert(masina.getmodel() == "3");
	assert(masina.gettip() == "4");
}

void TestCompare()
{
	Car masinamica("1", "2", "3", "4");
	Car masinamare("1", "3", "3", "4");

	assert(masinamica < masinamare);
}

void TestOutput()
{
	std::stringstream test_stream;
	Car masina("1", "2", "3", "4");

	test_stream << masina;

	std::string a;
	getline(test_stream, a);
	assert(a == "1 2 3 4");
}

void TestCar()
{
	TestGetters();
	TestCompare();
	TestOutput();
}