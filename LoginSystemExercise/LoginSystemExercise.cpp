//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//Login System Demo - Filesystem, File storing, and Registration.
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


#include <iostream>
#include <fstream> //For writing and reading files. 
#include <string>

using namespace std;


//Checks to see if the User is logged in.
bool IsLoggedIn()
{
	string username, password, un, pw;

	cout << "Please enter your Username: ";
	cin >> username;

	cout << "Please enter your Password: ";
	cin >> password;

	//Creates a text file in our containing folder, with the value entered for username. 
	ifstream read("C:\\Users\\User\\source\\repos\\LoginSystemExercise\\Debug\\" + username + ".txt");
	getline(read, un); //Reads file and assigns value to un.
	getline(read, pw); //" ".
	read.close();

	if (un == username && pw == password)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int choice;

	cout << "I)Register\nII)Login\nPlease enter your choice: ";
	cin >> choice;

	if (choice == 1)
	{
		string username, password;
		cout << "Please select a Username: ";
		cin >> username;
		
		cout << "Please select a Password: ";
		cin >> password;

		//Writes to file.
		ofstream file; 
		file.open("C:\\Users\\User\\source\\repos\\LoginSystemExercise\\Debug\\" + username + ".txt");  
		file << username << endl << password << endl;
		file.close();

		main();
	}
	else if (choice == 2) //Checks and updates our login status.
	{
		bool status = IsLoggedIn();

		if (!status)
		{
			cout << "Incorrect login. Please try again." << endl; //Displays if User eneters incorrect information.
			system("PAUSE");
			return 0;
		}
		else
		{
			cout << "Login successful." << endl;
			system("PAUSE");
			return 1;
		}
	}
}


