/*****program to create thread and join thread and print thread id***/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


void *pthread1(void *param);


int main()
{
pthread_t tid; //decalring the tid variable of type pthread_t

pthread_create(&tid,NULL,pthread1,(void *)&tid);
//pthread_careate is to create the thread 
// 1st argument is the thread id which is of type pthread_t (structure data type) this is defined in pthread.h
//2nd argument is Attributes,here we are passing NULL
//3rd argument is our thread handling function name 
//4th is the argument weare to the thread handling fuction

pthread_join(tid,NULL);
//ptheread_join will suspend the execution of main function until our thread handling function execution finishes

return 0;
}

void *pthread1(void *param)
{
printf("The value received=%lu\n",(long)param);
pthread_exit(0);
//pthread_exit function is used to exit from the thread
}


