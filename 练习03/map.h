///======================================================================
///  Project:   Richer01
/// FileName:	map.h
///     Desc:   Richer 01
///   Author:	Chen Wei
///======================================================================
#ifndef MAP_H
#define MAP_H

#include "global.h"

class Block;
class Map
{
public:
    Map();
    virtual ~Map();
    virtual void show() const;
    void setBlock(int r,int c,Block * block);
    Block * getBlock(int r,int c) { return blocks[r][c];}

protected:
    Block * blocks[BlockID::BLOCK_ROWS][BlockID::BLOCK_COLS];
};

#endif // MAP_H
