EXEC=netpbm_gs2hm
SRC=main.c
CFLAGS=-W -Wall -Wextra -O2
LDFLAGS=-lm

all:
	$(CC) -o $(EXEC) $(CFLAGS) $(LDFLAGS) $(SRC)
