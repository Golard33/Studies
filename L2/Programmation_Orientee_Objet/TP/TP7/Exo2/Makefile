CXX=g++
CXXFLAGS=-std=c++98 -pedantic -Wall -Werror -g
LDFLAGS=
LDLIBS=
RM=rm -fv
all: main.out
book.o: book.cpp book.h
	$(CXX) $(CXXFLAGS) -c -o book.o book.cpp
library.o: library.cpp library.h
	$(CXX) $(CXXFLAGS) -c -o library.o library.cpp
main.out : main.cpp book.o library.o
	$(CXX) $(CXXFLAGS) -o main.out main.cpp book.o library.o $(LDFLAGS) $(LDLIBS)
clean:
	$(RM) *.o *.out