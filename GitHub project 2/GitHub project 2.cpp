#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


struct PROJECT2
{
	string fName;
	string lName;
	string password;
	string username;
	int id = 0;
	int telephoneNumber;
};

void checkForWrongInput(double variable) //Makes you enter a new option until you have entered a correct one
{
	while (cin.fail())
	{
		cout << endl << endl;
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

int getUserIndexById(PROJECT2* users, int& counter, int user)//Returns the index of the user
{
	for (int i = 0; i < counter; i++)
	{
		if (users[i].id == user)
			//it checks if the id in the array matches the id that is integrated and if it's true it returns the index of that element
		{
			return i;
		}
	}

	return -1;//its like an error
}

int findUserByUsername(string username, int count, PROJECT2* users) //Checks if you entered your Username Correctly
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

int findUserByPassword(string password, int count, PROJECT2* users) //Checks if you entered your Password Correctly
{
	for (int i = 0; i < count; i++)
	{
		if (users[i].password == password)
		{
			return i;
		}
	}
	return -1;
}

int findUserByTelephoneNumber(int telNumber, int count, PROJECT2* users) //Checks if you entered your Telephone Number Correctly
{
	for (int i = 0; i < count; i++)
	{
		if (users[i].telephoneNumber == telNumber)
		{
			return i;
		}
	}
	return -1;
}

void usersPasswordToStars(PROJECT2 users)//Hides the user's pasword
{

	for (int i = 0; i < users.password.length(); i++)
	{
		cout << "*";
	}
}

void deleteUser(PROJECT2* users, int& counter, int user)//Deletes the user's info
{
	int index = getUserIndexById(users, counter, user);
	for (int i = 0; i < counter - 1; i++)
	{
		users[i] = users[i + 1];
	}
	counter--;
}

void showUser(PROJECT2 users)//Displays the user's info
{
	cout << "User's Full name: ";
	cout << users.fName << " " << users.lName << endl;
	cout << "User's telephone number: ";
	cout << users.telephoneNumber << endl;
	cout << "User's username: ";
	cout << users.username << endl;
	cout << "User's password: ";
	usersPasswordToStars(users); cout << endl;
	cout << endl;
}

void showAllUsers(PROJECT2* users, int& counter, string username)//function for showing all customers with loop
{

	for (int i = 0; i < counter; i++)
	{
		if (users[i].username == username)
		{
			showUser(users[i]);
		}

	}
}

bool checkForforgottenPassword(string username, int telephoneNumber, int count, PROJECT2* users)//Checks if the username and the telephone number are correct
{
	for (int i = 0; i < count; i++)
	{
		if (users[i].username == username && users[i].telephoneNumber == telephoneNumber)
		{
			return 1;
		}
	}
	return 0;
}

bool checkForForgottenUsername(int telephoneNumber, int count, PROJECT2* users)//Checks if the telephone number is correct
{
	for (int i = 0; i < count; i++)
	{
		if (users[i].telephoneNumber == telephoneNumber)
		{
			return 1;
		}
	}
	return 0;
}

bool grantAccess(string username, string password, int count, PROJECT2* users)//Checks if you entered your Username and Password Correctly
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

////////////////Data Layer///////////////////////////////////////////////Data Layer///////////////////////////////////////////////Data Layer///////////////////////////////


void forgottenPassword(int& counter, PROJECT2* users)//Checks if your username and telephone number are correct and changes the password of the user
{
	cout << "Verification" << endl << endl;
	string username;
	cout << "Enter your username: ";
	cin >> username;
	int phoneNumber;
	cout << "Enter your phone number: ";
	cin >> phoneNumber;

	if (checkForforgottenPassword(username, phoneNumber, counter, users))
	{
		string newPassword;

		cout << endl;
		cout << "Enter your new password: ";
		cin >> newPassword;

		while (!checkPassword(newPassword))
		{
			system("cls");
			cout << "Your password must have at least 8 symbols, 1 small letter and 1 big letter" << endl;
			cout << "Try with another password: ";
			getline(cin, newPassword);
		}
		int userIndex = findUserByUsername(username, counter, users);
		users[userIndex].password = newPassword;
	}
}

void forgottenUsername(int& counter, PROJECT2* users)//Checks if your telephone number is correct and changes the username of the user
{
	
	cout << "Verification" << endl << endl;
	int phoneNumber;
	cout << "Enter your phone number: ";
	cin >> phoneNumber;
	
	if (checkForForgottenUsername( phoneNumber, counter, users))
	{
		string newUsername;
		cout << endl;
		cout << "Enter your new username: ";
		cin >> newUsername;

		int userIndex = findUserByTelephoneNumber(phoneNumber, counter, users);
		users[userIndex].username = newUsername;
	}
}

bool forgottenUserInfoMenu(int& counter, PROJECT2* users)//Display 2 option if you have enterred your password/username incorrect 3 times in a row 
{

	cout << "1. Forgot pasword?" << endl;
	cout << "2. Forgot username?" << endl;

	int choice;
	cout << "Enter your choice: ";
	cin >> choice;
	system("cls");
	checkForWrongInput(choice);
	switch (choice)
	{
	case 1:forgottenPassword(counter, users);

		break;

	case 2:forgottenUsername(counter, users);
		break;

	default:cout << "Try choosing an available option. :)" << endl << endl;
		break;
	}
	return 1;
}

void changeUsername(int& counter, PROJECT2* users)//You can change your username when you log in your account
{
	cout << "Verification" << endl << endl;
	string username;
	cout << "Enter your username: ";
	cin >> username;
	string password;
	cout << "Enter your password: ";
	cin >> password;
	if (grantAccess(username, password, counter, users))
	{
		string newUsername;

		cout << endl;
		cout << "Enter your new username: ";
		cin >> newUsername;

		int userIndex = findUserByPassword(password, counter, users);
		users[userIndex].username = newUsername;


	}

}

void changePassword(int& counter, PROJECT2* users)//You can change your pasword when you log in your account
{
	cout << "Verification" << endl << endl;
	string username;
	cout << "Enter your username: ";
	cin >> username;
	string password;
	cout << "Enter your password: ";
	cin >> password;
	if (grantAccess(username, password, counter, users))
	{
		string newPassword;

		cout << endl;
		cout << "Enter your new password: ";
		cin >> newPassword;

		while (!checkPassword(newPassword))
		{
			system("cls");
			cout << "Your password must have at least 8 symbols, 1 small letter and 1 big letter" << endl;
			cout << "Try with another password: ";
			getline(cin, newPassword);
		}
		int userIndex = findUserByUsername(username, counter, users);
		users[userIndex].password = newPassword;


	}

}

bool subMenu(int& counter, PROJECT2* users, int user, string username) //SubMenu that shows different options
{

	cout << "1. Show user info" << endl;
	cout << "2. Delete user" << endl;
	cout << "3. Change password" << endl;
	cout << "4. Change username" << endl;
	cout << "9. Sign out" << endl;

	int choice;
	cout << "Enter your choice: ";
	cin >> choice;

	checkForWrongInput(choice);
	system("cls");
	switch (choice)
	{
	case 1:showAllUsers(users, counter, username);
		break;

	case 2:deleteUser(users, counter, user);
		return 0;
		break;
	case 3:changePassword(counter, users);
		return 0;
		break;

	case 4:changeUsername( counter, users);
		return 0;
		break;

	case 9: return 0;
		break;

	default:
		break;
	}
	return 1;
}

void registration(int& counter, PROJECT2* users) //Creating user account
{
	cout << "First Name: ";
	cin >> users[counter].fName;
	cout << "Last Name: ";
	cin >> users[counter].lName;
	cout << "Telephone number: ";
	cin >> users[counter].telephoneNumber;
	checkForWrongInput(users[counter].telephoneNumber);
	cout << "Username: ";
	cin.ignore();
	getline(cin, users[counter].username);


	while (findUserByUsername(users[counter].username, counter, users) != -1)
	{
		system("cls");
		cout << "This username is already taken!" << endl;
		cout << "Try with another username: ";
		getline(cin, users[counter].username);

	}
	cout << "Password: ";
	getline(cin, users[counter].password);
	while (!checkPassword(users[counter].password))
	{
		system("cls");
		cout << "Your password must have at least 8 symbols, 1 small letter and 1 big letter" << endl;
		cout << "Try with another password: ";
		getline(cin, users[counter].password);
	}
	counter++;
}

void signIn(int& counter, PROJECT2* users) //Login System
{
	int wrongCounter = 0;
	string username, password;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;
	system("cls");
	while (!grantAccess(username, password, counter, users) && wrongCounter != 3)
	{
		system("cls");
		cout << "Your username/password is incorrect" << endl;
		cout << "Please try again" << endl;
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;
		system("cls");
		wrongCounter++;
		if (wrongCounter == 3)
		{
			forgottenUserInfoMenu(counter, users);
		}
	}

	int user = findUserByUsername(username, counter, users);
	if (grantAccess(username, password, counter, users) && wrongCounter != 3)
	{
		bool showMenu;
		do
		{

			showMenu = subMenu(counter, users, user, username);
		} while (showMenu);
	}
}

bool mainMenu(PROJECT2* users, int& counter)
{
	system("cls");
	cout << "1. Registration" << endl;
	cout << "2. Sign in" << endl;
	cout << "9. Exit" << endl;

	int choice;
	cout << "Enter your choice: ";
	cin >> choice;

	checkForWrongInput(choice);
	switch (choice)
	{
	case 1:registration(counter, users);
		break;

	case 2:signIn(counter, users);
		break;

	default:cout << "Try choosing an available option!" << endl << endl;
		break;

	case 9: return 0;

	}
	return 1;
}

int main()
{

	system("color b");

	PROJECT2 users[64];

	int counter = 0;

	bool showMenu = true;
	do
	{
		showMenu = mainMenu(users, counter);


	} while (showMenu);
}

