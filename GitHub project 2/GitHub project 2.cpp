#include <iostream>
#include<string>
using namespace std;

struct SITE
{
	string fName;
	string sName;
	string lName;
	int phoneNumber=0;
	int USN=0; //UNIQUE SITIZEN NUMBER (≈√Õ)
	string password;
	string username;
};

void checkForWrongInput(double variable) //Makes you enter a new option until you have entered a correct one
{
	while (cin.fail())
	{
		cout << "Enter a number, please!" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> variable;
	}
}

bool checkPassword(string password) //Checks if your password contains small and big letters
{
	int countSmallLetters = 0;
	int countBigLetters = 0;
	for (size_t i = 0; i < password.size(); i++)
	{
		if (password[i] >= 'A' && password[i] <= 'Z')
		{
			countBigLetters++;
		}
		else if (password[i] >= 'a' && password[i] <= 'z')
		{
			countSmallLetters++;
		}
	}
	if (password.size() < 8 || countSmallLetters == 0 || countBigLetters == 0)
	{
		return 0;
	}
	return 1;

}

int findUserByUsername(string username, int count, SITE* users) //Checks if you entered your Username and Password Correctly
{
	for (int i = 0; i < count; i++)
	{
		if (users[i].username == username)
		{
			return i;
		}
	}
	return -1;
}

void registration(int& counter, SITE* users) //creating user account
{
	cout << "First Name: ";
	cin >> users[counter].fName;
	cout << "Second Name: ";
	cin >> users[counter].sName;
	cout << "Third Name: ";
	cin >> users[counter].lName;
	cout << "telephone number: ";
	cin >> users[counter].phoneNumber;
	checkForWrongInput(users[counter].phoneNumber);
	cout << "USN: ";
	cin >> users[counter].USN;
	checkForWrongInput(users[counter].USN);
	cout << "Username: ";
	cin.ignore();
	getline(cin, users[counter].username);

	while (findUserByUsername(users[counter].username, counter, users) != -1)
	{
		cout << "This username is already taken!" << endl;
		cout << "Try with another username: ";
		getline(cin, users[counter].username);
	}
	cout << "Password: ";
	getline(cin, users[counter].password);
	while (!checkPassword(users[counter].password))
	{
		cout << "Your password must have at least 8 symbols, 1 small letter and 1 big letter" << endl;
		cout << "Try with another password: ";
		getline(cin, users[counter].password);
	}
	counter++;
}

bool grantAccess(string username, string password, int count, SITE* users) //Checks if you 
{
	for (int i = 0; i < count; i++)
	{
		if (users[i].username == username && users[i].password == password)
		{
			return 1;
		}
	}
	return 0;
}


////////////////////////////////////////////////////
bool mainMenu(SITE* users, int& counter)
{
	int choice;
	cin >> choice;
	checkForWrongInput(choice);
	switch (choice)
	{
	case 1:
		break;

	case 2:
		break;

	case 3:

		break;

	default:cout << "Try choosing an available option!" << endl << endl;
		break;

	case 9: return 0;

	}
	return 1;
}

bool subMenu(int& count, SITE* users, int user) //SubMenu that shows different options
{
	cout << "Insert " << endl;
	cout << "" << endl;

	int choice;
	cout << "Enter your choice: ";
	cin >> choice;
	system("cls");
	checkForWrongInput(choice);
	switch (choice)
	{
	case 1: 
		break;

	case 2:
		break;

	case 3:
		break;

	case 4:
		break;

	case 9: return 0;
		break;

	default:cout << "Try choosing an available option. :)" << endl << endl;
		break;
	}
	return 1;
}

void login(int& counter, SITE* users) //Login System
{
	int wrongCounter = 0;
	string username, password;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;
	while (!grantAccess(username, password, counter, users) && wrongCounter != 3)
	{
		cout << "Your username/password is incorrect" << endl;
		cout << "Please try again" << endl;
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;
		wrongCounter++;
	}
	int user = findUserByUsername(username, counter, users);
	if (grantAccess(username, password, counter, users) && wrongCounter != 3)
	{
		bool showMenu;
		do
		{
			showMenu = subMenu(counter, users, user);
		} while (showMenu);
	}
}

int main()
{
	SITE users[64];

	int counter = 0;

	bool showMenu = true;
	do
	{
		showMenu = mainMenu(users, counter);
		

	} while (showMenu);
}