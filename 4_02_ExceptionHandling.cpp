#include<iostream>
#include<exception>
#include<stdexcept>
using namespace std;

class DivOperationException : public exception{
public:
	const char* what()
	{
		return "Divide by zero" ;
	}
};

double div(double a, double b)
{
	if (b == 0)
		throw DivOperationException();
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
	catch (DivOperationException &ex_error)
	{
		cout << "Exception : " << ex_error.what() << endl;
	}

	return 0;
}