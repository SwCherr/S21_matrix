CC=gcc
FLAGS=-Wall -Wextra -Werror -std=c11 -g

OS = $(shell uname)
SRC=$(wildcard *.c)
TEST_SRC=$(wildcard ./tests/*.c)

ifeq ($(OS), Linux)
	GFLAGS = -lcheck -lpthread -lrt -lm -lsubunit
endif
ifeq ($(OS), Darwin)
	GFLAGS = -lcheck
	GCOV_FLAGS = -fprofile-arcs -ftest-coverage
endif

all: clean s21_matrix.a test

s21_matrix.a:
	@$(CC) $(FLAGS) $(GCOV_FLAGS) $(SRC) -c
	ar rc s21_matrix.a *.o
	ranlib s21_matrix.a
	@-rm -rf *.o

test: clean s21_matrix.a
	@$(CC) $(FLAGS) $(GFLAGS) $(TEST_SRC) $(GCOV_FLAGS) -L. s21_matrix.a -o test
	@./test

gcov_report:
	@lcov -t "s21_test_matrix" -o test.info --no-external -c -d .
	@genhtml -o report test.info
	open report/index.html
	rm -rf *.gcno *gcda *.gco

clean:
	@rm -rf *.a *.o
	@rm -rf function_files/*.o
	@rm -rf function_files/*.gcda
	@rm -rf function_files/*.gcno
	@rm -rf tests/*.o
	@rm -rf tests/*.gcda
	@rm -rf tests/*.gcno
	@rm -rf a.out
	@rm -rf *.dSYM report
	@rm -rf *.out
	@rm -rf test
	@rm -rf gcov_report
	@rm -rf *.info
	@rm -rf *.gcda
	@rm -rf *.gcno

style:
	clang-format -n -style=google *.h *.c $(TEST_SRC)
	@rm -rf .clang-format

style_repair:
	@cp ../materials/linters/.clang-format ../src  
	@clang-format -i -style=google *.h *.c $(TEST_SRC)

leaks:
	leaks -atExit -- ./s21_test_matrix

install_brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install lcov
