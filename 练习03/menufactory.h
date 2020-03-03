///======================================================================
///  Project:   Richer01
/// FileName:	menufactory.h
///     Desc:   Richer 01
///   Author:	Chen Wei
///======================================================================
#ifndef MENUFACTORY_H
#define MENUFACTORY_H

#include "absmenufactory.h"

class Menu;

class MenuFactory:public AbsMenuFactory
{
public:
    MenuFactory();
    virtual ~MenuFactory();
    virtual Menu * createMenu(int menuID);
};

class MyMenuFactory:public AbsMenuFactory
{
public:
    MyMenuFactory();
    virtual ~MyMenuFactory();
    virtual Menu * createMenu(int menuID);
};

class CoolMenuFactory : public AbsMenuFactory
{
public:
    CoolMenuFactory(AbsMenuFactory *in) : inner(in) { }
    virtual ~CoolMenuFactory() = default;
    virtual Menu * createMenu(int menuID) { return new CoolMenu(inner->createMenu(menuID)); }

protected:
    AbsMenuFactory *inner;
};

#endif // MENUFACTORY_H
