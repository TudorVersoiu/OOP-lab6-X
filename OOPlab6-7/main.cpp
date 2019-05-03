#include <iostream>
#include "UI.h"
#include "TestController.h"
#include "TestCar.h"


//9 Inchiriere masini
//Creati o aplicatie care permite :
// gestiunea unei liste de masini.Masina : nrInmatriculare, producator, model, tip
// adaugare, stergere, modificare si afisare masini
// cautare masina
// filtrare masini dupa : producator, tip
// sortare masini dupa : nrInmatriculare, tip, producator + model


int main()
{
#if _DEBUG // Defined by MSVC++
	TestController();
	TestCar();
#endif


	UI applicatie;
	try {
		while (applicatie.runPrompt());
	}
	catch (...)
	{
		std::cerr << "Unhandled exception";
		system("PAUSE"); // Debug purposes
	}

    return 0;
}
