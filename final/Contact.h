#pragma once

#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif // !BASIC_LIB
#include "Address.h"
using namespace std;


class Contact {
private:
	std::string first_name;
	std::string last_name;
	std::string mobile_number;
	std::string email_address;
	Address *address;

public:
	Address add;
	void add_address();
	bool equals(Contact contact);
	Contact* copy_contact();
	//mutator functions
	void setFirst(string& name);
	void setLast(string name);
	void setMobile(string number);
	void setEmail(string mail);
	//acessor functions
	string getFirst();
	string getLast();
	string getMobile();
	string getEmail();
	void address_print();
	bool address_equals(Address& adress);

	Contact() {}
	Contact(std::string first_name, std::string last_name, std::string mobile_number, std::string email_address, Address *address);
};
