# My first Greeting API Makefile

# This is also my first "slave" Makefile
DEBUG = yes
CC = gcc
DEBUG_CFLAGS = -W -Wall -ansi -pedantic -g
CFLAGS = $(DEBUG_CFLAGS)

# File_dir
INCDIR = include
SRCDIR = src
OBJDIR = obj/debug

# Object_file
OBJ = libgreeting.o

# @ : hide current trace
all: $(OBJ)
	@echo -e "\033[31;5mGeneration en mode debug ...\033[0m"

$(OBJ): $(SRCDIR)/greeting_lib.c $(INCDIR)/greeting_lib.h
	@$(CC) -o $(OBJDIR)/$@ -c $< $(CFLAGS)

.PHONY: clean

clean:
	@rm -rf $(OBJDIR)/*.o

