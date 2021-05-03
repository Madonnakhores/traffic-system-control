# include <iostream> 
# include <string>
using namespace std;
const int numberOfCars = 3;
const int numberOfUsers = 3;
const int MAXSPEED = 100;

struct date { int day, month, year; };
struct fine
{
	string streetName;
	float value;
	date DOF;
	char status = 'U';
};
struct car
{
	string plateNumber;
	string model;
	fine fines[20] = {};
	int productionYear;
	float totalValueOfFine = 0;
	int violationCounter = 0;
};
struct user
{
	int licenseNumber;
	string personName;
	date DOB;
	car cars[numberOfCars];
} users[numberOfUsers];
// search function
void search(user users[], int numberOfUsers, int numberOfCars)
{
	string name, platenumber;

	cout << "enter the driver name and plate number of your\t";  cin >> name >> platenumber;
	for (int i = 0; i < numberOfUsers; i++)
	{
		for (int j = 0; j < numberOfCars; j++)
		{
			if (users[i].personName == name && users[i].cars[j].plateNumber == platenumber)
			{
				cout << "the informations about this car are:" << endl;
				cout << "model: " << users[i].cars[i].model << endl;
				for (int counter = 0; counter < 20; counter++)
				{
					if (users[i].cars[i].fines[counter].value == 0 && counter == 0)
					{
						cout << "the driver doesn't have fines" << endl;
						break;
					}
					else
					{
						cout << "all fines: " << endl;
						for (int counter = 0; counter < 20; counter++)
						{
							if (users[i].cars[i].fines[counter].value == 0)
							{
								break;
							}
							cout << "fine value: " << users[i].cars[i].fines[counter].value << endl;
							cout << " the street name: " << users[i].cars[i].fines[counter].streetName << endl;
							cout << "fine date " << users[i].cars[i].fines[counter].DOF.day << " \ " << users[i].cars[i].fines[counter].DOF.month << " \ "
								<< users[i].cars[i].fines[counter].DOF.year << endl;
							cout << "fine status: " << users[i].cars[i].fines[counter].status << endl;

						}
						break;
					}
					cout << "production year: " << users[i].cars[i].productionYear << endl;
					break;
				}
			}
			break;
		}
	}
}
// violation function
void violation(user users[], int numberOfUsers, int numberOfCars, int MAXSPEED)
{
	string name, platenumber;
	float speed;

	cout << "enter the driver name and plate number of the car \t"; cin >> name >> platenumber;
	for (int i = 0; i < numberOfUsers; i++)
	{
		for (int j = 0; j < numberOfCars; j++)
		{
			if (users[i].personName == name && users[i].cars[j].plateNumber == platenumber)
			{
				cout << "enter the speed of the driver's car: ";   cin >> speed;
				if (speed > MAXSPEED)
				{
					users[i].cars[j].fines[users[i].cars[j].violationCounter].value = (speed - MAXSPEED) * 2;
					cout << "the fine value is: " << users[i].cars[j].fines[users[i].cars[j].violationCounter].value << endl;
					cout << "enter the street name \t";
					cin >> users[i].cars[j].fines[users[i].cars[j].violationCounter].streetName;  cout << endl;
					cout << "enter the fine date\t";
					cin >> users[i].cars[j].fines[users[i].cars[j].violationCounter].DOF.day >> users[i].cars[j].fines[users[i].cars[j].violationCounter].DOF.day
						>> users[i].cars[j].fines[users[i].cars[j].violationCounter].DOF.year; cout << endl;
					users[i].cars[j].violationCounter++;
				}
			}
			break;
		}
	}
}
//total amount of unpaid fines
void totalAmountOfUnpaidFines(user users[], int numberOfUsers, int numberOfCars)
{
	string name, platenumber;

	char choose;
	cout << "enter the driver name and plate number of the car \t"; cin >> name >> platenumber;
	for (int i = 0; i < numberOfUsers; i++)
	{
		for (int j = 0; j < numberOfCars; j++)
			if (users[i].personName == name && users[i].cars[j].plateNumber == platenumber)
			{
				for (int counter = 0; counter <= users[i].cars[j].violationCounter; counter++)
					users[i].cars[j].totalValueOfFine += users[i].cars[j].fines[counter].value;

				for (int counter = 0; counter <= users[i].cars[j].violationCounter; counter++)
				{
					if (users[i].cars[j].totalValueOfFine == 0)
					{
						cout << "the driver doesn't have fines to pay" << endl;
						break;
					}
					else
					{
						cout << "the total amount of unpaid fines of this car is : " << users[i].cars[j].totalValueOfFine << endl;
						cout << "do you want to pay all the fines?(y/n)\t"; cin >> choose;
						if (choose == 'y' || choose == 'Y')
						{
							users[i].cars[j].violationCounter = 0;
							users[i].cars[j].totalValueOfFine = 0;
							users[i].cars[j].fines[counter].status = ' p ';
							users[i].cars[j].fines[counter].streetName = "0";
							users[i].cars[j].fines[counter].DOF.day = 0;
							users[i].cars[j].fines[counter].DOF.month = 0;
							users[i].cars[j].fines[counter].DOF.year = 0;
							for (int counter = 0; counter < 20; counter++)
								users[i].cars[j].fines[counter].value = 0;
						}
					}
				}
			}

	}
}

