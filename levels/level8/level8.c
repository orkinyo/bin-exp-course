#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <unistd.h>

int i = 0;

int main()
{
    char fsb[100];
    memset(fsb,0,100);
    setvbuf(stdout, 0, _IONBF, 0); 
    printf("data to print before sleeping: ");
    scanf("%90s",fsb);
    printf(fsb);
    printf("\ni = %d\n",i);

    if(i == 420)
    {
        puts("N1c3!! here is your shell:");
        system("/bin/sh");
    }
    else
    {
        puts("\nGOODBYE!");
    }
}