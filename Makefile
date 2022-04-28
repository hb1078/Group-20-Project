main: main.o book.o accounts.o
	g++ main.o book.o accounts.o -o main

book.o: book.cpp book.h
	g++ -c book.cpp

accounts.o: accounts.cpp accounts.h
	g++ -c accounts.cpp

main.o: main.cpp book.h accounts.h
	g++ -c main.cpp

clean:
	rm *.o main