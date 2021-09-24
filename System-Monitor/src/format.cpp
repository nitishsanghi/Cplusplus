#include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
	int hours = 0;
	int minutes = 0;
	int left_minutes = 0;
	int left_seconds = 0;
	string time, HH, MM, SS;
	minutes = seconds / 60;
	left_seconds = seconds % 60;
	hours = minutes / 60;
	left_minutes = minutes % 60;

	HH = std::to_string(hours);
	MM = std::to_string(left_minutes);
	SS = std::to_string(left_seconds);

	if(hours < 10) HH = "0" + HH;
	if(left_minutes < 10) MM = "0" + MM;
	if(left_seconds < 10) SS = "0" + SS;
	time = HH + ":" + MM + ":" + SS;

	return time; }
