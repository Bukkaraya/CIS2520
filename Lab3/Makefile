# Compiler and flags
CC = gcc
CFLAGS = -Wall -pedantic -std=c99

#include files directory, contains header files
INCLUDES = -Iinclude

CFLAGS += $(INCLUDES)

#Directories with source code, object files, binary files
SRCDIR = src/
BINDIR = bin/
OBJDIR = obj/

#Flags to use find and use libraries
LIBFLAGS = -L./lib -lLinkedList

#Binary file output name
MAINPROG = $(BINDIR)main
TESTPROG = $(BINDIR)testMain

all: program test

program: $(OBJDIR)main.o $(OBJDIR)book.o
	$(CC) $^ $(LIBFLAGS) -o $(MAINPROG)

test: $(OBJDIR)book.o $(OBJDIR)testMain.o
	$(CC) $^ $(LIBFLAGS) -o $(TESTPROG)

$(OBJDIR)book.o: $(SRCDIR)book.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)testMain.o: $(SRCDIR)testMain.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)main.o: $(SRCDIR)main.c
	$(CC) $(CFLAGS) -c $< -o $@



clean:
	@rm $(OBJDIR)*.o $(MAINPROG)