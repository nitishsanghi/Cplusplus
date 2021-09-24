#include "processor.h"
#include "linux_parser.h"
#include <chrono>
#include <thread>
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() { 
	vector<string> cpuutil_prev = LinuxParser::CpuUtilization();
	vector<string> cpuutil_curr;
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	cpuutil_curr = LinuxParser::CpuUtilization();
	
	long idle_prev = stol(cpuutil_prev[4]) + stol(cpuutil_prev[5]);
	long nonidle_prev = stol(cpuutil_prev[1]) + stol(cpuutil_prev[2]) + stol(cpuutil_prev[3]) + stol(cpuutil_prev[6]) + stol(cpuutil_prev[7]) + stol(cpuutil_prev[8]);
	long idle_curr = stol(cpuutil_curr[4]) + stol(cpuutil_curr[5]);
	long nonidle_curr = stol(cpuutil_curr[1]) + stol(cpuutil_curr[2]) + stol(cpuutil_curr[3]) + stol(cpuutil_curr[6]) + stol(cpuutil_curr[7]) + stol(cpuutil_curr[8]);
	long total_prev = idle_prev + nonidle_prev;
	long total_curr = idle_curr + nonidle_curr;
	long total_d = total_curr - total_prev;
	long idle_d = idle_curr - idle_prev;

	return (double)(total_d - idle_d)/(double)total_d; }
