#include<iostream>
using namespace std;

#define MULERROR(X) ( X * 10)
#define MULCORRECT(X) ( (X) * 10)

//1. Use of inline function : repetative use of the small block of code can be consider as an Inline function

//2. Will increase the performance(runs faster but utilizes the memory for placing the code  for every call at the compilation):
// no need of stack call for the function declared as inline 

inline double add(double x, double y)
{
	return (x + y);
}

int main()
{
	// 2+(5*10) = 52 -->wrong
	cout <<  MULERROR(2 + 5)   <<  endl;

	// (2+5)10 = 70 --> correct
	cout <<  MULCORRECT(2 + 5) <<  endl;
	
	//inline call
	cout << add(10, 10) << endl;

	/*Memory creation and deletion using new and delete*/
	/******************************************************************/
	int *ptr = NULL;
	ptr = new int[10];
	if (ptr == NULL)
		cout << "Bad dynamic mem allocation" << endl;
	
	delete[] ptr;
	/******************************************************************/

	/*Memory creation and deletion using malloc and free*/
	/******************************************************************/
	int *ptr1 = NULL;
	ptr1 = (int *)malloc( sizeof(int)*10);
	if (ptr1 == NULL)
		cout << "Bad dynamic mem allocation" << endl;

	free(ptr1);
	/******************************************************************/

	return 0;
}

