#include <iostream>

using namespace std;

int main(){
	int n = 921;
	int s = n + 15;
	cout << s - s%16 << endl;
	return 0;
}