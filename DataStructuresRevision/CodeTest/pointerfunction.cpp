#include<iostream>

int *sum(int a, int b){
	int *c = new int;
		*c = a + b;
	return c;
}

using std::cout;

int main(){

	int *summed = sum(2, 4);

	cout << summed << std::endl;
	cout << &summed << std::endl;
	cout << *summed << std::endl;
	cout << *sum(2,4) << std::endl;


	return 0;
}