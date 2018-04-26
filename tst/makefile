LIBS=-lsfml-graphics -lsfml-window -lsfml-system



test: /tst/test.o
	g++ tst/test.o -o test $(LIBS)

test.o: /tst/test.cpp
	g++ -c tst/test.cpp -o /tst/test.o





clean: *.o
	rm *.o
