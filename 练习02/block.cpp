///======================================================================
///  Project:   Richer01
/// FileName:	block.cpp
///     Desc:   Richer 01
///   Author:	Chen Wei
///======================================================================
#include "block.h"

Block::Block()
{
    //ctor
}

Block::~Block()
{
    //dtor
}
MoneyBlock* MoneyBlock::clone()
{
    return new MoneyBlock(*this);
}
TripBlock* TripBlock::clone()
{
    return new TripBlock(*this);
}
BarBlock* BarBlock::clone()
{
    return new BarBlock(*this);
}
SlideBlock* SlideBlock::clone()
{
    return new SlideBlock(*this);
}


EBlock* EBlock::clone()
{
    return new EBlock(*this);
}

FBlock* FBlock::clone()
{
    return new FBlock(*this);
}

