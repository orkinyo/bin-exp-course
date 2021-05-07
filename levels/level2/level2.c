#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void win()
{
  system("/bin/sh");
}

int main()
{
  char buf[100];
  printf("now buffer overflow me!\n");
  gets(buf);
}