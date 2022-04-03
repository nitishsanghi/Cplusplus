#include<iostream>
#include<sstream>
#include<memory>

using namespace std;

using length = int;

typedef int breadth;

int main(int argc, char* argv[]){

	length a = 1;
	const breadth& b{a};
	a = 2;
	const int* c = &a;
	c = nullptr;
	return 0;
}