///======================================================================
///  Project:   Richer01
/// FileName:	map.cpp
///     Desc:   Richer 01
///   Author:	Chen Wei
///======================================================================
#include <iostream>
using namespace std;
#include "global.h"
#include "block.h"
#include "map.h"

MapImpl::MapImpl() = default;

MapImpl::~MapImpl()
{
    for (auto t : blocks) delete t;
}

void MapImpl::addBlock(Block *block)
{
    blocks.push_back(block);
}

Block* MapImpl::getBlock(int index)
{
    return blocks[index];
}

void MapImpl::show() const
{
    cout << endl;
    for (auto block : blocks)
    {
        if (!block) continue;
        cout << block->name() << " ";
    }
    cout << endl;
}

void Map::show() const
{
    return core->show();
}

Block* Map::getBlock(int index)
{
    return core->getBlock(index);
}

void Map::addBlock(Block *block)
{
    core->addBlock(block);
}

Map::Map(MapImpl *impl)
{
    core = impl;
}

Map::~Map()
{
    delete core;
}
