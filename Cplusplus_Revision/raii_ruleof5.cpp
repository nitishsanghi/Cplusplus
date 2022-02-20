#include<iostream>

using namespace std;


class MyClass{
	public:
		MyClass(){
			cout << "Creating class object uninitiated and no memory allocation " << endl; 
			cout << endl;
		}

		MyClass(size_t size){
			size_ = size;
			data_ = new int[size_];
			cout << "Creating class object of data size : " << size_*sizeof(int) << endl; 
			cout << endl;
		}


		MyClass createObject(int val);

		MyClass(const MyClass& source){
			size_ = source.size_;
			data_ = new int[size_];
			*data_ = *source.data_;
			cout << "Copy constructing class object of data size : " << size_*sizeof(int) << endl; 
			//cout << "Data address copy and data address source : " << data_ << endl << source.data_ << endl;
			cout << endl;
		}

		MyClass& operator=(const MyClass & source){
			if(this == &source){
				return *this;
			}
			size_ = source.size_;
			data_ = new int[size_];
			*data_ = *source.data_;
			cout << "Copy assignment constructing class object of data size : " << size_*sizeof(int) << endl; 
			cout << endl;
			//cout << "Data address copy and data address source : " << data_ << endl << source.data_ << endl;
			return *this;

		}

		MyClass(MyClass&& source){

			data_ = source.data_;
			size_ = source.size_;
			source.data_ = nullptr;
			source.size_ = 0;
			cout << "Move constructing class object of data size : " << size_*sizeof(int) << endl; 
			cout << endl;
		}

		MyClass& operator=(MyClass&& source){

			if(this == &source){
				return *this;
			}
			delete[] data_;

			data_ = source.data_;
			size_ = source.size_;
			source.data_ = nullptr;
			source.size_ = 0;
			cout << "Move assignment constructing class object of data size : " << size_*sizeof(int) << endl; 
			cout << endl;
			return *this;
		}

		~MyClass(){
			delete[] data_;
			cout << " Deleted object : " << this << endl;
			cout << endl;
		}


	private:
		int size_;
		int * data_;


};


int main(){

	MyClass mc(4);
	MyClass mc1;
	MyClass mc2(mc);
	MyClass mc3 = mc2;
	MyClass mc4;
	mc4 = mc2;
	MyClass mc5(move(mc));
	mc4 = move(mc3);
	MyClass mc6(10);
	mc6 = MyClass(100);
	MyClass mc7(MyClass(200));


	return 0;
}