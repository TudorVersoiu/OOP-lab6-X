#include "TestCar.h"
#include <cassert>
#include <sstream>


void TestGetters()
{
	Car masina("1", "2", "3", "4");
	assert(masina.get_registration_number() == "1");
	assert(masina.get_producer() == "2");
	assert(masina.get_model() == "3");
	assert(masina.get_type() == "4");
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