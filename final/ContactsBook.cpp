#include "ContactsBook.h"
#include<string>
#include<fstream>
using namespace std;

void ContactsBook::add_contact(Contact& contact)
{
	if (contacts_count >= size_of_contacts)
	{
		resize_list();
	}
	if (contacts_count < size_of_contacts)
	{
		cin.ignore();
		string data;
		cout << "\n\tNow enter details of your contact: ";
		cout << "\nKindly enter your first name: ";
		getline(cin, data);
		contact.setFirst(data);
		cin.ignore();
		cout << "Kindly enter your last name: ";
		getline(cin, data);
		contact.setLast(data);
		cin.ignore();
		cout << "Now enter your mobile phone number: ";
		getline(cin, data);
		contact.setMobile(data);
		cin.ignore();
		cout << "Lastly enter your Email address: ";
		getline(cin, data);
		contact.setEmail(data);
		contacts_list[contacts_count] = contact;
		contact.add_address();
		cout << "\nContact saved successully!";
		contacts_count++;
		cout << "check check\n";
		return;
	}
	/*
	- Check if the list is full, if it is full call the resize function
	- If list is not full add the contact to the end of the array
	- (end means the place where last contact was inserted)
	- At start it will be 0th index as no contact has been inserted before so
	- count is zero (contacts_count member)
	- Increment the count
	- As inserted successfully, return 1
	*/
}

string ContactsBook::error(string)
{
	while (1)
	{

	}
}
void ContactsBook::resize(int n)
{
	size_of_contacts = n;
}
int ContactsBook::total_contacts()
{
	return contacts_count;
}

bool ContactsBook::full()
{
	if (contacts_count >= size_of_contacts)
		return true;
	if (contacts_count < size_of_contacts)
	{
		return false;
	}
}

void ContactsBook::resize_list()
{
	Contact* temp = new Contact[2 * size_of_contacts];
	for (int i = 0; i < size_of_contacts; i++)
	{
		temp[i] = contacts_list[i];
	}
	delete[] contacts_list;
	Contact* contacts_list = nullptr;
	contacts_list = temp;
	delete[] temp;
	size_of_contacts = 2 * size_of_contacts;
	/*
	*	Here you will resize the contact list, see example code given in lab manual to see how to resize arrays
	*	You will allocate a temporary new array of double the current size and copy the contacts from
	*       previous array to this array one by one, get the copy of each contact using copy_contact
	*       function of Contact class
	*	Delete the previous array
	*	Assign the new temporary array to the contacts_list pointer
	*	Updated the this->size_of_contacts with new size
	*/
}

Contact* ContactsBook::search_contact(std::string first_name, std::string last_name)
{
	bool flag = false;
	for (int i = 0; i < contacts_count; i++)
	{
		if (first_name == contacts_list[i].getFirst() && last_name == contacts_list[i].getLast())
		{
			flag = true;
			return &contacts_list[i];
		}
	}
	if (!flag)
	{
		cout << "\nContact not Found with this name!";
		return nullptr;
	}
	/*
	*	In all search functions perform the searching according the given parameter and return a copy of the contact using copy func
	*	Remove this return nullptr; before writing your code
	*/
}

Contact* ContactsBook::search_contact(std::string phone)
{
	for (int i = 0; i < contacts_count; i++)
	{
		if (contacts_list[i].getMobile() == phone)
		{
			return &contacts_list[i];
		}
	}
	return nullptr;
}

Contact* ContactsBook::search_contact(Address& adress)
{
	for (int i = 0; i < contacts_count; i++)
	{
		if (contacts_list[i].address_equals(adress))
		{
			return &contacts_list[i];
		}
	}
	return nullptr;
}

ContactsBook::ContactsBook(int size_of_list)
{
	this->size_of_contacts = size_of_list;
	contacts_list = new Contact[size_of_list];
	contacts_count = 0;
	/*
	*	Initialize the contacts_list array, also initialize the size and count members accordingly
	*/
}
ContactsBook::~ContactsBook()
{
	delete[] contacts_list;
}
void ContactsBook::print_contacts_sorted(std::string choice)
{
	Contact*  copy = new Contact[contacts_count];
	for (int i = 0; i < contacts_count; i++)
	{
		copy[i] = contacts_list[i];
	}
	sort_contacts_list(copy, choice);
	cout << "\n\tContacts Information\nFirst Name\tLast Namw\tMobile Number\tEmail Adsress";
	for (int i = 0; i < contacts_count; i++)
	{
		cout << endl << contacts_list[i].getFirst() << "\t" << copy[i].getLast() << "\t" << copy[i].getMobile() << "\t" << copy[i].getEmail();
		cout << endl;
		copy[i].address_print();
	}
	/*
	*	Create a copy of this->contacts_list array here (do it by creating a new function that returns copy)
	*	Call the sort function sort_contacts_list to sort the newly created copy
	*	This copy is created to avoid changing the original insertion order of contact list
	*	Then print the contacts in following format:
	*	[First Name] [Last Name] [Mobile] [Email]
	*	Call the address print function to print address on next line
	*/
}

