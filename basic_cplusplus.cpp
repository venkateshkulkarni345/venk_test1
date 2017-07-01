#include<iostream>

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
}