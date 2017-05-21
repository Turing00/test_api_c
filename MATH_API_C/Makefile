# My first Greeting API Makefile

#**********************************************************************#
#*** fichier: Makefile                                              ***#
#*** create depend, build, clean, rebuild project                   ***#
#**********************************************************************#

# This is also my first "slave" Makefile
#.SUFFIXES: .c
.DEFAULT: all
.PHONY: clean

# File_dir
SRCDIR = src
LIBDIR = lib/debug

# Source_file
SRC = $(SRCDIR)/math_lib.c

# Object_file
LIB = $(LIBDIR)/libmathapi.so


# @ : hide current trace
all: $(LIB)
	@$(ECHO) -e "\033[31;5mGeneration en mode debug ...\033[0m"

$(LIB): $(SRC)
	@$(CC) -shared -fPIC -o $@ -c $<

clean:
	$(RM) -rf $(LIBDIR)/*.so

depend:
	@$(MAKEDEPEND) -- $(CFLAGS) -- $(SRC)
