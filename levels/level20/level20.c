#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>

char name[5];

void construc(void) __attribute__((constructor));

void construc(void)
{
    setvbuf(stdout, 0, _IONBF, 0);   
    int start_address =  (((int) &name) - (( (int) & name) % 0x1000));
    mprotect((void*) start_address ,0x1000,PROT_READ | PROT_WRITE | PROT_EXEC);
}

int main()
{
    
    char book_name[4];
    puts("Welcome, what is your name:");
    fgets(name,sizeof(name), stdin);
    * strchr(name,'\n') = 0;
    printf("welcome %s, please enter your favorite book's name:\n",name);
    gets(book_name);
}