#include<iostream>
using namespace std;
namespace myNamespace
{
	double add(double number1, double number2)
	{
		return (number1 + number2);
	}
	double sub(double number1, double number2)
	{
		return (number1 + number2);
	}
	double mul(double number1, double number2)
	{
		return (number1 + number2);
	}
	double div(double number1, double number2)
	{
		if (number2 != 0)
			return (number1 / number2);
		else
			return -1;
	}
	double insertNumOperation(double number1, double number2, double (*fun)(double,double))
	{
		return (*fun)(number1,number2);
	}
}
//using namespace myNamespace;
int main()
{
	double number1 = 20, number2 = 30;
	
	cout << number1 << " + " << number2 << " = " << myNamespace::insertNumOperation(number1, number2, myNamespace::add) << endl;

	return 0;
}