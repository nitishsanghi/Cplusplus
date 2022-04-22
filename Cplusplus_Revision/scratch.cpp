#include<iostream>
#include<sstream>
#include<memory>

using namespace std;


int main(int argc, char* argv[]){

	int n;
	cin >> n;
	const auto i = n;
	constexpr auto j = 3;
	cout << n << endl;
	cout << i << endl;
	cout << j << endl;
	return 0;
}