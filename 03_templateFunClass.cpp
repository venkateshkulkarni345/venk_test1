#include<iostream>
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
}