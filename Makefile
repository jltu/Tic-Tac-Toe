LIBS=-lsfml-graphics -lsfml-window -lsfml-system


main: main.o
	g++ main.o -o main $(LIBS)

main.o: main.cpp
	g++ -c main.cpp -o main.o



test: test.o
	g++ test.o -o test $(LIBS)

test.o: test.cpp
	g++ -c test.cpp -o test.o





clean: *.o
	rm *.o
