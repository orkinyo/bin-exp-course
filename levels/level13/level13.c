#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long int sz;
    FILE* f;
    char* s;
    f = fopen("./flag.txt","r");

    fseek(f,0,SEEK_END);
    sz = ftell(f);
    rewind(f);

    s = malloc(sz + 1);
    fread(s,sz,1,f);
    s[sz] = 0;

    printf("no_flag_here!\n",s);

    
}