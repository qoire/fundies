CC=gcc
CFLAGS=-I.
DEPS = l_array.h
.PHONY: clean

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: l_array_test.o
	gcc -o test l_array_test.o -I.
	./test

clean:
	rm -rf test *.o
