LIBS=-lsfml-graphics -lsfml-window -lsfml-system

main: main.o
	g++ main.o -o main $(LIBS)

##main template with OOP classes
#main: main.o class.o class2.o
	#g++ main.o class.o class2.o -o main $(LIBS)

# source file dependencies

#class.o: class.hpp

#class2.o: class2.hpp

clean: *.o
	rm *.o
