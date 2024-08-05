#include<iostream>
#include"ContactsBook.h"
using namespace std;

int menu();

int main()
{
	int freeSpace = 0;
	ContactsBook* contact_list = nullptr;

	while (true)
	{
		system("cls");
		int choice = menu();

		if (choice == 1)
		{
			if (contact_list != nullptr) {
				delete contact_list;
				contact_list = nullptr;
			}
			cout << "\nEnter Size of list: ";
			cin >> freeSpace;
			while (cin.fail() || freeSpace <= 1)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter a valid number greater than 1.\n";
				cout << "Enter Size of list: ";
				cin >> freeSpace;
			}
			contact_list = new ContactsBook(freeSpace);
		}
		else if (choice == 2)
		{
			if (contact_list == nullptr) {
				cout << "Please create a contact list first.\n";
			}
			else {
				Contact contact;
				contact_list->add_contact(contact);
			}
		}
		else if (choice == 3)
		{
			if (contact_list == nullptr) {
				cout << "Please create a contact list first.\n";
			}
			else {
				contact_list->merge_duplicates();
			}
		}
		else if (choice == 4)
		{
			if (contact_list == nullptr) {
				cout << "Please create a contact list first.\n";
			}
			else {
				contact_list->save_to_file("contact");
			}
		}
		else if (choice == 5)
		{
			if (contact_list == nullptr) {
				cout << "Please create a contact list first.\n";
			}
			else {
				contact_list->load_from_file("contact");
				system("pause");
			}
		}
		else if (choice == 6)
		{
			if (contact_list == nullptr) {
				cout << "Please create a contact list first.\n";
			}
			else {
				contact_list->print_contacts_sorted("first_name");
				system("pause");
			}
		}
		else if (choice == 7)
		{
			if (contact_list == nullptr) {
				cout << "Please create a contact list first.\n";
			}
			else {
				cout << contact_list->total_contacts();
				system("pause");
			}
		}
		else if (choice == 8)
		{
			if (contact_list == nullptr) {
				cout << "Please create a contact list first.\n";
			}
			else {
				int choic;
				cout << "1. BY USER FIRST NAME \n2. BY LAST NAME \n";
				while (true)
				{
					cin >> choic;
					if (choic >= 1 && choic <= 2)
						break;
					cout << "\nEnter valid input: ";
				}
				if (choic == 1) {
					contact_list->print_contacts_sorted("first_name");
				}
				else if (choic == 2) {
					contact_list->print_contacts_sorted("last_name");
				}
				system("pause");
			}
		}
		else if (choice == 9)
		{
			cout << "Exiting!\n";
			if (contact_list != nullptr) {
				delete contact_list;
				contact_list = nullptr;
			}
			system("pause");
			exit(0);
		}
		else
		{
			cout << "Invalid choice. Please try again.\n";
		}
	}

	system("pause");
	return 0;
}

int menu()
{
	cout << "\n\tContact Management System\n";
	cout << "1. Create a contact list.\n";
	cout << "2. Add a new contact.\n";
	cout << "3. Merge duplicates.\n";
	cout << "4. Store to file.\n";
	cout << "5. Load from file.\n";
	cout << "6. Print Contacts Sorted.\n";
	cout << "7. Display count of contacts.\n";
	cout << "8. Search contacts.\n";
	cout << "9. Exit.\n";
	int choice;
	cout << "Enter your choice: ";
	cin >> choice;
	while (cin.fail() || choice < 1 || choice > 9)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid choice. Please enter a number between 1 and 9.\n";
		cout << "Enter your choice: ";
		cin >> choice;
	}
	return choice;
}
