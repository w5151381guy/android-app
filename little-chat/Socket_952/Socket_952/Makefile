#!/bin/sh

CC = g++
MAKEFLAG=
LDFLAGS=
LIBS=
CFLAGS= -Wall -O

EXE = client server

.cpp.o:   ;   $(CC) $(MAKEFLAG) $(CFLAGS) -c $*.cpp

all:$(EXE)

client: lib.o client.o
	$(CC) $(MAKEFLAG) -o $@ $? $(LDFLAGS) $(LIBS)

server: lib.o server.o
	$(CC) $(MAKEFLAG) -o $@ $? $(LDFLAGS) $(LIBS)

clean:
	rm -rf $(EXE) *.o *~ *.core DEADJOE log answer answer1
