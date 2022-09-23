all: way_home

FLAGS := -std=c11 -Wall -Wextra -Werror -Wpedantic -Iinc

way_home:
	clang $(FLAGS) -o way_home src/*.c

clean:
	rm -rf way_home

uninstall:
	rm -rf way_home

reinstall:
	make uninstall
	make

