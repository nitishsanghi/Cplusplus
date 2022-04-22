#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> V;

int main(){

	V abc{1,2,3,4,5,6,7};
	V::const_iterator it;
	for(it = abc.cbegin(); it!=abc.cend(); ++it){
		*it = *it + 1;
		cout << *it << endl;

	}
	return 0;
}