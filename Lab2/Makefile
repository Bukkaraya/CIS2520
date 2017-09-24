# Compiler and flags
CC = gcc
CFLAGS = -Wall -pedantic -std=c99

# inlcude files directory, contains header files
INCLUDES = -Iinclude

# Directories with source code, object files and binary
SRCDIR = src/
BINDIR = bin/
OBJDIR = obj/

SOURCE = $(SRCDIR)store.c $(SRCDIR)book.c $(SRCDIR)boardgame.c 
OBJS = $(OBJDIR)store.o $(OBJDIR)book.o $(OBJDIR)boardgame.o

MAINPROG = $(BINDIR)main.out


program: $(OBJS) $(OBJDIR)main.o
	$(CC) $(OBJS) $(OBJDIR)main.o -o $(MAINPROG)

$(OBJDIR)store.o: $(SRCDIR)store.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCDIR)store.c -o $(OBJDIR)store.o

$(OBJDIR)book.o: $(SRCDIR)book.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCDIR)book.c -o $(OBJDIR)book.o

$(OBJDIR)boardgame.o: $(SRCDIR)boardgame.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCDIR)boardgame.c -o $(OBJDIR)boardgame.o

$(OBJDIR)main.o: $(SRCDIR)main.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCDIR)main.c -o $(OBJDIR)main.o

clean:
	@rm $(OBJDIR)*.o $(MAINPROG)
