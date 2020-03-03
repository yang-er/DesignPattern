//
// Created by tlylz on 2019/10/7.
//

#include "mapmgr.h"
#include "mapbuilder.h"
#include "mapdirector.h"

MapMgr* MapMgr::getMgr()
{
    if (mgr == nullptr)
        mgr = new MapMgr;
    return mgr;
}

MapMgr* MapMgr::mgr;

void MapMgr::releaseMgr()
{
    delete mgr;
    mgr = nullptr;
}

MapMgr::MapMgr() = default;

MapMgr::~MapMgr()
{
    delete curMap;
}

void MapMgr::createMap()
{
    delete curMap;
    curMap = nullptr;

    //MapBuilder* builder = new MapBuilder;
    //MapDirector* director = new MapDirector(builder);
    MapBuilder* builder = new EFMapBuilder;
    MapDirector* director = new SunMapDirector(builder);

    director->makeMap();
    curMap = director->getMap();
    delete director;
    delete builder;


    /**
    curMap = new Map;

    int layout[BlockID::BLOCK_ROWS][BlockID::BLOCK_COLS] = {
        {1, 1, 1, 1, 1},
        {2, 0, 0, 0, 2},
        {3, 0, 0, 0, 3},
        {4, 0, 0, 0, 4},
        {1, 1, 1, 1, 1}
    };

    BlockFactory* blockFac  = new BlockFactory;
    for(int r = 0; r < BlockID::BLOCK_ROWS; ++r) {
        for(int c = 0; c < BlockID::BLOCK_COLS; ++c) {
            curMap->setBlock(r, c, blockFac->createBlock(layout[r][c]));
        }
    }
    delete blockFac;
    **/
}
