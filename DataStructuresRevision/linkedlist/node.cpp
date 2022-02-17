#include<iostream>

using namespace std;


struct node{ 
	// struct member variables and functions by default are public
		int data;
		node *next;
};


int main(){

	node *temp1 = new node;
	temp1->data = 10;
	temp1->next = new node;

	cout << temp1 << endl << &temp1 << endl << temp1->next << endl;
	cout << temp1->data << endl;

	node temp2;
	temp2.data = 8;
	temp2.next = temp1;

	cout << &temp2 << endl << temp2.next << endl << &temp2.next << endl;
	cout << temp2.data << endl << temp2.next->data << endl;


}