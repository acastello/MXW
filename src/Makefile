CC=winegcc
CFLAGS=-lpthread -g
ALL=actions.exe tests.exe testffi_main

all: $(ALL)

actions.exe: actions.c actions.h
	$(CC) $(CFLAGS) $^ -o $@

tests.exe: tests.c
	$(CC) $(CFLAGS) $^ -o $@

testffi_main: FFItest.hs testffi.o
	ghc --make $^

testffi.o: testffi.c testffi.h
	gcc -c testffi.c -o $@
