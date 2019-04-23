#pragma once
#include <map>
#include "Controller.h"


class UI
{
private:
	Controller controller;
public:
	// Display avaible commands and query user choice
	int runPrompt();

	// Prompt user and read car data
	void addCar();

	// Prompt user and delets the car with the provided registration number
	void removeCar();

	// Prints to the stdout all the cars
	void printAllCars() const;

	// Prompt for car data and replaces overwrites the car in the
	// repository that already holds the provided registration number
	void updateCar();

	// Prompts for a registration number and displays the corresponding car
	// If no car is found, it prints an according message
	void searchCar() const;

	// Prints the cars by some conditions provided on the command line
	void filteredPrint() const;

	// Prints the cars sorted
	void sortedPrint() const;
};

