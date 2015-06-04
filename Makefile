EXEC=netpbm_gs2hm
SRC=main.c
CFLAGS=-W -Wall -Wextra -O2 -ansi -pedantic
LDFLAGS=-lm

.PHONY: clean

all:
	$(CC) -o $(EXEC) $(CFLAGS) $(LDFLAGS) $(SRC)

clean:
	rm -vf $(EXEC)
