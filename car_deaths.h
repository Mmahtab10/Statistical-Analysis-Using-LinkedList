#include "list.h"

#ifndef hydro_h
#define hydro_h

void displayHeader();

int readData(FlowList &x);
// that reads records years and no. of deaths from input file (car.txt), 
// inserts them into the list, 
// and returns the number of records in the file.

int menu();
//that displays a menu and returns the user’s choice (an integer 1 to 5).

void display(const FlowList &x);
//that displays years and deaths, and shows the average of the deaths in the list (calling
//function averge).

void addData(FlowList &list);
//that prompts the user to enter new data, inserts the data into the linked list, and
//updates the number of records.

void removeData(FlowList& x);
//that prompts the user to indicate what year to be removed, removes a single
//record from the list, and updates the number of records.

double average(const FlowList& lst);
//that returns the flow average in the given list

void saveData(const FlowList& obj);
//that opens the car.txt file for writing and writes the contents of the linked list
//into the file.

void pressEnter();
//that displays <<<Press Enter to Continue>>>, and waits for the user
// to press the <Return Key> 
#endif