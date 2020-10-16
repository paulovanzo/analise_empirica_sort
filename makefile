# makefile selection sort

all:
	mkdir -p bin
	g++ -Wall -c src/selection_sort.cpp -o bin/selection_sort.o
	g++ -Wall -c src/merge_sort.cpp -o bin/merge_sort.o
	g++ -Wall -c src/bubble_sort.cpp -o bin/bubble_sort.o
	g++ -Wall -c src/rand.cpp -o bin/rand.o

	g++ -Wall src/main.cpp bin/rand.o bin/selection_sort.o bin/merge_sort.o bin/bubble_sort.o -o bin/main
run:
	./bin/main