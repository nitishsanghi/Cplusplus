#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

class linkedlist{

	public:
		node *head;

	linkedlist(int value){
		head = new node(value);
	}

	linkedlist(){
		head = new node();
	}

	void addnode(int val){
		node *temp =  new node(val);
		temp->next = head;
		head = temp;
	}
};


#endif