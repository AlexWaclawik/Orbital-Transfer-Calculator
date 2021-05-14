mainClass: body.o main.o
	g++ body.o main.o -o mainClass
body.o: body.cpp body.h
	g++ -c body.cpp
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm -f *.o
	rm mainClass
run: mainClass
	./mainClass
