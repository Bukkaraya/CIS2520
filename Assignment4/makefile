#Compiler and flags
CC = gcc
CFLAGS = -Wall -std=c99

#inlcude files directory
INCLUDES = -Iinclude

#Directories with source code, object files and binary
SRCDIR = src/
BINDIR = bin/
OBJDIR = obj/


OBJS = $(OBJDIR)binarySearchTreeAPI.o $(OBJDIR)rule.o


PROGNAME = $(BINDIR)main
PROGTEST = $(BINDIR)testMain

all: program test


test:  $(OBJDIR)testMain.o $(OBJS)
	$(CC) $^ -o $(PROGTEST)

program: $(OBJS) $(OBJDIR)main.o
	$(CC) $(OBJS) $(OBJDIR)main.o -o $(PROGNAME)

$(OBJDIR)binarySearchTreeAPI.o : $(SRCDIR)binarySearchTreeAPI.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)rule.o : $(SRCDIR)rule.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)testMain.o: $(SRCDIR)testMain.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)main.o: $(SRCDIR)main.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm $(OBJDIR)*.o $(PROGNAME) $(PROGTEST)
