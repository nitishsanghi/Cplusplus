#include <iostream>

class A
{
public:
    A(int a)
    {
        std::cout << "A: " << a << '\n';
    }
    void printA(){
    	std::cout << "A member function" << std::endl;
    }
};

class B: public A
{
public:
    B(int a, double b)
    : A{ a }
    {
        std::cout << "B: " << b << '\n';
    }
    void printB(){
    	std::cout << "B member function" << std::endl;
    }
};

class C: public B
{
public:
    C(int a , double b , char c)
    : B{ a, b }
    {
        std::cout << "C: " << c << '\n';
    }
    void printC(){
    	std::cout << "C member function" << std::endl;
    }
};

int main()
{
    C c{ 5, 4.3, 'R' };

    return 0;
}


