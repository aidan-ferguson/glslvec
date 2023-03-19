test: tests include
	clang++ -Iinclude -std=c++17 -o test.out tests/main.cpp
	./test.out
	
install:
	echo todo