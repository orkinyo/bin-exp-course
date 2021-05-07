CC = gcc

level5 : level5.c
	${CC} level5.c -o level5 -Wl,--rpath ./ -Wl,--dynamic-linker=./ld-2.24.so -w -g -no-pie
	sudo chown root ./level5
	sudo chgrp root ./level5
	sudo chmod a+s ./level5