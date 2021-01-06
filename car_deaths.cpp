#include "car_deaths.h"
#include "list.h"
#include <fstream>
#include <iostream>
using namespace std;

int main(void)
{
	FlowList x;
	int numRecords;
	displayHeader();
	numRecords = readData(x);
	int quit =0;

	while(0 == quit)
	{
		switch(menu())
		{
			case 1:
			display(x);
			pressEnter();
			break;

			case 2:
			addData(x);
			pressEnter(); 
			break;

			case 3:
			saveData(x);
			pressEnter(); 
			break;

			case 4:
			removeData(x);
			pressEnter();
        	break;

        	case 5:
        	cout << "\nProgram terminated successfully!\n\n"; 
        	quit = 1;
			break;

			default:
					cout << "\nNot a valid input.\n"; 
					pressEnter();

		}
	}
}
void displayHeader()
{
	cout << "\nNumber of deaths per year due to car accidents" << endl;
	pressEnter();
}

int menu()
{
	cout << "\nPlease select one of the following operations:"<< endl;
	cout << "1. Display deaths per year, and the average." << endl;
	cout << "2. Add data" << endl;
	cout << "3. Save data into the file" << endl;
	cout << "4. Remove data" << endl;
	cout << "5. Quit" << endl;
	cout << "Enter your choice (1, 2, 3, 4, of 5):" << endl;

	int inp;
	cin >> inp;
	return inp;
}

void display(const FlowList &x)
{
	x.print();
	//display average
	cout << "The average number of deaths per year due to car accidents: " << average(x) << endl;
}

void pressEnter()
{
	cout << "\n<<< Press Enter to Continue>>>>\n"; 
	cin.get();
}

int readData(FlowList &x)
{
	ifstream inObj("car.txt");
	if(! inObj)
	{
		cout << "Error: cannot open the file" << endl;
		exit(1);
	}
	double flo;
	int yer;
	int i =0; 
	
	while(inObj.good())
	{
		//read from file using inObj and store into yer and flo
		inObj >> yer >> flo;
		if(! inObj)
			break;
		i++;
		x.insert(yer,flo);	
	}
	inObj.close();
	return i;
}

void removeData(FlowList& x)
{
	int year;
	cout << "Please enter the year that you want to remove:\t" << endl;
	cin >> year;
	if(x.member(year))
	{
		x.remove(year);
		cout << "Record was successfully removed. " << endl;
	}
	else
	{
		cout << "Error: No such a data." << endl;
	}
}

void saveData(const FlowList& obj)
{
	ofstream outObj;
	outObj.open("car.txt", ios::trunc);

	if (! outObj) 
	{
		cout << "Error: cannot open the file "<< endl; 
		exit(1);
	}

	//write to file
	outObj << endl;
	for (Node* ptr = obj.head(); ptr != 0; ptr = ptr->next) 
	{
		outObj << setw(10) << ptr->item.year << setw(10) << ptr->item.flow << endl;	
	}
	outObj.close();
	cout << "Data are saved into the file." << endl;
}

void addData(FlowList &list)
{
	int year;
	double deaths;
	cout << "Please enter a year: ";
	cin >> year;

	cout << "\nPlease enter the number of deaths: ";
	cin >> deaths;
	if(list.member(year))
	{
		cout << "\nError: Duplicate data" << endl;
	}
	else
	{
		list.insert(year,deaths);
		cout << "\nNew record inserted successfully." << endl;
	}
}

double average(const FlowList& lst) 
{
	return lst.average();
}