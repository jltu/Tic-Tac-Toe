LIBS=-lsfml-graphics -lsfml-window -lsfml-system


main: main.o
	g++ main.o -o main $(LIBS)





clean: *.o
	rm *.o
