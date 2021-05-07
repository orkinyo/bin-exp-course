#include <stdio.h>
#include <stdlib.h>

char idk[] = "/bin/sh";

void gadgets()
{
    __asm__(
        "mov eax, 0x77\n"
        "ret\n"
        "int 0x80\n"
    );
}

int main()
{
    char buf[8];
    gets(buf);
}