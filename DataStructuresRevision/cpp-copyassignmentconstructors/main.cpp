#include<iostream>
 

 class Pair {
 public:
   int *pa,*pb;
   Pair(int, int);
   Pair(const Pair &);
   Pair(): Pair(0,0){}
  ~Pair();
 };

 
 Pair::Pair(int a, int b){
   pa = new int;
   *pa = a;
   pb = new int;
   *pb = b;
   std::cout << "custom constructor\n";
 }


 Pair::Pair(const Pair & p){
   pa = new int(*p.pa);
   pb = new int(*p.pb);
   std::cout << "copy constructor\n";
 }
 
 Pair::~Pair(){
   delete pa;
   delete pb;
   std::cout << "destructor\n";
 }
 
 /* Here is a main() function you can use
  * to check your implementation of the
  * class Pair member functions.
  */
  
int main() {
  Pair p(15,16);
  Pair q(p);
  Pair *hp = new Pair(23,42);
  delete hp;
  
  std::cout << "If this message is printed,"
    << " at least the program hasn't crashed yet!\n"
    << "But you may want to print other diagnostic messages too." << std::endl;
  return 0;
}