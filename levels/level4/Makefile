CC = gcc

level4 : level4.c
	${CC} level4.c -o level4 -w -O3 -g -fno-pic -no-pie -fno-stack-protector -Wl,-z,norelro -mpreferred-stack-boundary=4 -masm=intel 
	#sudo chown root ./level4
	#sudo chgrp root ./level4
	#sudo chmod a+s ./level4