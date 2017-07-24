CC=gcc
CFLAGS=-Wall -g
TARG=ttt
OBJS=ttt.o lib.o
HDRS=defs.h


$(TARG): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARG) $(OBJS)

$(OBJS): $(HDRS)

.PHONY: clean
clean:
	rm -v $(TARG) $(OBJS)
