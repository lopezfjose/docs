
CC := gcc

CFLAGS = -std=c99 -Wall -Wextra -Wpedantic -Werror

test: tests.out
	@./tests.out

clean: rm -f *.o *.out

tests.out: test/test_prime_factors.c src/prime_factors.c src/prime_factors.h
	@echo Compiling $@
	$(CC) $(CFLAGS) src/prime_factors.c test/vendor/unity.c test/test_prime_factors.c -o tests.out