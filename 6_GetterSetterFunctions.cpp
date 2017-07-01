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
};

int main()
{

	Abc a2;
	a2.setVariableI(10);

	cout << a2.getVariableI() << endl;


	return 0;
}