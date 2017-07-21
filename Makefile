all: ush

ush: ush.c
	gcc -O2 -static -o ush ush.c

clean:
	rm -f *.o ush
