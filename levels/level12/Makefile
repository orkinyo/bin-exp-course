CC = gcc
level12 : level12.c
	${CC} level12.c -o level12 -D_FORTIFY_SOURCE=0 -w -masm=intel -m32 -fno-stack-protector -mpreferred-stack-boundary=2 -O3 -g -fno-pic -no-pie -Wl,-z,relro,-z,now -Wl,--rpath ../level12 -Wl,--dynamic-linker=./ld-2.23.so
	#sudo chown root ./level8 
	#sudo chgrp root ./level8
	#sudo chmod a+s ./level8