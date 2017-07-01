#include<iostream>
using namespace std;

class Abc
{
public:
	int i;

	Abc()
	{
		i = 0;
	}
	Abc(int i)
	{
		this->i = i;
	}

	int getVariableI()
	{
		return this->i;
	}
	void setVariableI(int i)
	{
		this->i = i;
	}
public:
	void fun1(Abc obj){
		cout << "Call by Value " << obj.i << endl;
	}
	void fun2(Abc *obj){
		cout << "Call by Reference " << obj->i << endl;
	}
};
int main()
{

	Abc *a1 = new Abc(10);
	a1->fun1(*a1);
	a1->fun2(a1);

	// 
	Abc a2;
	a2.setVariableI(10);
	a2.fun1(a2);
	a2.fun2(&a2);


	return 0;
}