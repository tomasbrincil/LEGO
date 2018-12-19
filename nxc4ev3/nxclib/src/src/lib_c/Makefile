## Copyright (c) 2015 Ahmad Fatoum
## Copyright (c) 2017 Faculty of Electrical Engineering, CTU in Prague
PREFIX ?= 
CC = $(PREFIX)gcc
AR = $(PREFIX)ar
SRCS = $(wildcard impl/*.c)
OBJS = $(patsubst %.c,%.o,$(SRCS))

.DEFAULT: nxclib.a
nxclib.a: $(OBJS)
	$(AR) rcs $@ $^
	
%.o: %.c
	$(CC) -Os -std=gnu99 -pthread -isystem ./include -isystem ../native/include -c $< -o $@

.PHONY: clean
clean:
	$(RM) impl/*.o impl/*.d *.a
