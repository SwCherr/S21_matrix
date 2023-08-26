CC=gcc
FLAGS=-Wall -Wextra -Werror
LIBS=-lm -lcheck

SRC=$(wildcard *.c)
# OBJ=$(patsubst %.c,%.o,$(SRC))

TEST_SRC=$(wildcard ./tests/*.c)
# TEST_OBJ=$(patsubst %.c,%.o,$(TEST_SRC))

all: clean s21_matrix.a test

s21_matrix.a:
	@$(CC) $(CFLAGS) $(GCOV_FLAGS) $(SRC) -c
	ar rc s21_matrix.a *.o
	ranlib s21_matrix.a

test:
	@$(CC) $(CFLAGS) $(det_OS) --coverage $(SOURCE_TESTS_FUNC) s21_matrix.a -o s21_test_matrix
	./s21_test_matrix

gcov_report:
	@lcov -t "s21_test_matrix" -o test.info --no-external -c -d .
	@genhtml -o report test.info
	open report/index.html
	rm -rf *.gcno *gcda *.gco

clean:
	rm -rf *.a
	rm -rf *.o
	rm -rf function_files/*.o
	rm -rf function_files/*.gcda
	rm -rf function_files/*.gcno
	rm -rf tests/*.o
	rm -rf tests/*.gcda
	rm -rf tests/*.gcno
	rm -rf a.out
	rm -rf *.dSYM
	rm -rf *.out
	rm -rf test
	rm -rf main
	rm -rf gcov_report
	rm -rf *.info
	rm -rf *.gcda
	rm -rf *.gcno

# gcov_report: GCOVFLAGS = -lcheck --coverage
# gcov_report: DEBUGFLAGS = -g
# gcov_report: test
# gcov_report:
# 	geninfo ./ -b ./ -o ./coverage.info
# 	genhtml coverage.info -o gcov_report
# 	xdg-open gcov_report/index.html


style:
	clang-format -n -style=google *.h *.c $(TEST_SRC)
	@rm -rf .clang-format

style_repair:
	@cp ../materials/linters/.clang-format ../src  
	@clang-format -i -style=google *.h *.c $(TEST_SRC)

leaks:
	leaks -atExit -- ./test

install_brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install lcov
