LIBS=-lsfml-graphics -lsfml-window -lsfml-system


main: main.o
	g++ main.o -o main $(LIBS)

main.o: main.cpp
	g++ -c main.cpp -o main.o

clean: *.o
	rm *.o
