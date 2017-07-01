#include<iostream>
using namespace std;

template<class T,int nSize>
class ABC
{
public:
	T *k;

	ABC()
	{
		k = NULL;
	}
	ABC(int nSize)
	{
		//k = (T*) malloc( sizeof(T) * nSize);
		k = new T[nSize];
	}
	~ABC()
	{
		delete[] k;
		//free(k);
	}
	void setArrayValues()
	{
		T i;
		for (i = 0; i < 10; i++)
			k[i] = i;
	}
	void printArrayValues()
	{
		T i;
		for (i = 0; i < 10; i++)
		cout << k[i] << endl;
	}
};

int main()
{
	ABC<int,10> a1;

	//a1.setArrayValues();
	//a1.printArrayValues();

	int *p = NULL;

	p = (int*)malloc(sizeof(int) * 10);
	free(p);

	p = new int[10];
	delete[] p;

	return 0;
}