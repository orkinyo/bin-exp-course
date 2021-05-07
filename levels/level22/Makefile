CC = gcc

level22 : level22.c
	${CC} level22.c -o level22 -D_FORTIFY_SOURCE=0 -w -O3 -mpreferred-stack-boundary=2 -g -fno-pic -m32 -no-pie -fno-stack-protector -Wl,-z,norelro -masm=intel 
