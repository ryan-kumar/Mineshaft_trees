CXX=clang++
CXX_FLAGS=-std=c++20 -g -fstandalone-debug -Iincludes -Wall -Wextra -Werror -fsanitize=address,null -fno-omit-frame-pointer -O0 -gdwarf-4

exec: bin/exec
tests: bin/tests

bin/exec: ./src/driver.cc ./src/mineshaft_tree.cc ./includes/mineshaft_tree.hpp 
	$(CXX) $(CXX_FLAGS) ./src/driver.cc ./src/mineshaft_tree.cc -o $@

bin/tests: ./tests/tests.cc ./src/mineshaft_tree.cc ./includes/mineshaft_tree.hpp 
	$(CXX) $(CXX_FLAGS) ./tests/tests.cc ./src/mineshaft_tree.cc -o $@

.DEFAULT_GOAL := exec
.PHONY: exec clean

clean:
	rm -rf bin/* 
