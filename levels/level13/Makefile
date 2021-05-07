all: level13 hook.so


CC = gcc
level13 : level13.c
	${CC} level13.c -o level13 -w
	#sudo chown root ./level8 
	#sudo chgrp root ./level8
	#sudo chmod a+s ./level8
hook.so : hook.c
	${CC} hook.c -o hook.so -fPIC -shared -ldl