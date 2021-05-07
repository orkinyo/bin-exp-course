CC = gcc
level15 : level15.c
	${CC} level15.c -o level15 -g -no-pie -Wl,-z,norelro -Wl,--rpath ./ -Wl,--dynamic-linker=./ld-2.23.so
	#sudo chown root ./level8
	#sudo chgrp root ./level8
	#sudo chmod a+s ./level8