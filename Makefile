run:build
	./program

huffman_tree.o:huffman_tree.cpp huffman_tree.h
	g++ -c huffman_tree.cpp 
main.o:main.cpp
	g++ -c main.cpp

build:huffman_tree.o main.o
	g++ *.o -o program

clean:
	rm program *.o

