#include<iostream>

// For code in C using malloc() or calloc() one of the two header files 
// below need to be added. Not required for C++ coding.
//#include<stdlib.h> 
//#include<malloc.h>


using namespace std;

struct Mystruct
{ 
	int n;
	char c[4];
	float f;
	double d;
	
};

int main(){

	int *p = (int*)malloc(3*sizeof(int));
	p[0] = 1;
	p[1] = 2;
	p[2] = 3;
	cout << &p << endl << &p[0] << endl << &p[1] << endl << &p[2] << endl;
	cout << p[0] << endl << p[1] << endl << p[2] << endl;

	Mystruct *q = (Mystruct*)malloc(sizeof(Mystruct));
	Mystruct *r = (Mystruct*)calloc(4, sizeof(Mystruct));

	cout << &q << endl << &q[0] << endl << &q[1] << endl << &q[2] << endl;
	cout << q[0].n << endl;

	p = (int*)realloc(p, 5*sizeof(int));
	free(p);
	free(q);
	free(r);

	return 0;
}