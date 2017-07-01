#include<iostream>
using namespace std;

template<class T>
T add(T a, T b)
{
	return (a + b);
}


int main()
{
	cout << add<int>(10, 20);
	return 0;
}