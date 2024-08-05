#pragma once
#include <iostream>
#include <string>

class Address {
private:
	std::string house;
	std::string street;
	std::string city;
	std::string country;

public:
	Address() {}
	Address(std::string house, std::string street, std::string city, std::string country);
	//mutator function
	void setHouse(std::string house_set);
	void setStreet(std::string street_set);
	void setCity(std::string city_set);
	void setCountry(std::string country_set);
	//accessor functions
	std::string getHouse();
	std::string getStreet();
	std::string getCity();
	std::string getCountry();
	bool equals(Address& address);
	void print_address();
	Address copy_address();

};