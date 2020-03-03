///======================================================================
///  Project:   Richer01
/// FileName:	blockfactory.cpp
///     Desc:   Richer 01
///   Author:	Chen Wei
///======================================================================
#include "global.h"
#include "block.h"
#include "blockfactory.h"

BlockFactory::BlockFactory()
{
    //ctor
}

BlockFactory::~BlockFactory()
{
    //dtor
}
Block* BlockFactory::createBlock(int blockID)
{
    if(blockID == BlockID::MONEY_BLOCK) {
        return new MoneyBlock;
    } else if(blockID == BlockID::TRIP_BLOCK) {
        return new TripBlock;
    } else if(blockID == BlockID::BAR_BLOCK) {
        return new BarBlock;
    } else if(blockID == BlockID::SLIDE_BLOCK) {
        return new SlideBlock;
    } else {
        return nullptr;
    }
}
