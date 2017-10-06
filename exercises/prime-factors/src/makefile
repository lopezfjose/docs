
CC := gcc

CFLAGS := -std=c99 -Wall -Wextra -Wpedantic -Werror

SRCS := $(wildcard *.c)
OBJS := $(patsubst %.c,%.o,$(SRCS))

PROGRAM := test.exe

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) -o $(PROGRAM) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	rm -rf $(OBJS) $(PROGRAM)