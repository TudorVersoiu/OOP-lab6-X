#include <iostream>
#include "UI.h"
#include "TestController.h"
#include "TestCar.h"


//9 Inchiriere masini
//Creati o aplicatie care permite :
// gestiunea unei liste de masini.Masina : nrInmatriculare, producer, model, type
// adaugare, stergere, modificare si afisare masini
// cautare masina
// filtrare masini dupa : producer, type
// sortare masini dupa : nrInmatriculare, type, producer + model


int main()
{
#if _DEBUG // Defined by MSVC++
	TestController();
	TestCar();
#endif


	UI application;
	try {
		while (application.runPrompt());
	}
	catch (...)
	{
		std::cerr << "Unhandled exception";
		system("PAUSE"); // Debug purposes
	}

    return 0;
}
