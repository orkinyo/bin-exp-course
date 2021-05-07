CC = gcc
level21 : level21.c
	${CC} level21.c -o level21 -w -fno-stack-protector -Wl,-z,norelro -z execstack -w -O0 -g -m32 -mpreferred-stack-boundary=2 