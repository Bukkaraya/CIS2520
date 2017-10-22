#Compiler and flags
CC = gcc
CFLAGS = -Wall -std=c99

#inlcude files directory
INCLUDES = -Iinclude

#Directories with source code, object files and binary
SRCDIR = src/
BINDIR = bin/
OBJDIR = obj/


OBJS = $(OBJDIR)patient.o $(OBJDIR)linkedListAPI.o $(OBJDIR)priorityQueue.o


PROGNAME = $(BINDIR)main
PROGTEST = $(BINDIR)testMain


all: program test


program: $(OBJS) $(OBJDIR)main.o
	$(CC) $(OBJS) $(OBJDIR)main.o -o $(PROGNAME)

test:  $(OBJDIR)testMain.o $(OBJDIR)linkedListAPI.o
	$(CC) $^ -o $(PROGTEST)

$(OBJDIR)patient.o: $(SRCDIR)patient.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)priorityQueue.o: $(SRCDIR)priorityQueue.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)linkedListAPI.o : $(SRCDIR)linkedListAPI.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)testMain.o: $(SRCDIR)testMain.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)main.o: $(SRCDIR)main.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm $(OBJDIR)*.o $(PROGNAME) $(PROGTEST)
