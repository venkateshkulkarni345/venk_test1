#include<iostream>
using namespace std;

class A{
private:
	int *p;
	int size;
public:
	A(){
		this->p = NULL;
		this->size = 0;
	}

	A(int size){
		this->size = size;
		this->p = new int[this->size];
	}

	A(A &obj){
		this->size = obj.size;
		this->p = new int[this->size];
		for(int i = 0;i<this->size;i++)
			this->p[i] = obj.p[i];
	}

	void setValue(){
		for(int i = 0;i<this->size;i++)
			this->p[i] = i;
	}

	void getValue(){
		for(int i = 0;i<this->size;i++)
			cout << &this->p[i] << "+" <<this->p[i] << endl;
	}

	~A(){
		delete [] p;
	}

};

int main()
{
	A a1(10);
	a1.setValue();
	a1.getValue();

	A a2(a1);
	a2.setValue();
	a2.getValue();

	return 0;
}#include<iostream>
using namespace std;

class StringManupulate
{
private:
	char *str;
	int t_size;

public:
	StringManupulate(){
		this->str = NULL;
		this->t_size = 0;
	}

	StringManupulate(char *str){
		this->t_size = getStringLength(str);
		this->str = new char[this->t_size + 100];
		this->copyString(str);
	}

	int getStringLength(char *str){
		int len = 0;
		while(*(str++) != '\0')
			len++;
		return len;
	}
	void copyString(char *str){
		int len = getStringLength(str);
		int idx = 0;
		while(len--)
			this->str[idx++]= *str++;

		this->str[idx] = '\0';
	}
	void display(){
		cout<<this->str<<endl;
	}

	void reverseString(){
		int endIdx = getStringLength(this->str);
		int startIdx = 0;
		for(endIdx,startIdx;endIdx != 0;endIdx--,startIdx++)
			this->str[startIdx] = this->str[endIdx];

	}

	void concatinateString(char *str1){
		int len = getStringLength(this->str) + getStringLength(str1);
		int startIdx = getStringLength(this->str);
		for(startIdx;startIdx < len ;startIdx++)
			this->str[startIdx] = *str1++;

		this->str[startIdx] = '\0';
	}
};

int main()
{
	StringManupulate str1("Hello");
	str1.display();
	
	str1.reverseString();
	str1.display();	

	str1.concatinateString("World");
	str1.display();	
	return 0;
}#include<iostream>
using namespace std;

template <class T>
T add(T a , T b){
	return (a+b);
}
namespace nArray{
template <class V,int nMax>
class Array{
private:
	V *nArray;
public:
	Array(){
		nArray = new V[nMax];
	}
	~Array(){
		delete [] nArray;
	}
	void setArray(){
		for(int i = 0;i<nMax;i++)
			nArray[i] = (V)i/2;
	}
	void getArray(){
		for(int i = 0;i<nMax;i++)
			cout<<nArray[i]<<endl;
	}
};
}

int main()
{
	cout<<add<int>(10,20)<<endl;
	cout<<add<float>(10.0,20.0)<<endl;

	nArray::Array<int,10> nAry;
	nAry.setArray();
	nAry.getArray();

	nArray::Array<float,10> nAry2;
	nAry2.setArray();
	nAry2.getArray();

	return 0;
}#include<iostream>
#include<exception>
using namespace std;

double divd(double num1, double num2)throw(runtime_error)
{
	if (num2 == 0.0)
		//throw -9;
		throw runtime_error("div by zero 123");
	else
		return (num1/num2);
}

int main()
{
	double m = 0;
	try{
		m = divd(10,0.0);
	}
	catch (runtime_error &ex_error)
	{
		cout << "Exception : " << ex_error.what() << endl;
	}
	/*catch(int k)
	{
		cout<<"div by zero error"<<endl;
	}*/
	catch(const char *str)
	{
		cout<<str<<endl;
	}
	catch(...)
	{
		cout<<"div by zero error"<<endl;
	}
	return 0;
}#include<iostream>
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
}#include<iostream>
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

/*There are 3 important places where a copy constructor is called.
When an object is created from another object of the same type
When an object is passed by value as a parameter to a function
When an object is returned from a function*/

