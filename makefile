test_val_build:
	gcc -g -O0 test_string.c -o test.out

test_valgrind: test_val_build
	valgrind --leak-check=full --track-origins=yes ./test.out

clean:
	rm -f test.out


