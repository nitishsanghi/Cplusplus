#include<iostream>
#include<utility>

using namespace std;

int main(){

	
	// std::pair container
	pair<int,int> p1(1,2);
	pair<double,int> p2(3.2,4);
	pair<int,int> p3(32,53);
	cout << "p1 :" << p1.first << " " << p1.second << endl;
	cout << "p2 :" << p2.first << " " << p2.second << endl;
	cout << "p3 :" << p3.first << " " << p3.second << endl;

	p1.swap(p3);

	cout << "p1 :" << p1.first << " " << p1.second << endl;
	cout << "p2 :" << p2.first << " " << p2.second << endl;
	cout << "p3 :" << p3.first << " " << p3.second << endl;

	auto p4 = std::make_pair(p1,p2);
	cout << "p4 :" << p4.first.first << " " << p4.second.second << endl;

	cout << get<0>(p1) << endl;

	if(p1 == p3)
		cout << "Made +ve comparison" << endl;
	else
		cout << "Made negative comparison " << endl;

	int a,b;
	tie(a,b) = p1;
	cout << a << " " << b << endl;

	// std::tuple
	tuple<int,int,int> t1(1,2,3);
	tuple<double,int,string> t2(3.2,4,"adfda");
	tuple<int,int,int> t3(32,53,12);
	cout << "t1 :" << get<0>(t1) << " " << get<1>(t1) << " " << get<2>(t1) << endl;
	cout << "t2 :" << get<0>(t2) << " " << get<1>(t2) << " " << get<2>(t2) << endl;

	t1.swap(t3);

	cout << "t1 :" << get<0>(t1) << " " << get<1>(t1) << " " << get<2>(t1) << endl;

	auto t4 = std::make_tuple(t1,t2,9373);

	if(t1 == t3)
		cout << "Made +ve comparison" << endl;
	else
		cout << "Made negative comparison " << endl;

	tie(a,b, ignore) = t1;
	cout << a << " " << b << endl;



}