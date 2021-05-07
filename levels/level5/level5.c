#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct{
    char first_name[8];
    char last_name[8];
}person;

typedef struct{
    char functions_name[8];
    void (*pointer1)();
    void (*pointer2)();
}functions_s;

void setup()
{
    setvbuf(stdin,NULL,_IONBF,0);
    setvbuf(stdout,NULL,_IONBF,0);
}

void win(){
    seteuid(0);
    setgid(0);
    setuid(0);
    system("/bin/sh");
    exit(EXIT_SUCCESS);
}

functions_s* func_g = NULL;
person* person_g = NULL;

void interesting_function_rlyyyyy()
{
    sleep(1);
}

void create_functions(){
    assert(func_g == NULL);
    func_g = malloc(sizeof(functions_s));
    printf("how should I name func_g?\n");
    scanf("%8s",func_g->functions_name);
    printf("alright that's enough of you, now let me decide the rest please...\n");
    func_g->pointer1 = &interesting_function_rlyyyyy;
    func_g->pointer2 = &interesting_function_rlyyyyy;
}

void call_functions(){
    printf("alright, now about to call functions. I sure hope everything is OK\n");
    (*func_g->pointer1)();
    (*func_g->pointer2)();
}

void create_person(){
    assert(person_g == NULL);
    person_g = malloc(sizeof(person));
}

void name_person(){
    printf("first name:\n");
    scanf("%8s",person_g->first_name);
    printf("last name:\n");
    scanf("%8s",person_g->last_name);
}

void my_exit(){
    if(func_g != NULL){
        free(func_g);
    }   
    char choice;
    printf("are you sure you want to exit (y/n)?: \n");
    fflush(stdout);
    __fpurge(stdin);
    scanf("%c",&choice);
    if (choice == 'y')
    {
        exit(0);
    }
    else{
        return;
    }
}

void menu()
{
    setup();
    unsigned int sel;
    char* menu = "what would you like to do next:\n1:create new functions?\n2:call_functions?\n3:create a person?\n4:name a person?\n5:exit?\n";
    while (1)
    {
        __fpurge(stdin);
        printf("%s",menu);
        scanf("%u",&sel);
        __fpurge(stdin);
        switch (sel)
        {
            case 1:
                create_functions();
                break;
            case 2: 
                call_functions();
                break;
            case 3:
                create_person();
                break;
            case 4:
                name_person();
                break;
            case 5:
                my_exit();
                break;
            default:
                break;
        }
    }
    
}

int main()
{
    //printf("sizeof(functions_s) = %lu\n",sizeof(functions_s));
    int sel;
    printf("HOW R U?? OMGGG WELCOME TO THE University of Alaska Fairbanks or in short UAF\n\n\n");
    menu();

    printf("is this code even reacheble LOLLLL\n");
    return EXIT_SUCCESS;
    
    
    
}