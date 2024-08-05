#include "Contact.h"
#include<string>
using namespace std;
//error checking code for empty string entered
string emptyString(string name)
{
	while (1)
	{
		if (name.empty())
		{
			cout << "\nEntered string is empty. plz enter again: ";
			getline(cin, name);
		}
		else
		{
			return name;
		}
	}
}

//implementing code for constructor to initialize all members

Contact::Contact(std::string first_name, std::string last_name,
	std::string mobile_number, std::string email_address, Address *adress)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->mobile_number = mobile_number;
	this->email_address = email_address;
	address = new Address(adress->copy_address());
	//this->address = adress->copy_address();
};


//implementing all the miutator functions

void Contact::setFirst(string& name)
{
	first_name = emptyString(name);
}
void Contact::setLast(string name)
{
	last_name = emptyString(name);
}
void Contact::setMobile(string number)
{
	number = emptyString(number);
	while (1)
	{
		if (number.size() == 11)
		{
			mobile_number = number;
			break;
		}
		else
		{
			cout << "\nEntered Mobile number does not contain 11 digits. Plz enter again: ";
			getline(cin, number);

		}
	}
}
void Contact::setEmail(string mail)
{
	email_address = emptyString(mail);
}

void Contact::add_address()
{
	cin.ignore();
	string n;
	cout << "\nEnter house: ";
	getline(cin, n);
	n = emptyString(n);
	add.setHouse(n);
	cout << "\nEnter Street: ";
	getline(cin, n);
	n = emptyString(n);
	add.setStreet(n);
	cout << "\nEnter City: ";
	getline(cin, n);
	n = emptyString(n);
	add.setCity(n);
	cout << "\nEnter Country: ";
	getline(cin, n);
	n = emptyString(n);
	add.setCountry(n);
}
//implementing accessor functions
string Contact::getFirst()
{
	return first_name;
}
string Contact::getLast()
{
	return last_name;
}
string Contact::getMobile()
{
	return mobile_number;
}
string Contact::getEmail()
{
	return email_address;
}


//implementing equal function to check whether current object is equal to referred object or not
bool Contact::equals(Contact contact)
{
	bool flag;
	if (this->first_name == contact.getFirst() && this->last_name == contact.getLast() && this->mobile_number == contact.getMobile() && this->email_address == contact.getEmail())
	{
		flag = true;
	}
	else
	{
		flag = false;
	}
	if (this->add.equals(*contact.address) && flag)
	{
		return true;
	}
	else
		return false;
}
bool Contact::address_equals(Address& adress)
{
	if (add.equals(adress))
	{
		return true;
	}
	return false;
}
/*
*	Implement the equals function(as declared in header file) that takes a
*   Contact object and checks if it is equal to current object refered by (this pointer).
*   Compare all the attributes.
*   For comparing address of contact you can call the equals function of the Address object;
*   For example: this.address.equals
*/

//implementing
Contact* Contact::copy_contact()
{
	Contact copy;
	copy.first_name = this->first_name;
	copy.last_name = this->last_name;
	copy.mobile_number = this->mobile_number;
	copy.email_address = this->email_address;
	copy.address = this->address;
	return &copy;
	/*
	Return a new object(deep copy of "this"[due to Address pointer, which should also be copied])
	*/
}
void Contact::address_print()
{
	add.print_address();
}
