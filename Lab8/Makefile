# Compiler and flags
CC = gcc
CFLAGS = -Wall -pedantic -std=c99

# inlcude files directory, contains header files
INCLUDES = -Iinclude

# Directories with source code, object files and binary
SRCDIR = src/
BINDIR = bin/
OBJDIR = obj/

MAINPROG = $(BINDIR)main


program: $(OBJDIR)main.o
	$(CC) $< -o $(MAINPROG)

$(OBJDIR)main.o: $(SRCDIR)main.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm $(OBJDIR)*.o $(MAINPROG)