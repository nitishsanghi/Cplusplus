#include<iostream>


class MyClass{
	public:
		//int *num = (int*)malloc(sizeof(int)); Throws warning that non-static member is initialized
		int *num;
		MyClass(){
			num = (int*)malloc(sizeof(int));
		}
		~MyClass(){
			free(num);
		}
		void *operator new(size_t size){
			void *p = malloc(size);
			return p;
		}

		void *operator new(MyClass *p){
			void *q = p;
			return q;
		}
		void operator delete(void *p){
			free(p);
		}

};

int main(){

	MyClass mc;
	*mc.num = 45;
	std::cout << mc.num << std::endl;
	std::cout << *mc.num << std::endl;

	MyClass *mc1 = new MyClass();
	*mc1->num =40;
	std::cout <<  &mc1 <<" "<<mc1 <<" "<<*mc1->num << std::endl;

	MyClass *mc2 = new (mc) MyClass;
	*mc2->num =30;
	std::cout  <<  &mc2 <<" "<<mc2 <<" "<< *mc2->num << std::endl;

	std::cout << sizeof(mc2) << std::endl;
}