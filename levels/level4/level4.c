#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* special = "/bin/sh\0";

void gadgets()
{
    __asm__(
        "mov rax,59 \n"
        "ret \n"
        "pop rsi \n"
        "ret \n"
        "pop rdi \n"
        "ret \n"
        "pop rdx \n"
        "ret \n"
        "syscall"

    );
}
//gcc level3.c -o level3 -fno-stack-protector ............. what does  that mean?!?!
int main()
{
    char buf[100];
    printf("LOL.....Isn't this just level 3?!\n");
    read(0,buf,200);
    
}