#include<iostream>
using namespace std;

class ABC
{
	int x;
	int y;

public:
	ABC()
	{
		this->x  = 0;
		this->y =  0;
	}
	ABC(int i)
	{
		this->x = i;
		this->y = i;
	}
	ABC(int i, int j)
	{
		this->x = i;
		this->y = j;
	}
	ABC(ABC *obj)
	{
		this->x = obj->x;
		this->y = obj->y;
	}
	void func()
	{
		cout << this->x << " and " << this->y << endl;
	}
};

int main()
{
	ABC *a1 = new ABC(10,20);
	a1->func();

	ABC a2(a1);
	a2.func();

	ABC a3 = a2;
	a3.func();

	delete a1;

	return 0;
}
#include<iostream>
using namespace std;

class ABC
{
public:
	int x;
	
	ABC()
	{
		x = 0;
	}
	ABC(int x)
	{
		this->x = x;
	}
};
class DEF : public ABC
{
	DEF(){}
	DEF(int x):ABC(x){}
	void fun()
	{
		cout << x << endl;
	}
};

int main()
{
	DEF *d  = new DEF(10);

	delete d;

	return 0;
}#include<iostream>
using namespace std;

class ABC
{
	int len;
	int wid;
public:
	ABC()
	{
		this->len = 0;
		this->wid = 0;
	}
	ABC(int i)
	{
		this->len = i;
		this->wid = i;
	}
	ABC(int i, int j)
	{
		this->len = i;
		this->wid = j;
	}
	int getArea()
	{
		return (this->len * this->wid);
	}
	friend void printArea( ABC *obj)
	{
		cout << "len : " <<obj->len << endl;
		cout << "wid : " << obj->wid << endl;
	}

};


class B;

class A
{
	int x;
public:
	A()
	{
		this->x = 0;
	}
	A(int i)
	{
		this->x = i;
	}
	friend class B;
};

class B
{
public:
	void fun(A obj)
	{
		cout << "Object of A : " <<obj.x << endl;
	}
};

int main()
{
	// for friend function
	ABC b(10,20);
	printArea(&b);

	// for friend class
	A a(10);
	B b1;
	b1.fun(a);

	return 0;
}#include<iostream>
using namespace std;

class Area
{

private:
	int len;
	int wid;

public:
	Area()
	{
		this->len = 0;
		this->wid = 0;
	}

	void setLength(int i)
	{
		this->len = i;
	}

	void setWidth(int j)
	{
		this->wid = j;
	}

	int getArea()
	{
		return (this->len * this->wid);
	}
	Area operator+ (Area obj)
	{
		Area res;
		res.len = obj.len + this->len;
		res.wid = obj.wid + this->wid;
		return res;
	}
};
int main()
{
	Area a1;
	a1.setLength(10);
	a1.setWidth(20);
	cout << "a1 : " << a1.getArea() << endl;
	
	Area a2;
	a2.setLength(20);
	a2.setWidth(30);
	cout << "a2 : " << a2.getArea() << endl;
	
	Area a3;
	
	a3 = a1 + a2;
	cout << "a3 : " << a3.getArea() << endl;

	return 0;
}#include<iostream>
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
}#include<iostream>
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
}#include<iostream>
#include<pthread.h>
using namespace std;

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

void *func()
{
	pthread_mutex_lock(&mut1);
	counter++;
	cout << counter << endl;
	pthread_mutex_unlock(&mut1);
}

int main()
{
	int ret1, ret2;
	pthread_t thread1, thread2;

	ret1 = pthread_create(&thread1, NULL, func, NULL);
	if (ret1 == 0)
	{
		cerr << "Cannot crete thread";
	}

	ret2 = pthread_create(&thread2, NULL, func, NULL);
	if (ret2 == 0)
	{
		cerr << "Cannot crete thread";
	}

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	pthread_exit(thread_1);
	pthread_exit(thread_2);

	return 0;
}#include<iostream>
#include<pthread.h>
using namespace std;

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_condition_t cond1 = PTHREAD_COND_INITIALIZER;

int counter = 0;

