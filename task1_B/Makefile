# -*- Makefile -*-

all: main

main: main2_4.c nested clone daemon
	gcc -o main main2_4.c

nested: main2_1.c
	gcc -o nested main2_1.c

clone: main2_2.c
	gcc -o clone main2_2.c

daemon: main2_3.c
	gcc -o daemon main2_3.c

.PHONY: clean all

clean:
	-rm -f *.o main nested clone daemon 2>/dev/null

