#pragma once
#include <string>
using namespace std;
enum FlightType {Departure, Arrival};

struct TimeRec {
	int hour;
	int min;
};

struct FlightRec {
	string FlightNO;
	string Destination;
	TimeRec Time;
	FlightType Ftype;
	bool Delay;
	TimeRec ExpectedTime;
};

bool operator<(const FlightRec& left, const FlightRec& right) {
	if (left.Time.hour < right.Time.hour) {
		return true;
	}
	else if (left.Time.hour == right.Time.hour) {
		return left.Time.min < right.Time.min;
	}
	return false;
}

bool operator==(const FlightRec& left, const FlightRec& right) {
	return (left.FlightNO == right.FlightNO);
}

