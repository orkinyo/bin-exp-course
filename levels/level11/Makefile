CC = gcc
level11 : level11.c
	${CC} level11.c -o level11 -D_FORTIFY_SOURCE=0 -w -O3 -g -m32 -fno-pic -no-pie -Wl,-z,relro,-z,now -mpreferred-stack-boundary=2 -Wl,--rpath ../level11 -Wl,--dynamic-linker=./ld-2.23.so
	#sudo chown root ./level8 
	#sudo chgrp root ./level8
	#sudo chmod a+s ./level8 