
#pragma once
#include <iostream>
#include "Editor.h"

using namespace std;
int main()
{
	Editor flights;
	flights.readFromFile();
	int hour, min;
	bool exit = false;
	cout << "Welcome to Airport Flight Control"
		<< "\nPlease, enter current time"
		<< "\nHours :";
	cin >> hour;
	cout << "\Minustes: ";
	cin >> min;
	do {
		int choice;
		cout << "\n1)Enter a new flight"
			<< "\n2)Cancel a flight"
			<< "\n3)Modify time of a flight"
			<< "\n4)Add delay to a flight"
			<< "\n5)Display all flights"
			<< "\n6)Display departure flights"
			<< "\n7)Display arrival flights"
			<< "\n8)Exit";
		cout << "\nChoise: ";
		cin >> choice;
		switch (choice) {
		case 1:
			flights.addFlight();
			break;
		case 2:
			flights.deleteFlight();
			break;
		case 3:
			flights.editTime();
			break;
		case 4:
			flights.addDelay();
			break;
		case 5:
			flights.displayAll();
			break;
		case 6:
			flights.displayDepFlights(hour, min);
			break;
		case 7:
			flights.displayArrFlights(hour, min);
			break;
		case 8:
			flights.loadToFile(hour, min);
			exit = true;
			break;
		}
	} while (exit != true);

	


}

