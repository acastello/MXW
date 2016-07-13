CC=winegcc
CFLAGS=-lpthread -lX11
ALL=actions.exe tests.exe testffi_main

all: $(ALL)

clean:
	rm -fv *.o *.hi

actions.o: actions.c
	$(CC) $(CFLAGS) $^ -c

actions.exe: actions.o actions.h
	$(CC) $(CFLAGS) actions.o -o $@

tests.exe: tests.c
	$(CC) $(CFLAGS) $^ -o $@

testffi_main: testffi_main.hs FFItest.hs testffi.o
	ghc --make $^ -o $@

testffi.o: testffi.c
	gcc $^ -c -o $@
