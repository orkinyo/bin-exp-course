#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main()
{
    char* program = "./level16";
    char* argv = NULL;
    char* envp = {0};
    
    puts("--pwned--");
    execve(program,argv,envp);
}