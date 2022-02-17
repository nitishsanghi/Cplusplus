#include<iostream>
#include "linkedlist.h"
#include "node.h"

using namespace std;

int main(){

	linkedlist l;
	cout << l.head->data << endl;
	cout << &l.head << endl << l.head << endl; 
	l.head->data = 10;
	cout << l.head->data << endl;
	cout << &l.head << endl << l.head << endl; 

	l.addnode(35);
	cout << l.head->data << endl << l.head->next->data << endl;
	cout << &l.head << endl << &l.head->next << endl;
	cout << l.head << endl << l.head->next << endl;
	return 0;
}