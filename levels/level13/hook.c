#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

int printf(const char *format, ...)
{
    puts("[+] hooked successfully");
    char* flag;
    va_list argp;
    va_start(argp, format);
    flag = va_arg(argp,char*);
    puts("we learned about hooking with LD_PRELOAD and also about varargs, btw here is your flag:");
    puts(flag);
    puts("!!win!!");
}