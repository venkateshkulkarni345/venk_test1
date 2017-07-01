#include<iostream>
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
}