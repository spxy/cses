*.cc: clean
	c++ -g -std=c++20 -Wall -Wextra -pedantic "$@" 2>&1
	sh test/test.sh "$@"
	make clean

clean:
	rm -rf *.out input.txt expect.txt actual.txt
