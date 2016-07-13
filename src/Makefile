CC=winegcc
<<<<<<< HEAD
CFLAGS=-lpthread -g
ALL=actions.exe tests.exe testffi_main
=======
CFLAGS=-lpthread -lX11
ALL=actions.exe tests.exe
>>>>>>> 6a8e5ff4541a03ed352303cfb78a39ef1b64c1c8

all: $(ALL)

actions.exe: actions.c actions.h
	$(CC) $(CFLAGS) $^ -o $@

tests.exe: tests.c
	$(CC) $(CFLAGS) $^ -o $@

testffi_main: FFItest.hs testffi.o
	ghc --make $^

testffi.o: testffi.c testffi.h
	gcc -c testffi.c -o $@
