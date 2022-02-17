#ifndef NODE_H
#define NODE_H

struct node{ 
	// struct member variables and functions by default are public
		int data;
		node *next;
		
		node(){
			data = 0;
			next = nullptr;
		}

		node(int val){
			data = val;
			next = nullptr;
		}

		node(int val, node *n){
			data = val;
			next = n;
		}
};

#endif