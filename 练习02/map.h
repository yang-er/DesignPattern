///======================================================================
///  Project:   Richer01
/// FileName:	map.h
///     Desc:   Richer 01
///   Author:	Chen Wei
///======================================================================
#ifndef MAP_H
#define MAP_H

#include "global.h"
#include <vector>

class Block;

class MapImpl
{
public:
    MapImpl();
    virtual ~MapImpl();
    virtual void show() const;
    void addBlock(Block *block);
    Block* getBlock(int index);

protected:
    std::vector<Block*> blocks;
};

class Map
{
public:
    Map(MapImpl *impl);
    ~Map();
    void show() const;
    void addBlock(Block * block);
    Block * getBlock(int index);

protected:
    MapImpl *core;
};

#endif // MAP_H
