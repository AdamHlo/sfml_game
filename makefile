all: game

game: src/main.cpp src/loop.cpp src/handler.cpp src/gameTable.cpp src/gameObject.cpp
	g++ -c -g src/main.cpp src/loop.cpp src/handler.cpp src/gameTable.cpp src/gameObject.cpp
	g++ main.o loop.o handler.o gameTable.o gameObject.o -o game -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

clean:
	rm *.o
