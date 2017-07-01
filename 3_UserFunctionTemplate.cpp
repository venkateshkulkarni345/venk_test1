#include<iostream>
using namespace std;

template<class T>
T add(T a, T b)
{
	return (a + b);
}

template<class T, class U>
class MyClassTemplate
{

private:
	T a;
	U b;

public:	
	MyClassTemplate()
	{
		a = (T)0;
		b = (U)0;
	}
	
	MyClassTemplate(T a, U b)
	{
		this->a = a;
		this->b = b;
	}
	void getFunction()
	{
		cout << "a = " << this->a << " and  b = " << this->b << endl;
	}
};

int main()
{
	double a = 10.12;
	int b = 20;

	cout  << a << " + " << b << " = " << add<double>(a,(double)b)<< endl;
	
	MyClassTemplate<double, int> myObj(a,b);
	myObj.getFunction();

		return 0;
}