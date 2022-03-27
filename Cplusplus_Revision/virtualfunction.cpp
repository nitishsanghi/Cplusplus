#include<iostream>

class Base{
	public:
		Base(std::string s): s_(s){};

		void print(){
			std::cout << "String is : " << s_ << std::endl;
		}

	private:
		std::string s_;
};

class Inherit: public Base{
	public:
		Inherit(bool b, std::string s): Base(s), b_(false){};
		void print(){
			std::cout << "Boolean is :" << b_ << std::endl;
		}

	private:
		bool b_;		

};

class Foo
{
public:
    int m_x {};
    int m_y {};
};

int main()
{
    Foo foo { 6, 7 }; // list-initialization

    return 0;
}


