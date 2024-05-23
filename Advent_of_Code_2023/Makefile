MAIN = main.o
DOCTEST = doctest.o
CXXFLAGS= -g3
LDFLAGS=
CXX = g++
main: $(MAIN)
	$(CXX) -g -o main $(MAIN)

doctest: $(DOCTEST)
	$(CXX) -g -o doctest $(DOCTEST)

main.o: main.cpp Aoc.h 

doctest.o: doctest.cpp doctest.h Aoc.h

clean:
	rm -f $(DOCTEST) $(MAIN)