all: normal_distribution.o
	gcc -o program normal_distribution.o

normal_distribution.o: normal_distribution.c
	gcc -c normal_distribution.c

clean:
	rm *.o

run:
	./program
	make clean
