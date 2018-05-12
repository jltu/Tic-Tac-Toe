LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

main: main.o game_logic.o Board.o Piece.o Texts.o Title.o Button.o
	g++ -std=c++11  main.o game_logic.o Board.o Piece.o Texts.o Title.o Button.o -o main $(LIBS)

game_logic.o: game_logic.hpp

Board.o: Board.hpp

Piece.o: Piece.hpp

Texts.o: Texts.hpp

Title.o: Title.hpp

Button.o: Button.hpp

# source file dependencies

#class.o: class.hpp

#class2.o: class2.hpp

clean: *.o
	rm *.o
