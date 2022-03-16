#include<iostream>
#include<memory>

using namespace std;
class myClass{
	public:
		int a;
		void print(){
			cout << "value is : " << a << endl;
		}
};

int main(){

	unique_ptr<int> p(new int(2));
	cout<< *p << endl;
	*p = 8493;
	cout<< *p << endl;

	unique_ptr<myClass> mc(new myClass);
	mc->a = p;
	mc->print();
	cout << mc.get() << endl;
	unique_ptr<myClass> mc1(new myClass);
	*mc1 = *mc;
	cout << mc.get() << endl;
}