CC = gcc

level2 : level2.c
	${CC} level2.c -o level2 -w -Ttext=0x03bbc0ff -O3 -g -fno-pic -fno-stack-protector -m32 -Wl,-z,norelro -z execstack -mpreferred-stack-boundary=2 -no-pie
	#sudo chown root ./level2
	#sudo chgrp root ./level2
	#sudo chmod a+s ./level2