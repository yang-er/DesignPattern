///======================================================================
///  Project:   Richer01
/// FileName:	menufactory.cpp
///     Desc:   Richer 01
///   Author:	Chen Wei
///======================================================================
#include "global.h"
#include "menu.h"
#include "menufactory.h"

MenuFactory::MenuFactory()
{
    //ctor
}

MenuFactory::~MenuFactory()
{
    //dtor
}
Menu* MenuFactory::createMenu(int menuID)
{
    if(menuID == MenuID::MAIN_MENU) {
        return new MainMenu;
    } else if(menuID == MenuID::PLAYERS_MENU) {
        return new PlayersMenu;
    } else if(menuID == MenuID::LOAD_MENU) {
        return new LoadMenu;
    } else if(menuID == MenuID::SAVE_MENU) {
        return new SaveMenu;
    } else if(menuID == MenuID::OPTION_MENU) {
        return new OptionMenu;
    } else if(menuID == MenuID::VOLUME_MENU) {
        return new VolumeMenu;
    } else if(menuID == MenuID::RESOLUTION_MENU) {
        return new ResolutionMenu;
    } else {
        return new MainMenu;
    }
}
///-----------------------------------------

MyMenuFactory::MyMenuFactory()
{
    //ctor
}

MyMenuFactory::~MyMenuFactory()
{
    //dtor
}
Menu* MyMenuFactory::createMenu(int menuID)
{
    if(menuID == MenuID::MAIN_MENU) {
        return new MainMenu;
    } else if(menuID == MenuID::PLAYERS_MENU) {
        return new PlayersMenu;
    } else if(menuID == MenuID::LOAD_MENU) {
        return new LoadMenu;
    } else if(menuID == MenuID::SAVE_MENU) {
        return new SaveMenu;
    } else if(menuID == MenuID::OPTION_MENU) {
        return new OptionMenu;
    } else if(menuID == MenuID::VOLUME_MENU) {
        return new VolumeMenu;
    } else if(menuID == MenuID::RESOLUTION_MENU) {
        return new ResolutionMenu;
    } else {
        return new MainMenu;
    }
}
