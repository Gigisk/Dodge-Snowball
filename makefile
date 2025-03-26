all: compile

compile:
    g++ main.cpp Game.cpp Player.cpp Snowball.cpp Heart.cpp Button.cpp -I/opt/homebrew/include -o app -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio

clean:
	 rm -f app *.o
