#include<iostream>
using namespace std;

double add(double number1, double number2)
{
	return (number1 + number2);
}

double sub(double number1, double number2)
{
	return (number1 + number2);
}
double operationFunction(double number1, double number2, double (*fun)(double, double))
{
	return ((*fun)(number1, number2));
}

int main()
{
	double number1 = 10, number2 = 20;

	//first type of creating function pointers
	cout << number1 << " + " << number2 << " = " <<operationFunction(number1,number2,add) << endl;
	
	//second type of creating function pointers
	double(*fpFun)(double, double);
	fpFun = &add;
	cout << number1 << " + " << number2 << " = " << fpFun(number1, number2) << endl;
	
	return 0;
}