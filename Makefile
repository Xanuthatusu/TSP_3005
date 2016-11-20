CXXFLAGS := -std=c++11 -Wall -Werror

all: run

unittest: compile
	valgrind --leak-check=full --track-fds=yes --log-file=valgrind.log ./TSP
	cat valgrind.log

run: compile
	./TSP < tsp-samples/graph005.txt

compile: main.cpp tsp.o
	g++ $(CXXFLAGS) -o TSP $^

tsp.o: tsp.cpp tsp.h
	g++ $(CXXFLAGS) -c $<

clean:
	rm -f *.o *~

spotless: clean
	rm -f tsp
	rm -rf *.dSYM

