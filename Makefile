LIBS=-lsfml-graphics -lsfml-window -lsfml-system


main: main.o
	g++ main.o -o main $(LIBS)

main.o: main.cpp
	g++ -c main.cpp -o main.o



test: /tst/test.o
	g++ tst/test.o -o test $(LIBS)

test.o: /tst/test.cpp
	g++ -c tst/test.cpp -o /tst/test.o





clean: *.o
	rm *.o
