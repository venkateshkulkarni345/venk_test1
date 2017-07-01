	#include<iostream>
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
	}