#include<iostream>
#include<exception>
using namespace std;

double div(double a, double b)
{
	if (b == 0)
	{
		throw runtime_error("divide by error");
		//throw 10.01;
		//throw "Divide by zero error";
    }
	else
		return (a / b);
}
int main()
{
	double a = 12.12;
	double c= 0.0,b = 0.0;
	
	try
	{
		c = div(a,b);
		
	}
	catch (const char *err_msg)
	{
		cout << "Exception :" << err_msg << endl;
	}
	catch (int err_msg)
	{
		cout << "Exception number :" << err_msg << endl;
	}
	catch (runtime_error &ex)
	{
		cout << "Exception :" << ex.what() << endl;
	}
	catch (...)
	{
		cout << "divide by zero error" << endl;
	}

	return 0;
}