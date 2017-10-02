#Compiler and flags
CC = gcc
CFLAGS = -Wall -std=c99

#inlcude files directory
INCLUDES = -Iinclude

#Directories with source code, object files and binary
SRCDIR = src/
BINDIR = bin/
OBJDIR = obj/

SOURCE = $(SRCDIR)car.c $(SRCDIR)testMain.c
OBJS = $(OBJDIR)car.o $(OBJDIR)linkedListAPI.o

PROGNAME = $(BINDIR)main
PROGTEST = $(BINDIR)testMain

all: program test

program: $(OBJS) $(OBJDIR)main.o
	$(CC) $(OBJS) $(OBJDIR)main.o -o $(PROGNAME)

test: $(OBJS) $(OBJDIR)testMain.o
	$(CC) $(OBJS) $(OBJDIR)testMain.o -o $(PROGTEST)

$(OBJDIR)car.o: $(SRCDIR)car.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCDIR)car.c -o $(OBJDIR)car.o

$(OBJDIR)linkedListAPI.o : $(SRCDIR)linkedListAPI.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)testMain.o: $(SRCDIR)testMain.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCDIR)testMain.c -o $(OBJDIR)testMain.o

$(OBJDIR)main.o: $(SRCDIR)main.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCDIR)main.c -o $(OBJDIR)main.o

clean:
	@rm $(OBJDIR)*.o $(PROGNAME) $(PROGTEST)
