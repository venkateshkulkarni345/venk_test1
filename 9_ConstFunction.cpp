#include<iostream>
using namespace std;

class ABC
{
public:
	//int i;
	mutable int i;

public:
	ABC()
	{
		this->i = 0;
	}
	ABC(int i)
	{
		this->i = i;
	}
	void func() const
	{
		cout << this->i << endl;
	
		// can modify the non constant vairable inside the const function
		// only if we make the variable mutable
		this->i = this->i + 1;
		cout << this->i << endl;
	}
};

int main()
{
	//constructor over loading with no input argument
	ABC a1;
	a1.func();

	//constructor over loading with one input argument
	ABC a2(10);
	a2.func();

	return 0;
}