#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str("Hello world");
	string::iterator it;
	string::reverse_iterator rit;
	for (it = str.begin(); it != str.end(); ++it)
	{
		cout << *it <<endl;
	}


	for (rit = str.rbegin(); rit != str.rend(); ++rit)
	{
		cout << *rit << endl;
	}


	return 0;
}