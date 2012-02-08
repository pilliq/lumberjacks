
COMPILER = gcc
CCFLAGS  = -ansi -pedantic -Wall
all: shell

debug:
		make DEBUG=TRUE

shell: shell.o
		$(COMPILER) $(CCFLAGS) -o shell shell.c

ifeq ($(DEBUG), TRUE)
	 CCFLAGS += -g
 endif

clean:
		rm -f shell
			rm -f *.o

