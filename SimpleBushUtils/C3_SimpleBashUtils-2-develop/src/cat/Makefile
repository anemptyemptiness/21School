CC=gcc
CFLAGS=-Wall -Werror -Wextra
SOURCES=main.c cat.c parser.c
all: s21_cat

s21_cat:
	$(CC) $(CFLAGS) $(SOURCES) -o s21_cat

clean:
	rm s21_cat

rebuild: clean all
