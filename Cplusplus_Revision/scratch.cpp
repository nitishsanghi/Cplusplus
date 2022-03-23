#include<iostream>
#include<sstream>

using namespace std;

int main(int argc, char* argv[]){
	/*cout << "# of arguments : " << argc << endl;
	for(int i = 0; i < argc; i++)
		cout << argv[i] << endl;*/

	stringstream s;
	ostringstream so;
	istringstream si("input string stream");
	s <<"jdsk dlfjslkd d fldjs ljld fs";
	so << "output string stream";
	cout << so.str() << endl;
	string word;
	while(si>>word)
		cout << word;


	return 0;
}