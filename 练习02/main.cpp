#include <iostream>
#include "game.h"

int main()
{
    Game *t = Game::getGame();
    t->init();
    t->run();
    t->term();
    t->releaseGame();
    return 0;
}