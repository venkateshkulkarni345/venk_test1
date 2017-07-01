/*There are 3 important places where a copy constructor is called.
When an object is created from another object of the same type
When an object is passed by value as a parameter to a function
When an object is returned from a function*/

#include<iostream>
using namespace std;

class ABC
{
	int x;
	int y;

public:
	ABC()
	{
		this->x  = 0;
		this->y =  0;
	}
	ABC(int i)
	{
		this->x = i;
		this->y = i;
	}
	ABC(int i, int j)
	{
		this->x = i;
		this->y = j;
	}
	ABC(ABC *obj)
	{
		this->x = obj->x;
		this->y = obj->y;
	}
	void func()
	{
		cout << this->x << " and " << this->y << endl;
	}
};

int main()
{
	ABC *a1 = new ABC(10,20);
	a1->func();

	ABC a2(a1);
	a2.func();

	ABC a3 = a2;
	a3.func();

	delete a1;

	return 0;
}
