CC=winegcc
CFLAGS=-lpthread -lX11
ALL=actions.exe tests.exe

all: $(ALL)

actions.exe: actions.c actions.h
	$(CC) $(CFLAGS) $^ -o $@

tests.exe: tests.c
	$(CC) $(CFLAGS) $^ -o $@
