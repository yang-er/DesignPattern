///======================================================================
///  Project:   Richer01
/// FileName:	mapbuilder.cpp
///     Desc:   Richer 01
///   Author:	Chen Wei
///======================================================================
#include "global.h"
#include "block.h"
#include "mapbuilder.h"
#include "blockmgr.h"
MapBuilder::MapBuilder()
{
    //ctor
}

MapBuilder::~MapBuilder()
{
    //dtor
}
Block* MapBuilder::buildBlock(int blockID)
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
///-----------------------------------------
Block* EFMapBuilder::buildBlock(int blockID)
{
    return BlockMgr::getMgr()->cloneBlock(blockID);
}
