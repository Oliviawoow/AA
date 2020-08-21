CC = g++
CFLAGS = -Wall -Wextra -O2
LDLIBS = -lm

build: algo.o

algo.o: algo1.cpp algo2.cpp algo3.cpp
	g++ algo1.cpp -c $(CFLAGS)
	gcc algo2.cpp -c $(CFLAGS)
	g++ algo3.cpp -c $(CFLAGS)

.PHONY: clean
clean:
	rm -rf *.o