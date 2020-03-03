///======================================================================
///  Project:   Richer01
/// FileName:	blockprototype.cpp
///     Desc:   Richer 01
///   Author:	Chen Wei
///======================================================================
#include "global.h"
#include "block.h"
#include "blockprototype.h"

BlockPrototype::BlockPrototype()
{
    //ctor
    prototypes[BlockID::NONE_BLOCK] = nullptr;
    prototypes[BlockID::MONEY_BLOCK] = new MoneyBlock;
    prototypes[BlockID::TRIP_BLOCK] = new TripBlock;
    prototypes[BlockID::BAR_BLOCK] = new BarBlock;
    prototypes[BlockID::SLIDE_BLOCK] = new SlideBlock;
}

BlockPrototype::~BlockPrototype()
{
    //dtor
    for(int i = 0; i < BlockID::BLOCK_COUNT; ++i) {
        delete prototypes[i];
    }
}
Block* BlockPrototype::cloneBlock(int blockID)
{
    return prototypes[blockID]->clone();
}
