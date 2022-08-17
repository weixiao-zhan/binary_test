CXX = g++
CFLAGS = -Og -g
#CFLAGS = -O1 -g
#CFLAGS = -O2 -g
#CFLAGS = -O3 -g
#CFLAGS = -static -Og -g

main: main.o throw.o exception.o
	$(CXX) $(CFLAGS) main.o throw.o exception.o -o test_cfg

exception.o: exception.cpp
	$(CXX) $(CFLAGS) -c exception.cpp

throw.o: throw.cpp
	$(CXX) $(CFLAGS) -c throw.cpp

main.o: main.cpp
	$(CXX) $(CFLAGS) -c main.cpp

clean:
	rm -f *.o test
