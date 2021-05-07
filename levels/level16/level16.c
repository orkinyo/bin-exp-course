#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    if(argc == 0)
    {
        system("/bin/sh");
        exit(EXIT_SUCCESS);
    }

    else
    {
        puts("LLESHON~[-+-]bye[-+-]~NOSHELL");
        exit(EXIT_FAILURE);
    }
    
}