///======================================================================
///  Project:   Richer01
/// FileName:	blockfactory.h
///     Desc:   Richer 01
///   Author:	Chen Wei
///======================================================================
#ifndef BLOCKFACTORY_H
#define BLOCKFACTORY_H

class Block;
class BlockFactory
{
public:
    BlockFactory();
    virtual ~BlockFactory();
    virtual Block * createBlock(int blockID);
protected:

private:
};

#endif // BLOCKFACTORY_H
