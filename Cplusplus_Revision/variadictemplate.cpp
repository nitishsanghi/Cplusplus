// just some interfaces, the specifics are not relevant

#include <string>
#include <iostream>

class A
{
public:
    virtual int foo(int x) const = 0;
};

class B
{
public:
    virtual float bar(float a, float b) const = 0;
};

class C
{
public:
    virtual std::string baz() const = 0;
};

class InstanceOfAll : public A, B, C
{
public:
    // ...
    virtual int foo(int x) const {std::cout << "Instance All" << std::endl;return 0;};
    virtual float bar(float a, float b) const {std::cout << "Instance B" << std::endl;return 0.0;};
    virtual std::string baz() const {std::cout << "Instance C" << std::endl;return "C is here";};
};

class InstanceOfA : public A
{
public:
    // ...
    virtual int foo(int x) const {std::cout << "Instance A" << std::endl;return 0;};
};

class InstanceOfB : public B
{
public:
    // ...
    virtual float bar(float a, float b) const {std::cout << "Instance B" << std::endl;return 0.0;};
};

class InstanceOfC : public C
{
public:
    // ...
    virtual std::string baz() const {std::cout << "Instance C" << std::endl;return "C is here";};
};

int some_function_a(const A* a)
{   std::cout << "In somefunciton a" << std::endl;
    int x = a->foo(42);
    return x;
}

float some_function_b(const B* b)
{   std::cout << "In somefunction b" << std::endl;
     float x = b->bar(1.0, 2.0);
    return x;
}



// conversion operator
/*struct X
{
    int data;

    operator std::string() const
    {
        return std::to_string(data);
    }

    // operator T*() [const]
};

struct X
{
    int a;
    float b;
    std::string c;
};
std::tuple<int, float, std::string>;*/

//template <class A, class B, class C>
template <class... Interfaces>
class Any
{
    public:
        Any(Interfaces&... interfaces) : m_interfaces(&interfaces...){
            std::cout << std::tuple_size<decltype(m_interfaces)>::value << std::endl;
        }


        template <class T>
        operator T*() const{
            return T*();
        }

        /*operator A*() const {
           return m_a; 
        }*/
    
    
    private:
        std::tuple<Interfaces*...> m_interfaces;

    // std::tuple<A*, B*, C*>;
    // std::tuple<Interfaces*...>;
};
template <class ...Interfaces>
int other_function(const Any<Interfaces...>& any)
{
    // .. some thing using A, B and C
 
    std::cout << "Other function " << std::endl;
    // can be converted to an A*
    some_function_a(any);

    // can be converted to a B*
    some_function_b(any);

    //const C* p_c = any; // can be converted to a C*
    //std::string s = p_c->baz();
    return 0;
}


int main()
{
    //InstanceOfAll i;
    //int x = other_function(i);

    InstanceOfA a;
    InstanceOfB b;
    InstanceOfC c;
    Any p = Any(a,b,c,a,b);
    int y = other_function(Any(a, b, c));
}
