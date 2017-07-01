#include<iostream>
using namespace std;

class A{
private:
	int *p;
	int size;
public:
	A(){
		this->p = NULL;
		this->size = 0;
	}

	A(int size){
		this->size = size;
		this->p = new int[this->size];
	}

	A(A &obj){
		this->size = obj.size;
		this->p = new int[this->size];
		for(int i = 0;i<this->size;i++)
			this->p[i] = obj.p[i];
	}

	void setValue(){
		for(int i = 0;i<this->size;i++)
			this->p[i] = i;
	}

	void getValue(){
		for(int i = 0;i<this->size;i++)
			cout << &this->p[i] << "+" <<this->p[i] << endl;
	}

	~A(){
		delete [] p;
	}

};

int main()
{
	A a1(10);
	a1.setValue();
	a1.getValue();

	A a2(a1);
	a2.setValue();
	a2.getValue();

	return 0;
}