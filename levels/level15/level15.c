#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <unistd.h>
#include <malloc.h>

#define max_books 30

char name[0x100];

char* books[max_books];

unsigned long read_number()
{
    char in[32];
    memset(in,0,32);
    read(0,in,31);
    return (unsigned long) strtoul(in,NULL,0);
}

int get_first_free_shelf()
{
    for(int i = 0 ; i < max_books ; i++)
    {
        if (books[i] == NULL)
        {
            return i;
        }
    }
    return -1;
}
void write_book()
{
    int pages;
    int free_shelf;
    free_shelf = get_first_free_shelf();
    if(free_shelf == -1)
    {
        printf("You are too creative, goodbye!\n");
        exit(0);
    }
    
    printf("how long is your book\n> ");
    pages = read_number();
    if(pages > 0x58)
    {
        puts("to many pages, pepople are stupid!");
        exit(0);
    }
    books[free_shelf] = malloc(pages);
    printf("story pls> ");
    read(0,books[free_shelf],pages);
}

void destroy()
{
    int index;
    printf("book index to destroy> ");
    index = read_number();
    if (index >= max_books)
    {
        printf("index out of range!");
        exit(0);
    }
    free(books[index]);
}

void masterpiece()
{
    int pages;
    printf("how long is your masterpiece?\n> ");
    pages = read_number();
    char* holy_book = malloc(pages); 
    printf("story pls> ");
    read(0,holy_book,pages);
}

void reinvent()
{
    printf("your new name?> ");
    read(0,name,0x100);
    printf("Hello you are great and writing is of great importance to the human race! you are genius and your name is @ %s!\n",name);
}


void menu()
{

    unsigned int choice;
    while(1)
    {
        puts("1. write a book");
        puts("2. destroy a book in angr because you are a creative crazy person");
        puts("3. reinvent yourself, and your name...");
        puts("4. go to lunch (and exit)");
        printf("> ");
        choice = read_number();


        switch (choice) {

            case 1:
                write_book();
                break;
            
            case 2:
                destroy();
                break;

            case 3:
                reinvent();
                break;

            case 4:
                exit(0);
            
           
            case 133742069:
                masterpiece();

            default:
                break;
        }
    }
}


int main()
{
    setvbuf(stdout,0,2,0);
    puts("Welcome to the library!");
    puts("I heard that you are the best author so pls help us: we need more books");
    printf("what your name?\n> ");
    read(0,name,0x100);

    puts("I shall now introduce you to our robotic assistant, CHAD\n");

    menu();
}