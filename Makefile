LIBS=-lsfml-graphics -lsfml-window -lsfml-system

main: main.o game_logic.o Board.o
	g++ main.o game_logic.o Board.o -o main $(LIBS)

game_logic.o: game_logic.hpp

Board.o: Board.hpp

# source file dependencies

#class.o: class.hpp

#class2.o: class2.hpp

clean: *.o
	rm *.o
