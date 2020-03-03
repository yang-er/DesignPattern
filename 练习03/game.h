///======================================================================
///  Project:   Richer01
/// FileName:	game.h
///     Desc:
///   Author:	Chen Wei
///  History:
///======================================================================
#ifndef GAME_H
#define GAME_H

class Menu;
class Map;
//class MenuMgr;

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
public:
    void setCurMenu(int menuID);
    Map * getCurMap() { return curMap;}
//private:
    void createMap();
private:
    Menu* curMenu = nullptr;
    //MenuMgr* mnuMgr = nullptr;
    Map* curMap = nullptr;
};

#endif // GAME_H
