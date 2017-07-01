#include<iostream>
using namespace std;

class Area
{

private:
	int len;
	int wid;

public:
	Area()
	{
		this->len = 0;
		this->wid = 0;
	}

	void setLength(int i)
	{
		this->len = i;
	}

	void setWidth(int j)
	{
		this->wid = j;
	}

	int getArea()
	{
		return (this->len * this->wid);
	}
	Area operator+ (Area obj)
	{
		Area res;
		res.len = obj.len + this->len;
		res.wid = obj.wid + this->wid;
		return res;
	}
};
int main()
{
	Area a1;
	a1.setLength(10);
	a1.setWidth(20);
	cout << "a1 : " << a1.getArea() << endl;
	
	Area a2;
	a2.setLength(20);
	a2.setWidth(30);
	cout << "a2 : " << a2.getArea() << endl;
	
	Area a3;
	
	a3 = a1 + a2;
	cout << "a3 : " << a3.getArea() << endl;

	return 0;
}