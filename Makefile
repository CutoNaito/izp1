CC = zig cc

CFLAGS = -std=c11 -Wall -Wextra -Werror

TARGET = bin/keyfilter

SRC = $(wildcard src/*.c)

$(TARGET): $(SRC)
	$(CC) $^ -o $@ $(CFLAGS)
