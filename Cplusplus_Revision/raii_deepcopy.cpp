#include<iostream>

using namespace std;

class MyClass{
	private:
		int *_myInt;

	public:
		MyClass(){
			_myInt = (int*)malloc(sizeof(int));
			*_myInt = 0;
		}

		MyClass(int val){
			_myInt = (int*)malloc(sizeof(int));
			*_myInt = val;
		}
		~MyClass(){
			free(_myInt);
		}

		MyClass(MyClass &source){
			_myInt = (int*)malloc(sizeof(int));
			*_myInt = *source._myInt;
		}

		MyClass& operator=(MyClass &source){
			_myInt = (int*)malloc(sizeof(int));
			*_myInt = *source._myInt;
			return *this;
		}

		void printAddressMemory(){
			cout << this << endl << _myInt << endl;
			cout << *_myInt << endl;
		}

};


int main(){

	MyClass myclass1(8346);
	myclass1.printAddressMemory();

	MyClass myclass2(myclass1);
	myclass2.printAddressMemory();

	MyClass myclass3;
	myclass3 = myclass2;
	myclass3.printAddressMemory();

	myclass1.printAddressMemory();
	myclass2.printAddressMemory();

	int a = 1;
    int b = a;
    a = 2;
    
    cout << a << endl << b << endl;
    cout << &a << endl << &b << endl;
	
}

