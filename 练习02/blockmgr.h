///======================================================================
///  Project:   Richer01
/// FileName:	blockmgr.h
///     Desc:   Richer 01
///   Author:	Chen Wei
///======================================================================
#ifndef BLOCKMGR_H
#define BLOCKMGR_H


class BlockMgr
{
public:
    static BlockMgr* getMgr();
    static void releaseMgr();
private:
    static BlockMgr* mgr;
private:
    BlockMgr();
    BlockMgr(const BlockMgr&);
    BlockMgr& operator=(const BlockMgr&);
public:
    virtual ~BlockMgr();
    virtual Block* cloneBlock(int blockID);
    void setPrototype(int blockID, Block * proto);
protected:
    Block* prototypes[BlockID::BLOCK_COUNT];
protected:

private:
};

#endif // BLOCKMGR_H
