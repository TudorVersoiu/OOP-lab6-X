#include "TestController.h"
#include "Repository.h"
#include <cassert>
#include <exception>

void TestAdd_Search(Controller& test_controller)
{
	test_controller.addCar("GJ 35 GTR", "Nissan", "R35-GTR", "Supercar");
	test_controller.addCar("CJ 01 JFK", "Dacia" , "1310"   , "Supercar");
	test_controller.addCar("GJ 16 GTR", "Nissan", "R35-GTR", "Supercar");
	test_controller.addCar("GJ 22 GTR", "Lancia", "R35-GT" , "Dubita"  );

	assert(test_controller.searchCar("GJ 35 GTR")->get_registration_number() == "GJ 35 GTR");
	assert(test_controller.searchCar("CJ 01 JFK")->get_registration_number() == "CJ 01 JFK");
	assert(test_controller.searchCar("GJ 16 GTR")->get_registration_number() == "GJ 16 GTR");
	assert(test_controller.searchCar("GJ 22 GTR")->get_registration_number() == "GJ 22 GTR");

	try {
		test_controller.addCar("GJ 35 GTR", "Nissan", "R35-GTR", "Supercar"); assert(false);
	}
	catch (repository_exception&) {
		assert(true);
	}
}

void TestRemove(Controller& test_controller)
{
	test_controller.removeCar("GJ 35 GTR");
	test_controller.removeCar("CJ 01 JFK");
	test_controller.removeCar("GJ 16 GTR");
	test_controller.removeCar("GJ 22 GTR");

    

	assert(test_controller.searchCar("GJ 35 GTR").get() == nullptr);
	assert(test_controller.searchCar("CJ 01 JFK").get() == nullptr);
	assert(test_controller.searchCar("GJ 16 GTR").get() == nullptr);
	assert(test_controller.searchCar("GJ 22 GTR").get() == nullptr);

	try {
		test_controller.removeCar("GJ 35 GTR");
		assert(false);
	}
	catch (repository_exception&) {
		assert(true);
	}
}

void TestModify(Controller& test_controller)
{
	test_controller.modifyCar("GJ 35 GTR", "test1", "test1", "test1");
	test_controller.modifyCar("CJ 01 JFK", "test2", "test2", "test2");
	test_controller.modifyCar("GJ 16 GTR", "test3", "test3", "test3");
	test_controller.modifyCar("GJ 22 GTR", "test4", "test4", "test4");

	assert(test_controller.searchCar("GJ 35 GTR")->get_producer() == "test1");
	assert(test_controller.searchCar("CJ 01 JFK")->get_producer() == "test2");
	assert(test_controller.searchCar("GJ 16 GTR")->get_producer() == "test3");
	assert(test_controller.searchCar("GJ 22 GTR")->get_producer() == "test4");
}

void TestSort(const Controller& test_controller)
{
	auto lista_masini = test_controller.getSortedCars();

	assert(lista_masini->at(0).get_registration_number() == "CJ 01 JFK");
	assert(lista_masini->at(1).get_registration_number() == "GJ 16 GTR");
	assert(lista_masini->at(2).get_registration_number() == "GJ 22 GTR");
	assert(lista_masini->at(3).get_registration_number() == "GJ 35 GTR");
}

void TestFilter(const Controller& test_controller)
{
	auto result = test_controller.getFilteredCars("test1", "");

	assert(result->at(0).get_registration_number() == "GJ 35 GTR");
}

void TestController()
{
	Controller test_controller;

	TestAdd_Search(test_controller);
	TestRemove(test_controller);

	// Adaugam din nou chestii in controller
	TestAdd_Search(test_controller);

	TestModify(test_controller);

	TestFilter(test_controller);

	TestSort(test_controller);

	auto a = test_controller.getCarList();
	assert(a.size() == 4);
}