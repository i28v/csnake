CC = gcc
src = $(wildcard src/*.c)
obj = $(src:.c=.o)

LDFLAGS = -Wall -O2 -I./include/
csnake: $(obj)
	$(CC) $(LDFLAGS) -s -o $@ $^

%.o: %.c
	$(CC) $(LDFLAGS) -c $< -o $@

clean: 
	rm -f $(obj) csnake
