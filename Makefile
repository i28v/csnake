CC = gcc
src = $(wildcard src/*.c)
obj = $(src:%.c=obj/%.o)

LDFLAGS =-s
CFLAGS=-Wall -O2 -I/include/
csnake: $(obj)
	$(CC) $(LDFLAGS) -s -o $@ $^

%.o: %.c
	$(CC) $(C) -c $< -o $@

clean: 
	rm -f $(obj) csnake
