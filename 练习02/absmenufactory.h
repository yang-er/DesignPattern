///======================================================================
///  Project:   Richer01
/// FileName:	absmenufactory.h
///     Desc:   Richer 01
///   Author:	Chen Wei
///======================================================================
#ifndef ABSMENUFACTORY_H
#define ABSMENUFACTORY_H

class Menu;
class AbsMenuFactory
{
public:
    AbsMenuFactory();
    virtual ~AbsMenuFactory();
    virtual Menu* createMenu(int menuID) = 0;
};

#endif // ABSMENUFACTORY_H
