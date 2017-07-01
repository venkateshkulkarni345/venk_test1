#include<iostream>
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
}