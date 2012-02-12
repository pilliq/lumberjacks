COMPILER = gcc
CCFLAGS  = -ansi -pedantic -Wall
all: shell

debug:
	make DEBUG=TRUE

shell: shell.o util.o linked-list.o
	$(COMPILER) $(CCFLAGS) -o shell shell.o util.o
shell.o: util.c util.h
	$(COMPILER) $(CCFLAGS) -c shell.c
util.o: util.c util.h
	$(COMPILER) $(CCFLAGS) -c util.c
linked-list.o: linked-list.c util.h
	$(COMPILER) $(CCFLAGS) -c linked-list.c

ifeq ($(DEBUG), TRUE)
	CCFLAGS += -g
endif

clean:
	rm -f shell
	rm -f *.o
