#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <unistd.h>
#include <malloc.h>

char idk[] = "/bin/sh";

void win(char* a)
{
    system(a);
}

unsigned long read_number()
{
    char in[32];
    memset(in,0,32);
    read(0,in,31);
    return (unsigned long) strtoul(in,NULL,0);
}


int main()
{
    char fsb[100];
    setvbuf(stdout, 0, _IONBF, 0); 
    unsigned int (*ptr) (unsigned int) = &sleep;
    unsigned int (**a) (unsigned int) =  &ptr;
    void* b = (void*) (((char*) (a)) + (sizeof (unsigned int*) / 2));
    printf("ILIKE TO SLEEP, TIME TO SLEEP: ");

    unsigned int sleep_time = read_number();
    printf("data to print before sleeping: ");
    scanf("%90s",fsb);
    printf(fsb);
    printf("\nptr = %p",ptr);
    (*ptr)(sleep_time);
}