#include<iostream>

using namespace std;

class MyClass{
	private:
		int *_myInt;
		static int counter;

	public:


		MyClass(int val){
			_myInt = (int*)malloc(sizeof(int));
			*_myInt = val;
			counter++;
		}
		~MyClass(){
			free(_myInt);
			counter--;
			cout << "Counter : " << counter << endl;
		}

		MyClass(MyClass &source){
			_myInt = (int*)malloc(sizeof(int));
			*_myInt = *source._myInt;
			counter++;
		}

		MyClass& operator=(MyClass &source){
			_myInt = (int*)malloc(sizeof(int));
			*_myInt = *source._myInt;
			counter++;
			return *this;
		}

		void printAddressMemory(){
			cout << "Counter : " << counter << endl;
			cout << this << endl << _myInt << endl;
			cout << *_myInt << endl;
		}

};

int MyClass::counter = 0;


int main(){

	MyClass myclass1(8346);
	myclass1.printAddressMemory();

	MyClass myclass2(myclass1);
	myclass2.printAddressMemory();

	MyClass myclass3 = myclass2;
	myclass3.printAddressMemory();

	myclass1.printAddressMemory();
	myclass2.printAddressMemory();

	int a = 1;
    int b = a;
    a = 2;
    
    cout << a << endl << b << endl;
    cout << &a << endl << &b << endl;
	
}