int main()
{
	system("COLOR 70");
	//information about every user
	users[0].licenseNumber = 2012;  users[0].personName = "mariam";  users[0].DOB.day = 12;  users[0].DOB.month = 12;  users[0].DOB.year = 1998;
	users[0].cars[0].plateNumber = "234MDA";  users[0].cars[0].model = "BMW";  users[0].cars[0].productionYear = 2010;

	users[1].licenseNumber = 2112;  users[1].personName = "veronia";  users[1].DOB.day = 1;  users[1].DOB.month = 1;  users[1].DOB.year = 1996;
	users[1].cars[0].plateNumber = "333ABC";  users[1].cars[0].model = "hyundai";  users[1].cars[0].productionYear = 2015; users[1].cars[1].plateNumber = "654RAG";
	users[1].cars[1].model = "kia"; users[1].cars[1].productionYear = 2011;

	users[2].licenseNumber = 5642;  users[2].personName = "rogina";  users[2].DOB.day = 7;  users[2].DOB.month = 8;  users[2].DOB.year = 2001;
	users[2].cars[0].plateNumber = "534MBA";  users[2].cars[0].model = "mini cooper";  users[2].cars[0].productionYear = 2016; users[2].cars[1].plateNumber = "111MMM";
	users[2].cars[1].model = " honda"; users[2].cars[1].productionYear = 2005; users[2].cars[2].plateNumber = "987ASD";
	users[2].cars[2].model = "honda"; users[2].cars[1].productionYear = 2008;


	//variables
	int key;
	char choice;


	//the system will start 
	cout << "\t\t\t\t\t* traffic control system*" << endl;
	cout << "your data are already collected." << endl;
	while (1)
	{
		cout << "please choose your task and enter his number." << endl;
		cout << "1- search for a specific car \t  2- add a new fine for someone \t  3- know and pay your total amount of unpaid fines" << endl;
		cin >> key;
		if (key != 1 && key != 2 && key != 3)
		{
			cout << "invalid entry try again" << endl;
			continue;
		}
		else if (key == 1)
		{
			search(users, numberOfUsers, numberOfCars);
		}
		else if (key == 2)
		{
			violation(users, numberOfUsers, numberOfCars, MAXSPEED);
		}
		else if (key == 3)
		{
			totalAmountOfUnpaidFines(users, numberOfUsers, numberOfCars);
		}

		cout << "do you have another task?(y/n)" << endl;
		cin >> choice;
		if (choice == 'n' || choice == 'N')
			break;
		else if (choice == ' y ' || choice == 'Y')
			continue;
	}

	system("pause");

}