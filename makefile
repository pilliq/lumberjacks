COMPILER = gcc
CCFLAGS  = -ansi -pedantic -Wall
all: shell

debug:
	make DEBUG=TRUE

shell: shell.o linked-list.o
	$(COMPILER) $(CCFLAGS) -o shell shell.o linked-list.o
shell.o: linked-list.c linked-list.h
	$(COMPILER) $(CCFLAGS) -c shell.c
linked-list.o: linked-list.c linked-list.h
	$(COMPILER) $(CCFLAGS) -c linked-list.c


ifeq ($(DEBUG), TRUE)
	CCFLAGS += -g
endif

clean:
	rm -f shell
	rm -f *.o
