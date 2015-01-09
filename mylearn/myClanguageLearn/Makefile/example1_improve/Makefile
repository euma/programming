test: main.o add.o sub.o
	gcc -o a main.o add.o sub.o

add.o: add.c
	gcc -c add.c

sub.o: sub.c
	gcc -c sub.c    

clean:
	rm -rf a
	rm -rf *.o
	rm -rf *~
