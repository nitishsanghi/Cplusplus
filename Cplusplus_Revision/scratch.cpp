#include<iostream>
#include<sstream>
#include<memory>

using namespace std;

void test(int arr[]){
	cout << "worked : " << sizeof(arr) << endl;
}


class myclass{
public:
	int* x;
	int y{};
	myclass(){
		x = new int(10);
		cout << "Test Class" << endl;
		cout << y << endl;
		cout << *x << endl;
	}
	~myclass(){
		delete x;
	}
};

class base{
public:
	void virtual show(){

		cout << "I am parent class" << endl;
	}
};

class child: public base{
public:
	void show(){
		cout << "I am child class" << endl;
	}

};

int main(int argc, char* argv[]){

	/*int z[5]{3,4};
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

	{
		int w = 10;
		cout << w << endl;
	}
	{
	myclass mc;
	//mc.~myclass();
	}
	myclass mc;
	myclass mc1();
	myclass mc2[5];
	cout << "point x in mc has value : " << *mc.x << endl;
	for(auto e : mc2)
		cout << *e.x << endl;*/

	child c;
	base * base_ptr = new child;
	base_ptr->show();

	return 0;
}