book_test: book_test.o book.o
	g++ book_test.o book.o -o book_test

book.o: book.cpp book.h
	g++ -c book.cpp -o book.o

book_test.o: book_test.cpp book.h
	g++ -c book_test.cpp -o book_test.o

clean:
	rm *.o book_test