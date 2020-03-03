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

Map::Map()
{
    //ctor
    for(int r = 0; r < BlockID::BLOCK_ROWS; ++r) {
        for(int c = 0; c < BlockID::BLOCK_COLS; ++c) {
            blocks[r][c] = nullptr;
        }
    }
}

Map::~Map()
{
    //dtor
    for(int r = 0; r < BlockID::BLOCK_ROWS; ++r) {
        for(int c = 0; c < BlockID::BLOCK_COLS; ++c) {
            delete blocks[r][c];
        }
    }
}
void Map::setBlock(int r, int c, Block* block)
{
    blocks[r][c] = block;
}
void Map::show() const
{
    for(int r = 0; r < BlockID::BLOCK_ROWS; ++r) {
        cout << endl;
        for(int c = 0; c < BlockID::BLOCK_COLS; ++c) {
            Block* block = blocks[r][c];
            if(block) {
                cout << block->name() << " ";
            } else {
                cout << "  ";
            }
        }
    }
    cout << endl;
}
