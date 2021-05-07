#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>

char stack[51];

char idk[] = "/bin/sh";

void construc(void) __attribute__((constructor));

void construc(void)
{
    puts("welcome!");    
    setvbuf(stdout, 0, _IONBF, 0);   
}

void win()
{
    __asm__(
        "mov eax,11 \n"
        "ret \n"
        "pop ebx \n"
        "ret \n"
        "pop ecx \n"
        "ret \n"
        "pop edx \n"
        "ret \n"
        "int 0x80"

    );
}

void gadgets()
{
    __asm__(
        "pop esp \n"
        "ret \n"
    );
}

int main()
{
    read(0,stack,51);
    stack[51] = '\0';
    char book_name[4];
    read(0,book_name,13);
}