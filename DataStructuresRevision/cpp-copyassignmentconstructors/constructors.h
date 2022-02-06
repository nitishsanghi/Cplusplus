#include<iostream>

class cube{
	public:
		cube(){
			length_ = 1;
			std::cout << "Default\n"; 
		}
		cube(int length){
			length_= length;
			std::cout << "Custom\n"; 
		}
		cube(const cube &obj){
			length_ = obj.length_;
			std::cout << "Copy\n"; 
		}
		cube & operator=(const cube &obj){
			length_ = obj.length_;
			std::cout << "Assignment\n"; 
			return *this;
		}

		int length_;

};