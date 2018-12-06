# My first Hello App Makefile

#**********************************************************************#
#*** fichier: Makefile                                              ***#
#*** create depend, build, clean, rebuild project                   ***#
#**********************************************************************#

# This is also my first "master" Makefile
# VPATH = src:../include
#.SUFFIXES: .c
.DEFAULT: all
.PHONY: clean mrproper

export DEBUG = yes
export CC = gcc
export CD = cd
export RM = rm
export ECHO = echo
export MAKEDEPEND = makedepend
export MAKE = make

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

SRC = $(SRCDIR)/main.c
OBJ = $(OBJDIR)/main.o
# Executable_name
BIN = $(BINDIR)/main

GREETAPIDIR = ../GREET_API_C
MATHAPIDIR = ../MATH_API_C

INCGREETAPIDIR = ../GREET_API_C/include
INCMATHAPIDIR = ../MATH_API_C/include

LIBGREETAPIDIR = ../GREET_API_C/lib/debug
LIBMATHAPIDIR = ../MATH_API_C/lib/debug

DEBUG_CFLAGS = -I$(INCGREETAPIDIR) -I$(INCMATHAPIDIR) \
               -W -Wall -ansi -pedantic -g
RELEASE_CFLAGS = -I$(INCGREETAPIDIR) -I$(INCMATHAPIDIR) \
                 -W -Wall -ansi -pedantic

ifeq ($(DEBUG), yes)
	CFLAGS = $(DEBUG_CFLAGS)
else
	CFLAGS = $(RELEASE_CFLAGS)
endif

LDFLAGS = -L$(LIBGREETAPIDIR) -lgreetingapi \
	      -L$(LIBMATHAPIDIR) -lmathapi

SUBDIRS = $(GREETAPIDIR) \
          $(MATHAPIDIR)


# @ : hide current trace.
all:
ifeq ($(DEBUG), yes)
	@$(ECHO) -e "\033[31;5mGeneration en mode debug ...\033[0m"
else
	@$(ECHO) -e "\033[32;5mGeneration en mode release ...\033[0m"
endif
	for dir in $(SUBDIRS); do ($(CD) $$dir; $(MAKE) $@); done
	$(MAKE) $(BIN)

$(BIN): $(OBJ)
	@$(CC) -o $@ $(OBJ) $(LDFLAGS)

$(OBJ): $(SRC)
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@$(ECHO) -e "\033[31;5mSuppression des fichiers objets et librairies ...\033[0m"
	@$(RM) -rf $(OBJDIR)/*.o
	for dir in $(SUBDIRS); do ($(CD) $$dir; $(MAKE) $@); done

mrproper: clean
	@$(ECHO) -e "\033[31;5mSuppression de l'executable ...\033[0m"
	@$(RM) -f $(BIN)

depend:
	@$(MAKEDEPEND) -- $(CFLAGS) -- $(SRC)
	for dir in $(SUBDIRS); do ($(CD) $$dir; $(MAKE) $@); done
