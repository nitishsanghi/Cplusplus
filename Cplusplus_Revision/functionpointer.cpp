#include<iostream>

using namespace std;

void my_int(string s){
	cout << s << endl;
}

int main(){
	void (*foo)(string);
	foo = &my_int;
	foo("shkldsahfl");
	return 0;

}