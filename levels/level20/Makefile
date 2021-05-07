CC = gcc
level20 : level20.c
	${CC} level20.c -o level20 -w -fno-stack-protector -Wl,-z,norelro -z execstack -w -O0 -g -m32 -mpreferred-stack-boundary=2 