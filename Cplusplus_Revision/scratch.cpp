#include<iostream>
#include<sstream>
#include<memory>

using namespace std;

typedef
unique_ptr<pair<string, string> > UPtrPSS;


//using UPtrPSS = unique_ptr<pair<string, string> >; //alias declaration

enum color {red, blue, green};

bool islucky(int a){
	if(a>0)
		return true;
}

bool islucky(char) = delete;
bool islucky(double) = delete;

int main(int argc, char* argv[]){
	/*cout << "# of arguments : " << argc << endl;
	for(int i = 0; i < argc; i++)
		cout << argv[i] << endl;*/
	//auto red = false;
	if(islucky(2))
		cout << "True" << endl;
	if(islucky('a'))
		cout << "FALSE" << endl;
	stringstream s;
	ostringstream so;
	istringstream si("input string stream");
	s <<"jdsk dlfjslkd d fldjs ljld fs";
	so << "output string stream";
	cout << so.str() << endl;
	string word;
	UPtrPSS abc;
	while(si>>word)
		cout << word;


	return 0;
}