void ContactsBook::sort_contacts_list(Contact *contacts_list, std::string choice)
{
	//i am stroing names of persons in this array to sort them easily
	string *str_name = new string[contacts_count];
	for (int i = 0; i < contacts_count; i++)
	{
		str_name[i] = contacts_list[i].getFirst();

	}
	//sorting for first name choice
	if (choice == "first_name")
	{
		for (int i = 0; i < contacts_count; i++)
		{
			//str_name = contacts_list[i].getFirst();
			for (int j = i + 1; j <= contacts_count; j++)
			{
				if (str_name[i][0] > str_name[j][0])
				{
					Contact temp = contacts_list[i];
					contacts_list[i] = contacts_list[j];
					contacts_list[j] = temp;
				}
			}
		}
		return;
		//sorting for second name choice
		for (int i = 0; i < contacts_count; i++)
		{
			str_name[i] = contacts_list[i].getLast();

		}
		if (choice == "last_name")
		{
			for (int i = 0; i <= contacts_count; i++)
			{
				//str_name = contacts_list[i].getLast();
				for (int j = i + 1; j <= contacts_count; j++)
				{
					if (str_name[i][0] > str_name[j][0])
					{
						Contact temp = contacts_list[i];
						contacts_list[i] = contacts_list[j];
						contacts_list[j] = temp;
					}
				}
			}
		}
		return;
		/*
		You should not duplicate the code to sort based on choices
		Follow the strategy provided in manual/tutorial to avoid duplicating the code (Section B & E only)
		Sort by the fist letter of first name or last name as given in choice
		*/
	}
}

void ContactsBook::merge_duplicates()
{
	int num = 0;
	bool isDuplicate;
	for (int i = 0; i <= contacts_count; i++)
	{
		isDuplicate = false;
		for (int j = i + 1; j < contacts_count; j++)
		{
			if (contacts_list[i].equals(contacts_list[j]))
			{
				isDuplicate = true;
				break;
			}
		}
		if (!isDuplicate)
		{
			contacts_list[i] = contacts_list[contacts_count - 1];
			contacts_count--;
		}
	}
	// Implement this function that finds and merges all the duplicates
	// Duplicate means exact equal
	// If there are three copies of a Contact, then only one should remain
	// For example: If total contact are 10, and 2 contacts are same, after removing duplicates
	// 9 contacts will be left; and the this->contacts_count of list will 9
	// At the end display contacts merged, and count of merged contacts
}


void ContactsBook::load_from_file(std::string file_name)
{
	ifstream inFile("contacts.txt");
	if (inFile.is_open())
	{
		string line;
		while (getline(inFile, line))
		{
			cout << line << endl;
		}
	}
	else
	{
		cout << "error opening file!";
	}
	inFile.close();
	/*
	*	Read contacts back from file in the same format
	*	Read the contacts_count, and run a loop for this contacts_count and read the
	*	contacts in the same format as you stored
	*	Add them to contact book (this.add_contact function can be used)
	*	Finally, close the file
	*/
}
void ContactsBook::save_to_file(std::string file_name)
{
	ofstream outFile("contacts.txt");
	if (outFile.is_open())
	{
		outFile << "Contacts count= " << contacts_count << endl;
		for (int i = 0; i <= contacts_count; i++)
		{

			outFile << contacts_list[i].getFirst() << "," << contacts_list[i].getLast() << "," << contacts_list[i].getMobile() << "," << contacts_list[i].getEmail() << ","
				<< contacts_list[i].add.getHouse() << "," << contacts_list[i].add.getStreet() << "," << contacts_list[i].add.getCity() << "," << contacts_list[i].add.getCountry() << endl;

		}
	}
	else
	{
		cout << "file could not open!";
	}
	outFile.close();
	/*
	*	In this function you will store all the contacts to a file
	*	On first line store contacts_count
	*	On next lines store contacts in the following format:
	*       2 lines for each contact
	*       On oneline write contact attributes(except address) in comma separated format. On second line
	*	store address atributes in the same format
	*	first_name,last_name,mobile_number,email_address
	*	house,street,city,country
	*	Close the file
	*/
}



