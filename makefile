driver: main.o test_bst.o
	g++ -o usecase main.o
	g++ -o test test_bst.o

main.o: main.cpp usecase.cpp bst.h bst.cpp
	g++ -c main.cpp

test_hash_table.o: test_bst.cpp bst.h bst.cpp
	g++ -c test_bst.cpp
