#pragma once
#include <iostream>
#include "Editor.h"
#include <fstream>
using namespace std;

void Editor::addFlight() {
	FlightRec flight;
	char choice;
	cout << "\nEnter d for departing flight"
		<< "\nEnter a for arriving flight"
		<< "\nChoice: ";
	cin >> choice;
	cout << "\nEnter flight number: ";
	cin >> flight.FlightNO;
	cout << "\nEnter destination: ";
	cin >> flight.Destination;
	cout << "\nEnter time: "
		<< "\nHours: ";
	cin >> flight.Time.hour;
	cout << "\nMinutes: ";
	cin >> flight.Time.min;
	flight.Delay = false;
	switch (choice) {
	case 'd':
		flight.Ftype = Departure;
		flights.insert(flight);
		break;
	case 'a':
		flight.Ftype = Arrival;
		flights.insert(flight);
		break;
	}
}

void Editor::deleteFlight() {
	string fn;
	cout << "\nEnter flight number to delete: ";
	cin >> fn;
	FlightRec flight;
	flight.FlightNO = fn;
	flight.Time.hour = 23;
	flight.Time.min = 59;
	flights.remove(flight);
	
}

void Editor::editTime() {
	int hour, min;
	string fn;
	cout << "Enter a flight number to edit: ";
	cin >> fn;
	cout << "\nEnter new hours: ";
	cin >> hour;
	cout << "\nEnter new minutes: ";
	cin >> min;
	FlightRec flight;
	flight.FlightNO = fn;
	flights.returnElement(flight);
	flights.remove(flight);
	flight.Time.hour = hour;
	flight.Time.min = min;
	if (flight.Delay) {
		flight.Delay = false;
	}
	flights.insert(flight);
}

void Editor::adaptTime(int& h, int& m) {
	if (m >= 60) {
		h += m / 60; 
		m %= 60;     
	}
	if (h >= 24) {
		h %= 24; 
	}
}


void Editor::addDelay() {
	int hour, min;
	string fn;
	cout << "\nEnter flight number to add delay to: ";
	cin >> fn;
	FlightRec flight;
	flight.FlightNO = fn;
	cout << "Enter hours: ";
	cin >> hour;
	cout << "Enter minutes: ";
	cin >> min;
	flights.returnElement(flight);
	flights.remove(flight);
	flight.ExpectedTime.hour = flight.Time.hour + hour;
	flight.ExpectedTime.min = flight.Time.min + min;
	adaptTime(flight.ExpectedTime.hour, flight.ExpectedTime.min);
	flight.Delay = true;
	flights.insert(flight);
}

void Editor::readFromFile() {
	fstream myFile("flights.txt", ios::in);
	if (!myFile.is_open()) {
		cerr << "Error opening file!" << endl;
		return ;
	}
	while (!myFile.eof()) {
		FlightRec flight;
		myFile >> flight.FlightNO;
		myFile >> flight.Destination;
		myFile >> flight.Time.hour;
		myFile >> flight.Time.min;
		myFile >> flight.Delay;
		myFile >> flight.ExpectedTime.hour;
		myFile >> flight.ExpectedTime.min;
		flights.insert(flight);
	}
	myFile.close();

}

void Editor::displayAll() {
	for (int i = 1; i <= flights.size(); i++) {
		FlightRec flight;
		flights.getElement(i, flight);
		cout << endl << flight.FlightNO << " " << flight.Destination
			<< " " << flight.Time.hour << ":" << flight.Time.min << " ";
		if (flight.Delay) {
			cout << "DELAYED" << " " << flight.ExpectedTime.hour << ":" << flight.ExpectedTime.min;
		}
	}
}

void Editor::displayDepFlights(int hour, int min) {
	for (int i = 1; i <= flights.size(); i++) {
		FlightRec flight;
		flights.getElement(i, flight);
		if (flight.Ftype == Departure) {
			if (flight.Delay) {
				if (flight.ExpectedTime.hour >= hour and flight.ExpectedTime.min > min) {
					cout << endl << flight.FlightNO << " "
						<< flight.Destination << " "
						<< flight.Time.hour << ":"
						<< flight.Time.min << " "
						<< "DELAYED" << " "
						<< flight.ExpectedTime.hour << ":"
						<< flight.ExpectedTime.min;
					
				}
			}
			else {
				if (flight.Time.hour >= hour and flight.Time.min > min) {
					cout << endl << flight.FlightNO << " "
						<< flight.Destination << " "
						<< flight.Time.hour << ":"
						<< flight.Time.min;
					
				}
			}
		}
	}
}

void Editor::displayArrFlights(int hour, int min) {
	for (int i = 1; i <= flights.size(); i++) {
		FlightRec flight;
		flights.getElement(i, flight);
		if (flight.Ftype == Arrival) {
			if (flight.Delay) {
				if (flight.ExpectedTime.hour >= hour and flight.ExpectedTime.min > min) {
					cout << endl << flight.FlightNO << " "
						<< flight.Destination << " "
						<< flight.Time.hour << ":"
						<< flight.Time.min << " "
						<< "DELAYED" << " "
						<< flight.ExpectedTime.hour << ":"
						<< flight.ExpectedTime.min;
					
				}
			}
			else {
				if (flight.Time.hour >= hour and flight.Time.min > min) {
					
						cout << endl << flight.FlightNO << " "
						<< flight.Destination << " "
						<< flight.Time.hour << ":"
						<< flight.Time.min;
					
				}
			}
		}
	}
}

void Editor::loadToFile(int hour, int min) {
	fstream myFile("AFC.txt", ios::out);
	if (!myFile.is_open()) {
		std::cerr << "Error: Could not open the file for writing." << std::endl;
		return ;
	}
	myFile << "Current time: " << hour << ":" << min
		<< "\n                        DEPARTURES                        "
		<< "\n  FLIGHT NO     DESTINATION     TIME     DELAYED     EXPECTED-TIME";
	for (int i = 1; i < flights.size(); i++) {
		FlightRec flight;
		flights.getElement(i, flight);
		if (flight.Ftype = Departure) {
			myFile << "\n    " << flight.FlightNO << "       " << flight.Time.hour << ":"
				<< flight.Time.min;
			if (flight.Delay) {
				myFile << "      DELAYED";
				if(flight.ExpectedTime.hour >= hour and flight.ExpectedTime.min > min) {
					myFile << "        " << flight.ExpectedTime.hour << ":" << flight.ExpectedTime.min;
				}
				else {
					myFile << "       ARRIVED";
				}
			}
		}
	}
	myFile.close();

	
}
