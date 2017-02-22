# My first Hello App Makefile

# This is also my first "master" Makefile
DEBUG = yes
export CC = gcc
export DEBUG_CFLAGS = -W -Wall -ansi -pedantic -g
export RELEASE_CFLAGS = -W -Wall -ansi -pedantic

ifeq ($(DEBUG), yes)
	CFLAGS = $(DEBUG_CFLAGS)
	LDFLAGS =
else
	CFLAGS = $(RELEASE_CFLAGS)
	LDFLAGS =
endif

# File_dir
SRCDIR = src
OBJDIR = obj
DEBUG_BINDIR = bin/debug
RELEASE_BINDIR = bin/release

ifeq ($(DEBUG), yes)
	BINDIR = $(DEBUG_BINDIR)
else
	BINDIR = $(RELEASE_BINDIR)
endif

LIBDIR = ../TEST_LIB_C
LIBOBJDIR = $(LIBDIR)/obj/debug

# Executable_name
BIN = main

# @ : hide current trace.
all: $(BIN)

ifeq ($(DEBUG), yes)
	@echo -e "\033[31;5mGeneration en mode debug ...\033[0m"
else
	@echo -e "\033[32;5mGeneration en mode release ...\033[0m"
endif

$(BIN): main.o
	@$(CC) -o $(BINDIR)/$@ $(OBJDIR)/$< $(LIBOBJDIR)/libgreeting.o $(LDFLAGS)

main.o: $(SRCDIR)/main.c
	@$(CC) -o $(OBJDIR)/$@ -c $< $(CFLAGS)

.PHONY: clean rmproper 

clean:
	@rm -rf $(OBJDIR)/*.o

mrproper:
	@rm -rf $(BINDIR)/$(BIN)
