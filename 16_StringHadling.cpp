#include<iostream>
#include<string>
using namespace std;

int main()
{

	char z[] = { 's', 't', 'a', 'r', 'r', '\n' };
	char *res = NULL;
	int i = 0, j = 0, lenOfArray = 0;
	
	lenOfArray = ( sizeof(z) / sizeof(char) ) ;
	res = (char*)malloc(sizeof(char)*lenOfArray);
	if (res == NULL)
	{
		cerr << "Bad Memory allocation in Heap";
	}

	for (i = lenOfArray -2 ; i >= 0; i--)
	{
		res[j++] = z[i];
	}

	res[j] = '\n';


	//cout << "Char Array : " << z << "Char Array Reverse" << res<< endl;

	for (i = 0; i <= lenOfArray; i++)
	{
		cout << z[i] << '\t';
	}
	cout << endl;

	for (i = 0; i <= lenOfArray; i++)
	{
		cout << res[i] << '\t';
	}

	string str1(z,lenOfArray);
	string str2(res,lenOfArray);

	cout << str1 << endl;
	cout << str2 << endl;

	return 0;
}