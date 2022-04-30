main: main.o cart.o book.o accounts.o
	g++ main.o cart.o book.o accounts.o -o main

book.o: book.cpp book.h
	g++ -c book.cpp

accounts.o: accounts.cpp accounts.h
	g++ -c accounts.cpp

cart.o: cart.cpp cart.h book.h
	g++ -c cart.cpp

main.o: main.cpp cart.h book.h accounts.h
	g++ -c main.cpp

clean:
	rm *.o main