CC = gcc

level3 : level3.c
	${CC} level3.c -o level3 -w -O1 -g -fno-pic -no-pie -fno-stack-protector -m32 -Wl,-z,norelro  -mpreferred-stack-boundary=2
	#sudo chown root ./level3
	#sudo chgrp root ./level3
	#sudo chmod a+s ./level3