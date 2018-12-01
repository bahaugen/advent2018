CC = g++
CFLAGS = -g -Wall -o3 -std=c++11

EXES = aoc1

all: $(EXES)

aoc1: aoc1.cpp
	$(CC) $(CFLAGS) -o $@ $< 

.PHONY: clean

clean:
	rm -f $(EXES) *.o