#include <iostream>
#include <vector>

using namespace std;

class Base{
public:
    Base(){
        cout << "Base object constructed" << endl;
    }

    virtual void print(){
        cout << "I am base function" << endl;
    }
};

class Derived: public Base{
public:
    Derived(){
        cout << "Derived object constructed" << endl;
    }

    virtual void print(){
        cout << "I am derived function" << endl;
    }
};

int main()
{
    Base b;
    Derived d;
    b.print();
    d.print();

    Base* vb;
    vb =  new Derived();
    vb->print();
    vb->Base::print();

    return 0;
}