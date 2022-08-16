CXX = gcc
#CFLAGS = -static -Og  -g
#CFLAGS = -O1 -g
#CFLAGS = -O2 -g
CFLAGS = -O3 -g


all: test

test: test.o indirect.o nonret.o tailcalls.o data.o
	$(CXX) $(CFLAGS) test.o indirect.o nonret.o tailcalls.o data.o -o test

indirect.o: indirect.c
	$(CXX) $(CFLAGS) -c indirect.c  

nonret.o: nonret.c
	$(CXX) $(CFLAGS) -c nonret.c 

tailcalls.o: tailcalls.c
	$(CXX) $(CFLAGS) -c tailcalls.c

data.o : data.c
	$(CXX) $(CFLAGS) -c data.c

test.o: test.c
	$(CXX) $(CFLAGS) -c test.c

clean:
	rm -f *.o test
