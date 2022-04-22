#include <iostream>
#include <string>

using namespace std;


string& operator+(string& s1, string& s2){
	cout << "I am working" << endl;
	s1 = s1.append(s2.append(s1));
	return s1;
}

class MyDate{
private:
	int date{};
public:
	MyDate(){}
	MyDate(int d) : date{d}{}

	MyDate& operator++(int){
		date++;
		return *this;
	}

	void print(){
		cout << date << endl;
	}
};

int main(){
	string s1{"Hello"}, s2{"World"};
	cout << s1 + s2 << endl;


	MyDate md;
	md.print();
	md++;
	md.print();
	return 0;
}