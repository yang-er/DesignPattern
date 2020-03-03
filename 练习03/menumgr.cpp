///======================================================================
///  Project:   Richer01
/// FileName:	menumgr.cpp
///     Desc:   Richer 01
///   Author:	Chen Wei
///======================================================================
#include "global.h"
#include "menumgr.h"
#include "menu.h"
#include "menufactory.h"


MenuMgr* MenuMgr::mgr = nullptr;
MenuMgr* MenuMgr::getMgr()
{
    if(mgr == nullptr) {
        mgr = new MenuMgr;
    }
    return mgr;
}
void  MenuMgr::releaseMgr()
{
    delete mgr;
    mgr = nullptr;
}

MenuMgr::MenuMgr()
{
    //ctor
    for(int i = MenuID::MAIN_MENU; i < MenuID::MENU_COUNT; ++i) {
        menus[i] = nullptr;
    }
}

MenuMgr::~MenuMgr()
{
    //dtor
    for(int i = MenuID::MAIN_MENU; i < MenuID::MENU_COUNT; ++i) {
        delete menus[i];
        menus[i] = nullptr;
    }
    delete fac;
}
void MenuMgr::setMenuFactory(AbsMenuFactory* pFac)
{
    delete fac;
    fac = pFac;
}

Menu* MenuMgr::getMenu(int menuID)
{
    if(menuID < MenuID::MAIN_MENU || menuID >= MenuID::MENU_COUNT) {
        menuID = MenuID::MAIN_MENU;
    }

    if(menus[menuID] == nullptr) {
        menus[menuID] = fac->createMenu(menuID);
    }
    return menus[menuID];
}
