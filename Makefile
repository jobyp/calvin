# Skip anything that starts with lib%..
PROGS:=$(filter-out lib%,$(patsubst %.c,%,$(wildcard *.c)))
CC:=gcc
# -pthread
CFLAGS:=-D_GNU_SOURCE -D_FORTIFY_SOURCE=2 -g -c -O2 -std=gnu99
# -pthread -lm
LDFLAGS:=

.PHONY: all
all: $(PROGS)
	@:

# Cancel the default rule for building 'foo' from 'foo.c'
% : %.c

%.o : %.c lib.h
	$(CC) -Wall $(CFLAGS) -o $@ $<

% : %.o lib.o
	$(CC) -Wall -o $@ $^ $(LDFLAGS)

.SECONDARY: lib.o

.PHONY: clean
clean:
	rm -vf $(PROGS) *~ *.o *.ps *.class


# Question: If intermediate files are automatically deleted,
#           how is that Make knows to build 'bst' when 'bst.c' is updated?
