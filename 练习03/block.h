///======================================================================
///  Project:   Richer01
/// FileName:	block.h
///     Desc:   Richer 01
///   Author:	Chen Wei
///======================================================================
#ifndef BLOCK_H
#define BLOCK_H


class Block
{
public:
    Block();
    virtual ~Block();
    virtual const char* name() const = 0;
    virtual Block * clone() = 0;
protected:

private:
};

class MoneyBlock: public Block
{
public:
    MoneyBlock(){}
    virtual ~MoneyBlock(){}
    virtual const char* name() const { return "A";}
    virtual MoneyBlock * clone() override;
};
class TripBlock: public Block
{
public:
    TripBlock(){}
    virtual ~TripBlock(){}
    virtual const char* name() const { return "B";}
    virtual TripBlock * clone() override;
};
class BarBlock: public Block
{
public:
    BarBlock(){}
    virtual ~BarBlock(){}
    virtual const char* name() const { return "C";}
    virtual BarBlock * clone() override;
};
class SlideBlock: public Block
{
public:
    SlideBlock(){}
    virtual ~SlideBlock(){}
    virtual const char* name() const { return "D";}
    virtual SlideBlock * clone() override;
};

class EBlock: public Block
{
public:
    EBlock(){}
    virtual ~EBlock(){}
    virtual const char* name() const { return "E";}
    virtual EBlock * clone() override;
};

class FBlock: public Block
{
public:
    FBlock(){}
    virtual ~FBlock(){}
    virtual const char* name() const { return "F";}
    virtual FBlock * clone() override;
};
#endif // BLOCK_H
