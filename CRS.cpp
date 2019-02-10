#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class CustomerRegistartionSystem
{
private:
	string firstName[100];
	string lastName[100];
	string comment[100];
	string email[100];
	unsigned long long phoneNumber1[100];
	unsigned long long phoneNumber2[100];
	unsigned int amountOfCustomers = 0;
	unsigned int index = 0;

public:
	void mainMenu()
	{
		int menuChoice;

		do
		{
			cout << "**************************************************" << endl;
			cout << "           CUSTOMER REGISTRATION SYSTEM           " << endl;
			cout << "**************************************************" << endl << endl;
			cout << "1 - Add a customer" << endl;
			cout << "2 - Edit a customer" << endl;
			cout << "3 - Delete a customer" << endl << endl;
			cout << "At the moment the amount of customers is " << amountOfCustomers << endl << endl;

			cin >> menuChoice;
			system("CLS");

		} while (menuChoice != 1 && menuChoice != 2 && menuChoice != 3);

		if (menuChoice == 1)
		{
			cout << endl << "Do You wish to add a customer from a console or from a .csv file?" << endl << endl;
			cout << "1 - Console" << endl;
			cout << "2 - File" << endl << endl;

			int addChoice;
			cin >> addChoice;

			if (addChoice == 1)
			{
				system("CLS");
				addCustomer();
			}

			else if (addChoice == 2)
			{
				system("CLS");
				addCustmerFromCSV();
			}
		}

		else if (menuChoice == 2)
		{
			system("CLS");
			editCustomer();
		}

		else if (menuChoice == 3)
		{
			system("CLS");
			deleteCustomer();
		}
	}

	void addCustmerFromCSV()
	{
		ifstream fin("Visma.csv");

		if (!fin.is_open())
		{
			cerr << "Error opening CSV file!" << endl;
		}

		while (!fin.eof())
		{
			getline(fin, firstName[index]);
			getline(fin, lastName[index]);
			getline(fin, email[index]);
			fin >> phoneNumber1[index];
			fin.ignore(SIZE_MAX);
			fin >> phoneNumber2[index];
			fin.ignore(SIZE_MAX);
			getline(fin, comment[index], ',');
			amountOfCustomers++;
			index++;
		}

		cout << "Customer added successfully!" << endl;
		fin.close();

		cout << endl << "Do You wish to add another customer? Y/N" << endl;

		char charForAdd;
		cin >> charForAdd;

		if (charForAdd == 'Y')
		{
			cout << "Do You wish to add a customer from a console or from a .csv file?" << endl << endl;
			cout << "1 - Console" << endl;
			cout << "2 - File" << endl << endl;

			int addChoice;
			cin >> addChoice;

			if (addChoice == 1)
			{
				system("CLS");
				addCustomer();
			}

			else if (addChoice == 2)
			{
				system("CLS");
				addCustmerFromCSV();
			}
		}

		else if (charForAdd == 'N')
		{
			cout << "Do You wish to edit an existing customer? Y/N" << endl;

			char charForEdit;
			cin >> charForEdit;

			if (charForEdit == 'Y')
			{
				system("CLS");
				editCustomer();
			}

			else if (charForEdit == 'N')
			{
				cout << "Do You wish to delete an existing customer? Y/N" << endl;

				char charForDelete;
				cin >> charForDelete;

				if (charForDelete == 'Y')
				{
					system("CLS");
					deleteCustomer();
				}

				else if (charForDelete == 'N')
				{

				}
			}
		}
	}

	void addCustomer()
	{
		cout << "**************************************************" << endl;
		cout << "                   ADD CUSTOMER                   " << endl;
		cout << "**************************************************" << endl << endl;

		cout << "Enter Your First Name: ";
		cin >> firstName[index];
		cout << "Enter Your Last Name: ";
		cin >> lastName[index];
		cout << "Enter Your Email: ";
		cin >> email[index];

		size_t at = email[index].find('@');

		if (at == string::npos)
		{
			cout << "Your email adress is missing @ symbol! Try again!" << endl;
			cout << "Enter Your Email: ";

			cin >> email[index];
		}

		size_t dot = email[index].find('.', at + 1);

		if (dot == string::npos)
		{
			cout << "Your email adress is missing . symbol after @! Try again!" << endl;
			cout << "Enter Your Email: ";

			cin >> email[index];
		}

		cout << "Enter Your First Phone Number: ";
		cin >> phoneNumber1[index];
		cout << "Enter Your Second Phone Number: ";
		cin >> phoneNumber2[index];
		cout << "Enter a comment about Yourself: ";
		cin.ignore();
		getline(cin, comment[index]);
		amountOfCustomers++;
		index++;

		cout << endl << "Do You wish to add another customer? Y/N" << endl;

		char charForAdd;
		cin >> charForAdd;

		if (charForAdd == 'Y')
		{
			cout << endl << "Do You wish to add a customer from a console or from a .csv file?" << endl << endl;
			cout << "1 - Console" << endl;
			cout << "2 - File" << endl << endl;

			int addChoice;
			cin >> addChoice;

			if (addChoice == 1)
			{
				system("CLS");
				addCustomer();
			}

			else if (addChoice == 2)
			{
				system("CLS");
				addCustmerFromCSV();
			}
		}

		else if (charForAdd == 'N')
		{
			cout << "Do You wish to edit an existing customer? Y/N" << endl;

			char charForEdit;
			cin >> charForEdit;

			if (charForEdit == 'Y')
			{
				system("CLS");
				editCustomer();
			}

			else if (charForEdit == 'N')
			{
				cout << "Do You wish to delete an existing customer? Y/N" << endl;

				char charForDelete;
				cin >> charForDelete;

				if (charForDelete == 'Y')
				{
					system("CLS");
					deleteCustomer();
				}

				else if (charForDelete == 'N')
				{
					
				}
			}
		}
		
	}

	void editCustomer()
	{	
		if (amountOfCustomers == 0)
		{
			cout << "There are no registered customers at the moment!" << endl << endl;
			cout << "Do You wish to add a customer? Y/N" << endl;

			char charForAdd;
			cin >> charForAdd;

			if (charForAdd == 'Y')
			{
				cout << endl << "Do You wish to add a customer from a console or from a .csv file?" << endl << endl;
				cout << "1 - Console" << endl;
				cout << "2 - File" << endl << endl;

				int addChoice;
				cin >> addChoice;

				if (addChoice == 1)
				{
					system("CLS");
					addCustomer();
				}

				else if (addChoice == 2)
				{
					system("CLS");
					addCustmerFromCSV();
				}
			}
		}

		else
		{
			cout << "**************************************************" << endl;
			cout << "                   EDIT CUSTOMER                  " << endl;
			cout << "**************************************************" << endl << endl;

			cout << "At the moment the amount of customers is " << amountOfCustomers << endl << endl;
			cout << "Enter the index number of the customer You wish to edit: ";

			unsigned int number;
			cin >> number;

			cout << endl << "The current customer information at the " << number << " index is: " << endl << endl;
			cout << firstName[number - 1] << endl;
			cout << lastName[number - 1] << endl;
			cout << email[number - 1] << endl;
			cout << phoneNumber1[number - 1] << endl;
			cout << phoneNumber2[number - 1] << endl;
			cout << comment[number - 1] << endl << endl;

			cout << "Enter the new customer information that will replace the current customer information! " << endl << endl;
			cout << "Enter Your First Name: ";
			cin >> firstName[number - 1];
			cout << "Enter Your Last Name: ";
			cin >> lastName[number - 1];
			cout << "Enter Your Email: ";
			cin >> email[number - 1];

			size_t at = email[number - 1].find('@');

			if (at == string::npos)
			{
				cout << "Your email adress is missing @ symbol! Try again!" << endl;
				cout << "Enter Your Email: ";

				cin >> email[number - 1];
			}

			size_t dot = email[number - 1].find('.', at + 1);

			if (dot == string::npos)
			{
				cout << "Your email adress is missing . symbol after @! Try again!" << endl;
				cout << "Enter Your Email: ";

				cin >> email[number - 1];
			}

			cout << "Enter Your First Phone Number: ";
			cin >> phoneNumber1[number - 1];
			cout << "Enter Your Second Phone Number: ";
			cin >> phoneNumber2[number - 1];
			cout << "Enter a comment about Yourself: ";
			cin.ignore();
			getline(std::cin, comment[number - 1]);

			cout << endl << "Do You wish to edit another customer? Y/N" << endl;

			char charForEdit;
			cin >> charForEdit;

			if (charForEdit == 'Y')
			{
				system("CLS");
				editCustomer();
			}

			else if (charForEdit == 'N')
			{
				cout << "Do You wish to delete an existing customer? Y/N" << endl;

				char charForDelete;
				cin >> charForDelete;

				if (charForDelete == 'Y')
				{
					system("CLS");
					deleteCustomer();
				}

				else if (charForDelete == 'N')
				{
					cout << "Do You wish to add a customer? Y/N" << endl;

					char charForAdd;
					cin >> charForAdd;

					if (charForAdd == 'Y')
					{
						cout << endl << "Do You wish to add a customer from a console or from a .csv file?" << endl << endl;
						cout << "1 - Console" << endl;
						cout << "2 - File" << endl << endl;

						int addChoice;
						cin >> addChoice;

						if (addChoice == 1)
						{
							system("CLS");
							addCustomer();
						}

						else if (addChoice == 2)
						{
							system("CLS");
							addCustmerFromCSV();
						}
					}
				}
			}
		}
		
	}

	void deleteCustomer()
	{
		if (amountOfCustomers == 0)
		{
			cout << "There are no registered customers at the moment!" << endl << endl;
			cout << "Do You wish to add a customer? Y/N" << endl;

			char charForAdd;
			cin >> charForAdd;

			if (charForAdd == 'Y')
			{
				cout << endl << "Do You wish to add a customer from a console or from a .csv file?" << endl << endl;
				cout << "1 - Console" << endl;
				cout << "2 - File" << endl << endl;

				int addChoice;
				cin >> addChoice;

				if (addChoice == 1)
				{
					system("CLS");
					addCustomer();
				}

				else if (addChoice == 2)
				{
					system("CLS");
					addCustmerFromCSV();
				}
			}
		}

		else
		{
			cout << "**************************************************" << endl;
			cout << "                 DELETE CUSTOMER                  " << endl;
			cout << "**************************************************" << endl << endl;

			cout << "At the moment the amount of customers is " << amountOfCustomers << endl << endl;
			cout << "Enter the index number of the customer You wish to delete: ";

			unsigned int number;
			cin >> number;

			cout << endl << "The current customer information at the " << number << " index is: " << endl << endl;
			cout << firstName[number - 1] << endl;
			cout << lastName[number - 1] << endl;
			cout << email[number - 1] << endl;
			cout << phoneNumber1[number - 1] << endl;
			cout << phoneNumber2[number - 1] << endl;
			cout << comment[number - 1] << endl << endl;
			cout << "Are You sure You want to delete this customer? Y/N" << endl;

			char charForDelete;
			cin >> charForDelete;

			if (charForDelete == 'Y')
			{
				firstName[number - 1] = "";
				lastName[number - 1] = "";
				email[number - 1] = "";
				phoneNumber1[number - 1] = 0;
				phoneNumber2[number - 1] = 0;
				comment[number - 1] = "";
				amountOfCustomers--;

				cout << endl << "The " << number << " customer successfully deleted!" << endl;
				cout << endl << "Do You wish to delete another customer? Y/N" << endl;
				
				if (charForDelete == 'Y')
				{
					system("CLS");
					deleteCustomer();
				}

				else if (charForDelete == 'N')
				{
					cout << "Do You wish to edit an existing customer? Y/N" << endl;

					char charForEdit;
					cin >> charForEdit;

					if (charForEdit == 'Y')
					{
						system("CLS");
						editCustomer();
					}

					else if (charForEdit == 'N')
					{
						cout << "Do You wish to add a customer? Y/N" << endl;

						char charForAdd;
						cin >> charForAdd;

						if (charForAdd == 'Y')
						{	
							cout << endl << "Do You wish to add a customer from a console or from a .csv file?" << endl << endl;
							cout << "1 - Console" << endl;
							cout << "2 - File" << endl << endl;

							int addChoice;
							cin >> addChoice;

							if (addChoice == 1)
							{
								system("CLS");
								addCustomer();
							}

							else if (addChoice == 2)
							{
								system("CLS");
								addCustmerFromCSV();
							}
						}
					}
				}
			}
		}
	}
};

int main()
{	
	CustomerRegistartionSystem crm;
	crm.mainMenu();
}
