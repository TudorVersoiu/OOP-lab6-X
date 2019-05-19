#include "Repository.h"
#include <fstream>

// ============== Basic repository operations ========================
void _base_repository::base_car_insert(const Car& car_object) {
		car_collection[car_object.get_registration_number()] = car_object;
}
void _base_repository::base_car_delete(const std::string& registration_number) {
	car_collection.erase(registration_number);
}

_base_repository::const_iterator _base_repository::find(const std::string& registration_number) const {
	return car_collection.find(registration_number);
}
_base_repository::iterator _base_repository::begin() noexcept {
	return car_collection.begin();
}
_base_repository::iterator _base_repository::end() noexcept {
	return car_collection.end();
}
// ==============

// Normal repository
void Repository::InsertCar(const Car & car_object) {
	_base_repository::base_car_insert(car_object);
}

void Repository::DeleteCar(const std::string& registration_number) {
	_base_repository::base_car_delete(registration_number);
}


// FileRepository
void FileRepository::save_to_file()
{
	std::ofstream output_file(filename);
	for ( auto car: car_collection ) {
		output_file
		<< car.second.get_registration_number() << ","
		<< car.second.get_producer() << ","
		<< car.second.get_model() << ","
		<< car.second.get_type() << '\n';
	}
}
void FileRepository::load_from_file()
{
	std::ifstream input_file(filename);
	while ( !input_file.eof() ) {
		std::string registration_number,
					producer,
					model,
					type;
		std::getline(input_file, registration_number, ',');
		std::getline(input_file, producer, ',');
		std::getline(input_file, model, ',');
		std::getline(input_file, type, '\n');

		base_car_insert(Car{registration_number, producer, model, type});
	}
}

void FileRepository::InsertCar(const Car& car_object) {
	_base_repository::base_car_insert(car_object);
	save_to_file();
}
void FileRepository::DeleteCar(const std::string& registration_number) {
	_base_repository::base_car_delete(registration_number);
	save_to_file();
}

FileRepository::FileRepository(const std::string& cars_filename = "cars.csv"): filename(cars_filename) {  }
