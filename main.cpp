#include <iostream>
#include "Game.h"

int main(){
    //init Game object
    Game game;
    //game loop
    while (game.running())
    { 
        //update
        game.update();
        //render
        game.render();

    }
    return 0;
}