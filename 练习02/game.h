///======================================================================
///  Project:   Richer01
/// FileName:	game.h
///     Desc:
///   Author:	Chen Wei
///  History:
///======================================================================
#ifndef GAME_H
#define GAME_H

class MenuMgr;
class MapMgr;

class Game
{
public:
    static Game* getGame();
    static void  releaseGame();
private:
    static Game* game;
private:
    Game() { }
    Game(const Game&);
    Game& operator=(const Game&);
public:
    void init();
    void run();
    void term();
private:
    MenuMgr* mnuMgr = nullptr;
    MapMgr* mapMgr = nullptr;
};

#endif // GAME_H
