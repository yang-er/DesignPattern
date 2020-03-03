///======================================================================
///  Project:   Richer01
/// FileName:	mapdirector.cpp
///     Desc:   Richer 01
///   Author:	Chen Wei
///======================================================================
#include "global.h"
#include "map.h"
#include "block.h"
#include "mapbuilder.h"
#include "mapdirector.h"

MapDirector::MapDirector(MapBuilder* aBuilder)
    : builder(aBuilder)
{
    //ctor
}

MapDirector::~MapDirector()
{
    //dtor
}

Map* __inner_make_map(int layout[BlockID::BLOCK_ROWS][BlockID::BLOCK_COLS], MapBuilder *builder)
{
    Block *contents[BlockID::BLOCK_ROWS][BlockID::BLOCK_COLS];
    for (int r = 0; r < BlockID::BLOCK_ROWS; r++)
        for (int c = 0; c < BlockID::BLOCK_COLS; c++)
            contents[r][c] = builder->buildBlock(layout[r][c]);

    #define isok(r,c) (r >= 0 && r < BlockID::BLOCK_ROWS && c >= 0 && c < BlockID::BLOCK_COLS)

    for (int r = 0; r < BlockID::BLOCK_ROWS; r++) {
        for (int c = 0; c < BlockID::BLOCK_COLS; c++) {
            contents[r][c]->setPosition(r, c);
            contents[r][c]->up = isok(r-1,c) ? contents[r-1][c] : nullptr;
            contents[r][c]->down = isok(r+1,c) ? contents[r+1][c] : nullptr;
            contents[r][c]->left = isok(r,c-1) ? contents[r][c-1] : nullptr;
            contents[r][c]->right = isok(r,c+1) ? contents[r][c+1] : nullptr;
        }
    }

    #undef isok

    Map *aMap = new Map(new MapImpl);
    for (int r = 0; r < BlockID::BLOCK_ROWS; ++r)
        for (int c = 0; c < BlockID::BLOCK_COLS; ++c)
            aMap->addBlock(contents[r][c]);
    return aMap;
}

void MapDirector::makeMap()
{
    int layout[BlockID::BLOCK_ROWS][BlockID::BLOCK_COLS] = {
        {1, 1, 1, 1, 1},
        {2, 0, 0, 0, 2},
        {3, 0, 0, 0, 3},
        {4, 0, 0, 0, 4},
        {1, 1, 1, 1, 1}
    };

    aMap = __inner_make_map(layout, builder);
}

Map* MapDirector::getMap()
{
    return aMap;
}
///-----------------------------------------
SunMapDirector::SunMapDirector(MapBuilder* aBuilder)
    : MapDirector(aBuilder)
{
}

void SunMapDirector::makeMap()
{
    int layout[BlockID::BLOCK_ROWS][BlockID::BLOCK_COLS] = {
        {1, 1, 1, 1, 1},
        {2, 0, 0, 0, 2},
        {3, 3, 3, 3, 3},
        {4, 0, 0, 0, 4},
        {1, 1, 1, 1, 1}
    };

    aMap = __inner_make_map(layout, builder);
}

