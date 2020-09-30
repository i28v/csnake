CC = gcc
src = $(wildcard src/*.c)
obj = $(src:%.c=obj/%.o)

LDFLAGS =-s
CFLAGS=-Wall -O2
csnake: $(obj)
	$(CC) $(LDFLAGS) -s -o $@ $^

%.o: %.c
	$(CC) $(LDFLAGS) -c $< -o $@

clean: 
	rm -f $(obj) csnake
