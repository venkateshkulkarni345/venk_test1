#include<iostream>
using namespace std;

class ABC
{
	int len;
	int wid;
public:
	ABC()
	{
		this->len = 0;
		this->wid = 0;
	}
	ABC(int i)
	{
		this->len = i;
		this->wid = i;
	}
	ABC(int i, int j)
	{
		this->len = i;
		this->wid = j;
	}
	int getArea()
	{
		return (this->len * this->wid);
	}
	friend void printArea( ABC *obj)
	{
		cout << "len : " <<obj->len << endl;
		cout << "wid : " << obj->wid << endl;
	}

};


class B;

class A
{
	int x;
public:
	A()
	{
		this->x = 0;
	}
	A(int i)
	{
		this->x = i;
	}
	friend class B;
};

class B
{
public:
	void fun(A obj)
	{
		cout << "Object of A : " <<obj.x << endl;
	}
};

int main()
{
	// for friend function
	ABC b(10,20);
	printArea(&b);

	// for friend class
	A a(10);
	B b1;
	b1.fun(a);

	return 0;
}