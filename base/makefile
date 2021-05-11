orbitCal: moon.o body.o user.o main.o
	g++ moon.o body.o user.o main.o -o orbitCal
moon.o: moon.cpp moon.h
	g++ -c moon.cpp
body.o: body.cpp body.h
	g++ -c body.cpp
user.o: user.cpp user.h
	g++ -c user.cpp
main.o: main.cpp user.h
	g++ -c main.cpp
clean:
	rm -f *.o
	rm orbitalCal
run: orbitalCal
	./orbitalCal
