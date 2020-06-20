CC = gcc
src = $(wildcard src/*.c)
obj = $(src:.c=.o)

LDFLAGS = -m32  -Wall -O2 -I./include/
csnake: $(obj)
	$(CXX) -s $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(LDFLAGS) -c $< -o $@

clean: 
	rm -f $(obj) csnake
