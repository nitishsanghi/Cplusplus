#include<iostream>
#include<sstream>
#include<memory>

using namespace std;

void test(int arr[]){
	cout << "worked : " << sizeof(arr) << endl;
}


int main(int argc, char* argv[]){

	int z[5]{3,4};
	int * x = new int;
	*x = 5;
	int y = 0;
	cout << sizeof(z) << endl;
	cout << size(z) << endl;
	cout << sizeof(x) << endl;
	cout << *(&z[0]+1) << endl;
	cout << z << endl;
	cout << x << endl;
	cout << &y << endl;
	test(z);
	return 0;
}