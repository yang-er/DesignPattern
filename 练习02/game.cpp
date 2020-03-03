///======================================================================
///  Project:   Richer01
/// FileName:	game.cpp
///     Desc:   Richer 01
///   Author:	Chen Wei
///======================================================================
#include "global.h"

#include "game.h"
#include "menu.h"
#include "menumgr.h"
#include "menufactory.h"
#include "blockfactory.h"
#include "map.h"
#include "mapbuilder.h"
#include "mapdirector.h"
#include "blockmgr.h"
#include "mapmgr.h"

Game* Game::game = nullptr;

Game* Game::getGame()
{
    if(game == nullptr) {
        game = new Game;
    }
    return game;
}

void  Game::releaseGame()
{
    delete game;
    game = nullptr;
}

void Game::init()
{
    mnuMgr = MenuMgr::getMgr();
    mnuMgr->setMenuFactory(new MenuFactory);
    mnuMgr->setCurMenu(MenuID::MAIN_MENU);
    mapMgr = MapMgr::getMgr();
    mapMgr->createMap();
}

void Game::run()
{
    bool running = true;
    while(running) {
        running = MenuMgr::getMgr()->getCurMenu()->process();
    }
}

void Game::term()
{
    MapMgr::releaseMgr();
    MenuMgr::releaseMgr();
    BlockMgr::releaseMgr();
}
