## Copyright (c) 2015 Ahmad Fatoum
PREFIX ?= 
CC = $(PREFIX)gcc
AR = $(PREFIX)ar
SRCS = $(wildcard impl/*.c)
OBJS = $(patsubst %.c,%.o,$(SRCS))

.DEFAULT: libev3api.a
libev3api.a: $(OBJS)
	$(AR) rcs $@ $^
	
%.o: %.c
	$(CC) -Os -std=gnu99 -isystem ./include -c $< -o $@

.PHONY: clean
clean:
	$(RM) impl/*.o impl/*.d *.a
