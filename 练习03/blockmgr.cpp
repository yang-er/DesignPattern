///======================================================================
///  Project:   Richer01
/// FileName:	blockmgr.cpp
///     Desc:   Richer 01
///   Author:	Chen Wei
///======================================================================
#include "global.h"
#include "block.h"
#include "blockmgr.h"

BlockMgr* BlockMgr::mgr = nullptr;

BlockMgr* BlockMgr::getMgr()
{
    if(mgr == nullptr) {
        mgr = new BlockMgr;
    }
    return mgr;
}
void BlockMgr::releaseMgr()
{
    delete mgr;
    mgr = nullptr;
}

BlockMgr::BlockMgr()
{
    prototypes[BlockID::NONE_BLOCK] = nullptr;
    prototypes[BlockID::MONEY_BLOCK] = new MoneyBlock;
    prototypes[BlockID::TRIP_BLOCK] = new TripBlock;
    prototypes[BlockID::BAR_BLOCK] = new BarBlock;
    prototypes[BlockID::SLIDE_BLOCK] = new SlideBlock;
}

BlockMgr::~BlockMgr()
{
    //dtor
    for(int i = 0; i < BlockID::BLOCK_COUNT; ++i) {
        delete prototypes[i];
    }
}

Block* BlockMgr::cloneBlock(int blockID)
{
    if(blockID > BlockID::NONE_BLOCK && blockID < BlockID::BLOCK_COUNT) {
        return prototypes[blockID]->clone();
    }
    return nullptr;
}
void BlockMgr::setPrototype(int blockID, Block* proto)
{
    delete prototypes[blockID];
    prototypes[blockID] = proto;

}
