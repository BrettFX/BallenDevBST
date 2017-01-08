all: Driver.o BallenDevBST.o
	g++ -Wall Driver.o BallenDevBST.o -o output.out

BallenDevBST.o: BallenDevBST.cpp
	g++ -Wall -c BallenDevBST.cpp
	
Driver.o: Driver.cpp
	g++ -Wall -c Driver.cpp

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~*.h.gch *#[

run:
	./output.out