void *func1()
{
	pthread_mutex_lock(&mut1);

	pthread_cond_wait(&cond1, &mut1);
	counter++;
	cout << counter << endl;
	
	pthread_mutex_unlock(&mut1);
}


void *func2()
{
	pthread_mutex_lock(&mut1);
	
	if (counter >= 10)
		pthread_cond_signal(&cond1);

	pthread_mutex_unlock(&mut1);
}

int main()
{
	int ret1, ret2;
	pthread_t thread1, thread2;

	ret1 = pthread_create(&thread1, NULL, func, NULL);
	if (ret1 == 0)
	{
		cerr << "Cannot crete thread";
	}

	ret2 = pthread_create(&thread2, NULL, func, NULL);
	if (ret2 == 0)
	{
		cerr << "Cannot crete thread";
	}

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	pthread_exit(thread_1);
	pthread_exit(thread_2);

	return 0;
}#include<iostream>
#include<pthread.h>
using namespace std;

void *threadHandler(void * message)
{
	char * msg;
	msg = (char*)message;
	cout << msg << endl;
}

int main()
{
	pthread_t threadID;
	int ret = 0;
	char * mesg = "Hello World";
	ret = pthread_create(&threadID,NULL,threadHandler,(void*)mesg);
	if (ret == 0)
	{
		cerr << "Cannot create a thread.\n";
	}

	pthread_join();
	
	pthread_exit(threadID);
	
	return 0;
}#include<iostream>
using namespace std;

int main()
{
	return 0;
}#include<iostream>
using namespace std;

int main()
{
	return 0;
}#include<iostream>
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
}#include<iostream>
using namespace std;

int main()
{
	return 0;
}#include<iostream>
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
}#include<iostream>
using namespace std;

template<class T>
T add(T a, T b)
{
	return (a + b);
}

template<class T, class U>
class MyClassTemplate
{

private:
	T a;
	U b;

public:	
	MyClassTemplate()
	{
		a = (T)0;
		b = (U)0;
	}
	
	MyClassTemplate(T a, U b)
	{
		this->a = a;
		this->b = b;
	}
	void getFunction()
	{
		cout << "a = " << this->a << " and  b = " << this->b << endl;
	}
};

int main()
{
	double a = 10.12;
	int b = 20;

	cout  << a << " + " << b << " = " << add<double>(a,(double)b)<< endl;
	
	MyClassTemplate<double, int> myObj(a,b);
	myObj.getFunction();

		return 0;
}#include<iostream>
#include<exception>
#include<stdexcept>
using namespace std;

double div(double a, double b) throw(int, const char *, runtime_error)
{
	if (b == 0)
		throw runtime_error("Runtime exception : Divide by zero");
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
	catch(int x)
	{
		cout << "Exception : " << x << endl;
	}
	catch (const char *msg)
	{
		cout << "Exception : " << msg << endl;
	}
	catch (runtime_error &ex_error)
	{
		cout << "Exception : " << ex_error.what() << endl;
	}
	catch (...)
	{
		cout << "Default Exception : divide by zero" << endl;
	}

	return 0;
}#include<iostream>
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
}#include<iostream>
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
}#include<iostream>
using namespace std;

class Abc
{
public:
	int i;

	Abc()
	{
		i = 0;
	}
	Abc(int i)
	{
		this->i = i;
	}

	int getVariableI()
	{
		return this->i;
	}
	void setVariableI(int i)
	{
		this->i = i;
	}
public:
	void fun1(Abc obj){
		cout << "Call by Value " << obj.i << endl;
	}
	void fun2(Abc *obj){
		cout << "Call by Reference " << obj->i << endl;
	}
};
int main()
{

	Abc *a1 = new Abc(10);
	a1->fun1(*a1);
	a1->fun2(a1);

	// 
	Abc a2;
	a2.setVariableI(10);
	a2.fun1(a2);
	a2.fun2(&a2);


	return 0;
}#include<iostream>
using namespace std;

class Abc
{
public:
	int i;

	Abc()
	{
		i = 0;
	}
	Abc(int i)
	{
		this->i = i;
	}

	int getVariableI()
	{
		return this->i;
	}
	void setVariableI(int i)
	{
		this->i = i;
	}
};

