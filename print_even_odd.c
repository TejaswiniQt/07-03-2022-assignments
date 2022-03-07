/****program to print even and odd numbers using two threads ****/

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int max=10;
unsigned int data=0;

void *even_thread(void *ptr)
{
    do
    {
	if(data % 2 == 0)
	{
	    printf("Even:%d\n",data);
	    data++;
	}
    }while(data<=max);
}

void *odd_thread(void *ptr)
{
    do
    {
	if(data % 2 != 0)
	{
	    printf("Odd:%d\n",data);
	    data++;
	}
    }while(data<=max);
}

int main()
{
    pthread_t tid[2];

    pthread_create(&tid[0],NULL,&even_thread,NULL);
    pthread_create(&tid[1],NULL,&odd_thread,NULL);

    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);


    return 0;
}



