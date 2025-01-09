#pragma once
#include "List.h"
class Editor {
private:
	List<FlightRec> flights;
public:
	void addFlight();
	void deleteFlight();
	void editTime();
	void addDelay();
	void adaptTime(int& h, int& m);
	void readFromFile();
	void displayAll();
	void displayDepFlights(int hour, int min);
	void displayArrFlights(int hour, int min);
	void loadToFile(int hour, int min);
};