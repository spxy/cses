*.cc: clean
	c++ -g -std=c++20 -Wall -Wextra -pedantic "$@" 2>&1
	sh test/test.sh "$@"
	make clean
	clang-format "$@" > formatted.cc
	diff -u "$@" formatted.cc
	clang-tidy "$@" -- -std=c++20

clean:
	rm -f *.out formatted.cc out.txt input.txt expected.txt actual.txt error.diff time.txt
	rm -rf a.out.dSYM/

dep:
	brew install llvm

chk: chk-format chk-tidy

chk-format:
	find . -name "*.cc" | while read -r f; do \
	echo "Running clang-format on $$f ..."; \
	clang-format "$$f" > formatted.cc; \
	diff -u "$$f" formatted.cc || exit 1; done

chk-tidy:
	find . -name "*.cc" | while read -r f; do \
	echo "Running clang-tidy on $$f ..."; \
	clang-tidy "$$f" -- -std=c++20 || exit 1; done

fix-format:
	clang-format -i *.cc

fix-tidy:
	clang-tidy --fix --fix-errors --fix-notes *.cc -- -std=c++20

fix: fix-format fix-tidy

print-format-config-default:
	clang-format --style=llvm --dump-config | less

print-format-config-current:
	clang-format --dump-config | less

print-tidy-config-default:
	clang-tidy --config= --dump-config | less

print-tidy-config-all:
	clang-tidy --config= --checks='*' --dump-config | less

print-tidy-config-current:
	clang-tidy --dump-config | less

print-tidy-checks-default:
	clang-tidy --config= --list-checks | less

print-tidy-checks-all:
	clang-tidy --checks='*' --list-checks | less

print-tidy-checks-current:
	clang-tidy --list-checks | less
