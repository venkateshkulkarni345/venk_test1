#include<iostream>
#include<exception>
#include<stdexcept>
using namespace std;

double div(double a, double b) throw(int, const char *, runtime_error)
{
	if (b == 0)
		throw runtime_error("Runtime exception : Divide by zero");
	else
	    return (a / b);
}

int main()
{
	double a = 10.12;
	double b = 0.0;
	double c = 0.0;
	
	try
	{
		c = div(a, b);
	}
	catch(int x)
	{
		cout << "Exception : " << x << endl;
	}
	catch (const char *msg)
	{
		cout << "Exception : " << msg << endl;
	}
	catch (runtime_error &ex_error)
	{
		cout << "Exception : " << ex_error.what() << endl;
	}
	catch (...)
	{
		cout << "Default Exception : divide by zero" << endl;
	}

	return 0;
}