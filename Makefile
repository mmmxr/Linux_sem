
test:comm.c test.c
	gcc -o $@ $^

.PHONY:clean
clean:
	rm -rf test
