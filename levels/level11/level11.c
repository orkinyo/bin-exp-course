#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <unistd.h>
#include <malloc.h>

char fsb[100] = {0};

void win()
{
    system("/bin/sh");
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
    char overflow[20];
    setvbuf(stdout, 0, _IONBF, 0); 
    printf("data to print before sleeping: ");
    scanf("%90s",fsb);
    printf(fsb);
    printf("\nplease overflow, but mind the bird: ");
    fflush(stdin);
    read(0,overflow,0x100);
}