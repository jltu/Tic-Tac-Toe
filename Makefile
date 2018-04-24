graphics: src/Graphics.cpp include/SFML/Graphics.hpp
	g++ -c src/Graphics.cpp -I"./lib/" -o src/Graphics.o
	g++ src/Graphics.o -I"./lib/" -o graphics -lsfml-graphics -lsfml-window -lsfml-system
