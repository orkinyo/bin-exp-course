#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <unistd.h>
#include <malloc.h>

void (*ptr) (void) = NULL;

void win(void)
{
    system("/bin/sh");
}


int main()
{
    char fsb[100];
    memset(fsb,0,100);
    setvbuf(stdout, 0, _IONBF, 0); 
    printf("data to print before sleeping: ");
    scanf("%90s",fsb);
    printf(fsb);
    if(ptr != NULL)
    {
        (*ptr)();
    }
    else
    {
        puts("\nGOODBYE!");
    }
}