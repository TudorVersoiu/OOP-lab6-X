#pragma once
#include <vector>
#include <memory>
#include <exception>
#include <unordered_map>
#include "Car.h"
#include "repository_exception.h"

// Repository interface for methods which can vary
class _repository_interface {
public:
	// Methods which can vary depending on repository
	virtual void InsertCar(const Car& car_object);
	virtual void DeleteCar(const std::string& registration_number);
};

// Define basic operations common to all repositories
class _base_repository: public _repository_interface {
protected:
	typedef std::unordered_map<std::string, Car>::iterator iterator;
	typedef std::unordered_map<std::string, Car>::const_iterator const_iterator;
	std::unordered_map<std::string, Car > car_collection;

	// Basic functionality
	void base_car_insert(const Car& car_object);
	void base_car_delete(const std::string& registration_number);

public:
	const_iterator find(const std::string& nr_inmatriculare) const;
	iterator begin() noexcept;
	iterator end() noexcept;
};


class Repository: public _base_repository {
public:
	// Inserts a new car into repository
	void InsertCar(const Car& masina) override;
	void DeleteCar(const std::string& nr_inmatriculare) override;
};


// ================================== FileRepository =================================
class FileRepository: public _base_repository {
private:
	const std::string filename;

	void save_to_file();
	void load_from_file();
public:
	void InsertCar(const Car& masina) override;
	void DeleteCar(const std::string& nr_inmatriculare) override;
};