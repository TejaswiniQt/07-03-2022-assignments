/****program to print uppercase and lowercase letters using two threads ****/

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

char ch=65;

void *capital(void *ptr)
{
    while(ch <= 90)
    {
	printf("%c ",ch);
	sleep(1);
    }
    printf("\n");
    pthread_exit(NULL);
}

void *small(void *ptr)
{
    while(ch <= 90)
    {
	printf("%c ",ch+32);
	sleep(1);
	ch++;
    }
    printf("\n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t tid[2];

    pthread_create(&tid[0],NULL,&capital,NULL);
    pthread_create(&tid[1],NULL,&small,NULL);

    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);

    return 0;

}