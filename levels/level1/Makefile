CC = gcc

level1 : level1.c
	${CC} level1.c -o level1 -fno-pie -no-pie -w -O0 -g -fno-stack-protector -m32 -Wl,-z,norelro -z execstack -mpreferred-stack-boundary=2
	#sudo chown root ./level1
	#sudo chgrp root ./level1
	#sudo chmod a+s ./level1