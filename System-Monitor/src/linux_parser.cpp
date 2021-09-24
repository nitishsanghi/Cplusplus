#include <dirent.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <iomanip>

#include "linux_parser.h"
#include "format.h"

using std::stof;
using std::string;
using std::to_string;
using std::vector;

// DONE: An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  filestream.close();
  return value;
}

// DONE: An example of how to read data from the filesystem
string LinuxParser::Kernel() {
  string os, version, kernel;
  string line;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> os >> version >> kernel;
  }
  stream.close();
  return kernel;
}

// BONUS: Update this to use std::filesystem
vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}

// TODO: Read and return the system memory utilization
float LinuxParser::MemoryUtilization() {
  string line, key, value, kB;
  int memtotal = -1;
  int memfree = -1;
  std::ifstream stream(kProcDirectory + kMeminfoFilename);
  if(stream.is_open()){
    while(std::getline(stream, line)){
      std::replace(line.begin(), line.end(), ':',' ');
      std::istringstream linestream(line);
      if(linestream >> key >> value >> kB){
          if(key == "MemTotal") {
            std::stringstream s(value);
            s >> memtotal;
          }
          if(key == "MemFree") {
            std::stringstream s(value);
            s >> memfree;
          }
      }
      if (memfree != -1 && memtotal != -1 ) break;
    }
  }
  stream.close();
  return 1-(double)memfree/(double)memtotal; }

// TODO: Read and return the system uptime
long LinuxParser::UpTime() { 
  long uptime_system, idle_time;
  string line;
  std::ifstream stream(kProcDirectory + kUptimeFilename);
  if(stream.is_open()){
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> uptime_system >> idle_time;
  }
  stream.close();
  return uptime_system; }

// TODO: Read and return the number of jiffies for the system
long LinuxParser::Jiffies() { 
	return LinuxParser::UpTime()*sysconf(_SC_CLK_TCK); }

// TODO: Read and return the number of active jiffies for a PID
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::ActiveJiffies(int pid) { 
	string line, s_temp;
	std::istringstream linestream;
	long act_jif = 0;
	std::ifstream stream(kProcDirectory +to_string(pid) + kStatFilename);
	if(stream.is_open()){	
		getline(stream, line);
		linestream.str(line);
		int count = 0;
		while(linestream >> s_temp) {
			++count;
			if(count > 13 && count <18) act_jif += stol(s_temp);	
		}
	}
	stream.close();	
	return act_jif; }

// TODO: Read and return the number of active jiffies for the system
long LinuxParser::ActiveJiffies() { 
	vector<string> cpuutil = LinuxParser::CpuUtilization();
	long act_jif = 0;	
	for(string x:cpuutil){
		if(x != "cpu") act_jif += stol(x);	
	}
	return act_jif; }

// TODO: Read and return the number of idle jiffies for the system
long LinuxParser::IdleJiffies() { 
	vector<string> cpuutil = LinuxParser::CpuUtilization();
	long idle_jif = std::stol(cpuutil[4]) + std::stol(cpuutil[5]);
	return idle_jif; }

// TODO: Read and return CPU utilization
vector<string> LinuxParser::CpuUtilization() { 
	string line;
	std::ifstream stream(kProcDirectory + kStatFilename);
	vector<string> cpuutil_info;
	if(stream.is_open()) {
		getline(stream,line);
		std::istringstream linestream(line);
		string s;
		while(linestream >> s) cpuutil_info.push_back(s);
	}
	stream.close();		
	return cpuutil_info; }

// TODO: Read and return the total number of processes
int LinuxParser::TotalProcesses() { 
	string line, s_temp, total_proc;
	std::istringstream linestream;
	std::ifstream stream(kProcDirectory + kStatFilename);
	if(stream.is_open()){
		while(getline(stream, line)){
			linestream.str(line);
			linestream >> s_temp;
			if(s_temp == "processes") {
				linestream >> total_proc;			
			}
		}
	}
	stream.close();
	return stoi(total_proc); }

// TODO: Read and return the number of running processes
int LinuxParser::RunningProcesses() { 
	string line, s_temp, running_proc;
	std::istringstream linestream;
	std::ifstream stream(kProcDirectory + kStatFilename);
	if(stream.is_open()){
		while(getline(stream, line)){
			linestream.str(line);
			linestream >> s_temp;
			if(s_temp == "procs_running") {
				linestream >> running_proc;			
			}
		}
	}
	stream.close();
	return stoi(running_proc); }

// TODO: Read and return the command associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Command(int pid) { 
	string line;
	std::ifstream stream(kProcDirectory + to_string(pid) + kCmdlineFilename);
	getline(stream, line);
	stream.close();
return line; }

// TODO: Read and return the memory used by a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Ram(int pid) { 
	string line, s_temp, ram;
	std::istringstream linestream;
	std::ifstream stream(kProcDirectory+to_string(pid)+kStatusFilename);
	if(stream.is_open()){
		while(getline(stream, line)){
			linestream.str(line);
			linestream >> s_temp;			
			if(s_temp == "VmSize:") {
				linestream >> ram; 
				break;
			}
		}	
	}
	stream.close();
return ram; }

// TODO: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Uid(int pid) { 
	string line, s_temp, uid;
	std::istringstream linestream;
	std::ifstream stream(kProcDirectory+to_string(pid)+kStatusFilename);
	if(stream.is_open()){
		while(getline(stream, line)){
			linestream.str(line);
			linestream >> s_temp;			
			if(s_temp == "Uid:") {
				linestream >> uid; 
				break;
			}
		}	
	}
	stream.close();
return uid; }

// TODO: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::User(int pid) { 
	string line, s_temp;
	string name, passwd, uid;
	std::istringstream linestream;
	std::ifstream stream(kPasswordPath);
	if(stream.is_open()){
		while(getline(stream, line)){
			replace(line.begin(), line.end(), ':', ' ');
			linestream.str(line);
			linestream >> name >> passwd >> uid;
			if(uid == LinuxParser::Uid(pid)) break;
		}
	}
	stream.close();
return name; }

// TODO: Read and return the uptime of a process
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::UpTime(int pid) { 
	string line, s_temp;
	std::istringstream linestream;
	std::ifstream stream(kProcDirectory +to_string(pid)+kStatFilename);
	if(stream.is_open()){	
		getline(stream, line);
		linestream.str(line);
		int count = 0;
		while(linestream >> s_temp) {
			++count;
			if(count == 22) break;	
		}
	}
	stream.close();
	return UpTime() - stoi(s_temp)/sysconf(_SC_CLK_TCK); }
