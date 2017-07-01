#include<iostream>
using namespace std;

class ABC
{
public:
	int x;
	static int y;
public:
	ABC()
	{
		x = 0;
	}

	ABC(int i,int j)
	{
		x = i;
		y = j;
	}

	void fun()
	{
		cout << "hello world" << endl;
	}

	// this cannot be made as virtual function
	static void staticFun()
	{
		cout << "Static function called : " << ABC::y << endl;
	}

};

//1. Only one copy of the the static data and shared 
//between all the objects of the same class

//2. this is the way the static data member can be intialized 
//but the member function is called in the main function

//3> for more examples: http://www.learncpp.com/cpp-tutorial/811-static-member-variables/

/**************************************************/
int ABC::y = 100;
/**************************************************/

int main()
{

	
	// Call the function wothout creating any instance of the class
	/**************************************************/
	ABC::staticFun();
	/**************************************************/

	// static member data can be modified as mentioned 
	//below but not the const data member of the class
	
	ABC a1(10,20);
	a1.fun();
	a1.staticFun();

	
	return 0;
}