int main()
{

	Abc a2;
	a2.setVariableI(10);

	cout << a2.getVariableI() << endl;


	return 0;
}#include<iostream>
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
}#include<iostream>
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
}#include<iostream>
using namespace std;

class ABC
{
public:
	//int i;
	mutable int i;

public:
	ABC()
	{
		this->i = 0;
	}
	ABC(int i)
	{
		this->i = i;
	}
	void func() const
	{
		cout << this->i << endl;
	
		// can modify the non constant vairable inside the const function
		// only if we make the variable mutable
		this->i = this->i + 1;
		cout << this->i << endl;
	}
};

int main()
{
	//constructor over loading with no input argument
	ABC a1;
	a1.func();

	//constructor over loading with one input argument
	ABC a2(10);
	a2.func();

	return 0;
}#include<iostream>

using namespace std;

class ABC{
private:
	int x;
public:
	ABC(){x = 0;}
	ABC(int x){this->x = x;}
	void fun();
	int getX();

};
void ABC::fun()
{
	cout << "ABC" <<endl;
	cout << "x :"<< x << endl;
}

int ABC::getX()
{
	return this->x;
}

class DEF : public ABC{
	int y;
public:
    DEF(){y = 0;}
	DEF(int y){this->y = y;}
	DEF(int x , int y):ABC(x){this->y = y;}
	void fun();
};

void DEF::fun()
{
	cout << "DEF" <<endl;
	cout << "x :"<< this->getX() << endl;
	cout << "y :"<< y << endl;
}

int main(){

	ABC a1(20);
    a1.fun();
	cout<< a1.getX() << endl;

	ABC *a2  = new ABC(10);
	a2->fun();
	cout<< a2->getX() << endl;

	
	DEF *d2  = new DEF(10,12);
	d2->fun();
	

	delete a2;

	int len = 10;
	int *ptr = new int[len];
	for(int i = 0; i < len;i++){
		ptr[i] = i;
	}

	for(int i = 0; i < len;i++){
		cout << *ptr++ << endl;;
	}

	int b1[10];
	int *b[10];

	for(int i = 0; i < 10;i++){
		b[i] = &b1[i];
	}
	for(int i = 0; i < 10;i++){
			b1[i] = i;
	}
	for(int i = 0; i < 10;i++){
			cout << b[i] << " : " << *b[i] << endl;
	}	
	// function pointer

	
	delete ptr;
	return 0;
}	#include<iostream>
	using namespace std;

	namespace kiran
	{
		template<class T>
		class Adder
		{
			private:
				T number1;
				T number2;
			public:
				Adder()
				{
					this->number1 = 0;
					this->number2 = 0;
				}
				Adder(T i)
				{
					this->number1 = i;
					this->number2 = i;
				}			
				Adder(T i,T j)
				{
					this->number1 = i;
					this->number2 = j;
				}
				Adder(Adder<T> &obj);

				Adder<T> operator+(Adder<T> obj);
				T addValues();
				void printResult();
		};

    template<class T>
	Adder<T>::Adder(Adder<T> &obj)
				{
					this->number1 = obj.number1;
					this->number2 = obj.number2;
				}
	template<class T>
	Adder<T> Adder<T>::operator+(Adder<T> obj)
				{
					Adder<T> res;
					res.number1 = this->number1 + obj.number1;
					res.number2 = this->number2 + obj.number2;
					return res;
				}
	template<class T>
	T  Adder<T>::addValues()
				{
					return (this->number1 + this->number1);
				}

	template<class T>
	void Adder<T>::printResult()
				{
					cout << this->number1 << " + " << this->number1 <<  " = " << this->addValues() << endl;; 
				}		
	}

	using namespace kiran;

	int main()
	{
		Adder<int> a1(10,20);
		Adder<int>  a2(30,40);
		Adder<int>  a3;
		Adder<int>  a4(a2);
	
		a3 = a1+a2;
		a3.printResult();
	
		a3 = a1+a4;
		a3.printResult();	
	
		a1.addValues();
		a1.printResult();
	
		a2.addValues();
		a2.printResult();
	
		return 0;
	}