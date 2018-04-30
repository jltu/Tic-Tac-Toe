LIBS=-lsfml-graphics -lsfml-window -lsfml-system

main: main.o game_logic.o
	g++ main.o game_logic.o -o main $(LIBS)

game_logic.o: game_logic.hpp

# source file dependencies

#class.o: class.hpp

#class2.o: class2.hpp

clean: *.o
	rm *.o
