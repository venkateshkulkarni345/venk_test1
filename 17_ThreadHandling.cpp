#include<iostream>
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
}