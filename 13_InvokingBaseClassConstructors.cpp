#include<iostream>
using namespace std;

class ABC
{
public:
	int x;
	
	ABC()
	{
		x = 0;
	}
	ABC(int x)
	{
		this->x = x;
	}
};
class DEF : public ABC
{
	DEF(){}
	DEF(int x):ABC(x){}
	void fun()
	{
		cout << x << endl;
	}
};

int main()
{
	DEF *d  = new DEF(10);

	delete d;

	return 0;
}