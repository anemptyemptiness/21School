CC=gcc
CFLAGS=-Wall -Werror -Wextra
SOURCES=main.c s21_grep.c
all: s21_grep

s21_grep:
	$(CC) $(CFLAGS) $(SOURCES) -o s21_grep

clean: 
	rm s21_grep

rebuild: clean all