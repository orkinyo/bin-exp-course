#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int x0r[] = {6, 4, 1, 25, 25, 84, 66, 1, 13, 6, 39, 95, 46, 6, 5, 78};
char* exp_s = "dabbad00caf3bab3";



bool meme(char* s)
{
    for(char* c = s ; *c ;++c)
    {
       
        if (((int)(exp_s[c-s] ^ (*c))) != x0r[c-s])
        {
            printf("%d != %d\n",exp_s[c-s] ^ *c,x0r[c-s]);
            return false;
        }
    }
    return true;
}

int main()
{
    char password[17];
    password[17] = '\0';
    printf("----ADMIN CONTROL PANEL LOGIN UI----\n");
    printf("Please Enter Secret Password:\n");
    scanf("%16s",password);
    if(strlen(password) != 16)
    {
        printf("ACCESS DENIED - PASSWORDS LENGTH\n");
        exit(1);
    }
    
    bool succsess = meme(password);
    if(!succsess)
    {
        printf("ACCESS DENIED\n");
        exit(1);
    }

        
    printf("!!!ACCESS GRANTED!!!\n");
    return 0;

}