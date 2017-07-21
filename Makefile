all: ush

ush:
	gcc -O2 -static -o ush ush.c

clean:
	rm -f *.o ush
