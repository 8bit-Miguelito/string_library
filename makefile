build_test:
	clang -c string.c
	clang -c test_string.c
	clang -g -Wall -Wextra -O1 -fsanitize=address,undefined -fno-omit-frame-pointer -o test.out string.o test_string.o

mac_leak_check:
	clang -c string.c
	clang -c test_string.c
	clang -g -Wall -Wextra -Wpedanctic -o test_nosan.out string.o test_string.o
	leaks --atExit -- ./test_nosan.out

mac_test_asan: build_test
	./test.out

test_pc: build_test
	ASAN_OPTIONS="detect_leaks=1" ./test.out

clean:
	rm -f *.out
	rm -f *.o






