CXX = gcc
#CFLAGS = -static -Og  -g
#CFLAGS = -O1 -g
#CFLAGS = -O2 -g
CFLAGS = -O3 -g


all: main

main: main.o indirect.o nonret.o tailcalls.o data.o
	$(CXX) $(CFLAGS) main.o indirect.o nonret.o tailcalls.o data.o -o test

indirect.o: indirect.c
	$(CXX) $(CFLAGS) -c indirect.c  

nonret.o: nonret.c
	$(CXX) $(CFLAGS) -c nonret.c 

tailcalls.o: tailcalls.c
	$(CXX) $(CFLAGS) -c tailcalls.c

data.o : data.c
	$(CXX) $(CFLAGS) -c data.c

main.o: main.c
	$(CXX) $(CFLAGS) -c main.c

clean:
	rm -f *.o main
