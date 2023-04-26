CFLAGS =gcc -Wall -Wextra -Werror -std=c11
GCOVFLAGS = --coverage 

ifeq ($(shell uname -s), Linux)	
	LFLAG += -lpthread -lrt -lm -lsubunit
endif

all: gcov_report

s21_math.a:
	gcc -Wall -Wextra -Werror -std=c11 -c s21_*.c
	ar rc s21_math.a s21_*.o
	ranlib s21_math.a

test: s21_math.a 
	gcc TEST.c -o test s21_math.a -lcheck $(LFLAG)
	./test

gcov_report:	
	gcc s21_*.c TEST.c -lcheck -o gcov_report --coverage $(LFLAG)
	./gcov_report
	rm -rf *TEST*.gc*
	gcov *s21_*.c 
	lcov -d . -o gcov_report.info -c
	genhtml -o report gcov_report.info
	open report/index.html

check:
	clang-format -style=Google -i *.c
	clang-format -style=Google -n *.c

leak_style: test
	leaks -atExit -- ./test
	clang-format -n -style=Google *s21_*.c TEST.c

rebuild: clean all

clean:
	rm -f *.gcno *.gcda *.info *.gcov 
	rm -f *.o *.a
	rm -rf report
	rm -f *.out
	rm -rf test
	rm -f gcov_report

