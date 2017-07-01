#include<iostream>
#include<exception>
using namespace std;

double divd(double num1, double num2)throw(runtime_error)
{
	if (num2 == 0.0)
		//throw -9;
		throw runtime_error("div by zero 123");
	else
		return (num1/num2);
}

int main()
{
	double m = 0;
	try{
		m = divd(10,0.0);
	}
	catch (runtime_error &ex_error)
	{
		cout << "Exception : " << ex_error.what() << endl;
	}
	/*catch(int k)
	{
		cout<<"div by zero error"<<endl;
	}*/
	catch(const char *str)
	{
		cout<<str<<endl;
	}
	catch(...)
	{
		cout<<"div by zero error"<<endl;
	}
	return 0;
}