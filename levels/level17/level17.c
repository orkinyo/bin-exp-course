#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

volatile int x;

void* th2(void* arg)
{
    puts("enter x:");
    scanf("%i",&x);
}

void* th1(void* arg)
{
    if(x == 5) //toc
    {
        sleep(2);

        if(x == 1337) //tou
        {
            system("cat flag.txt");
        }

        else
        {
            puts("bye");
        }
    }
}


int main()
{
    int  ret1, ret2;
    x = 5;
    pthread_t thread1, thread2;
    ret1 = pthread_create(&thread1, NULL, th1, (void*) NULL);
    ret2 = pthread_create(&thread2, NULL, th2, (void*) NULL);

    pthread_join( thread1, NULL);
    pthread_join( thread2, NULL); 

    exit(EXIT_SUCCESS);



}