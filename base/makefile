mainClass: main.o
	g++ main.o -o mainClass
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm -f *.o
	rm mainClass
run: mainClass
	./mainClass
