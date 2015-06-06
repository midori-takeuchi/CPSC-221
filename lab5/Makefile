all: main.cc Minheap.o Unit.o 
	g++ -Wall -g main.cc Minheap.o Unit.o -o minheap

Minheap.o : Minheap.cc Minheap.h  
	g++ -Wall -c Minheap.cc -o Minheap.o 

Unit.o : Unit.cc Unit.h  
	g++ -Wall -c Unit.cc -o Unit.o 

clean:
	rm -f Minheap.o 
	rm -f Unit.o 
	rm -f minheap 
	rm -f example 
	rm -fr minheap.dSYM/* 
	rmdir minheap.dSYM 
