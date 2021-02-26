1 : build/main.o build/sort_counting.o
	mkdir bin
	gcc -Wall -Werror build/main.o build/sort_counting.o -o bin/app

2 : build/main.o build/sort_insertion.o
	mkdir bin
	gcc -Wall -Werror build/main.o build/sort_insertion.o -o bin/app

3 : build/main.o build/sort_merge.o
	mkdir bin
	gcc -Wall -Werror build/main.o build/sort_merge.o -o bin/app

build/main.o: src/main.c
	mkdir build
	gcc -Wall -Werror -I include -c src/main.c -o build/main.o

build/sort_counting.o: src/sort_counting.c
	gcc -Wall -Werror -I include -c src/sort_counting.c -o build/sort_counting.o

build/sort_insertion.o: src/sort_insertion.c
	gcc -Wall -Werror -I include -c src/sort_insertion.c -o build/sort_insertion.o

build/sort_merge.o: src/sort_merge.c
	gcc -Wall -Werror -I include -c src/sort_merge.c -o build/sort_merge.o

clean:
	rm -rf bin/ build/

run:
	./bin/app

.PHONY: 1 2 3 clean run
