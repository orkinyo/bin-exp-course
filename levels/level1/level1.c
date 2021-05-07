#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int key = 0xcafebabe;
  char buf[20];
  printf("now buffer overflow me!\n");
  gets(buf);
  printf("key = %p\n",key);
  if(key == 0xdeadbeef)
  {
    system("/bin/bash");
  }
  else
  {
    printf("But Why??\n");
    return 1;
  }
}
