///======================================================================
///  Project:   Richer01
/// FileName:	mapbuilder.h
///     Desc:   Richer 01
///   Author:	Chen Wei
///======================================================================
#ifndef MAPBUILDER_H
#define MAPBUILDER_H

class Block;
class MapBuilder
{
public:
    MapBuilder();
    virtual ~MapBuilder();
    virtual Block* buildBlock(int blockID);
protected:

private:
};

class EFMapBuilder:public MapBuilder
{
public:
    EFMapBuilder(){}
    virtual ~EFMapBuilder(){}
    virtual Block* buildBlock(int blockID);
};
#endif // MAPBUILDER_H
