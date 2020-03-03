///======================================================================
///  Project:   Richer01
/// FileName:	menu.cpp
///     Desc:   Richer 01
///   Author:	Chen Wei
///======================================================================

#include "global.h"
#include "menu.h"
#include "map.h"
#include "game.h"
#include "block.h"
#include "blockmgr.h"
#include <iostream>
using std::cin;

bool Menu::process()
{
    show();
    int choice = getChoice();
    return doChoice(choice);
}
int  Menu::getChoice() const
{
    int choice = 0;
    cin >> choice;
    return choice;
}
///-----------------------------------------
void MainMenu::show() const
{
    dev << "\n\t" << "主菜单" << endl;
    dev << "1: New" << endl;
    dev << "2: Load" << endl;
    dev << "3: Save" << endl;
    dev << "4: Option" << endl;
    dev << "5: Play..." << endl;
    dev << "6: Change To EF"<<endl;
    dev << "0: Exit" << endl;
    dev << " Your selected:";
}

bool MainMenu::doChoice(int choice)
{
    switch(choice) {
    case 1:
        Game::getGame()->setCurMenu(MenuID::PLAYERS_MENU);
        break;
    case 2:
        Game::getGame()->setCurMenu(MenuID::LOAD_MENU);
        break;
    case 3:
        Game::getGame()->setCurMenu(MenuID::SAVE_MENU);
        break;
    case 4:
        Game::getGame()->setCurMenu(MenuID::OPTION_MENU);
        break;
    case 5:
        dev << "Playing ...." << endl;
        Game::getGame()->getCurMap()->show();
        break;
    case 6:
        BlockMgr::getMgr()->setPrototype(BlockID::MONEY_BLOCK,new EBlock);
        BlockMgr::getMgr()->setPrototype(BlockID::BAR_BLOCK,new FBlock);
        Game::getGame()->createMap();
        break;
    default:
        return false;
    }
    return true;
}

///------玩家人数菜单--------------------------------
void PlayersMenu::show() const
{
    dev << "\n\tSet number of players(2-8):" << endl;
    dev << "2. 2" << endl;
    dev << "3. 3" << endl;
    dev << "4. 4" << endl;
    dev << "5. 5" << endl;
    dev << "6. 6" << endl;
    dev << "7. 7" << endl;
    dev << "8. 8" << endl;
    dev << "0. Back" << endl;
    dev << " Your selected:";
}
bool PlayersMenu::doChoice( int choice)
{
    switch(choice) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        dev << "Set Players count" << endl;
        break;
    default:
        Game::getGame()->setCurMenu(MenuID::MAIN_MENU);
    }
    return true;
}
///-------载入菜单----------------------------------
void LoadMenu::show() const
{
    dev << "\n\tSelect the Record to be loaded(1-5):" << endl;
    dev << "1. 1" << endl;
    dev << "2. 2" << endl;
    dev << "3. 3" << endl;
    dev << "4. 4" << endl;
    dev << "5. 5" << endl;
    dev << "0. Back" << endl;
    dev << " Your selected:";
}
bool LoadMenu::doChoice( int choice)
{
    switch(choice) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        dev << "Load Recording..." << endl;
        break;
    default:
        Game::getGame()->setCurMenu(MenuID::MAIN_MENU);
    }
    return true;
}
///-------保存菜单----------------------------------
void SaveMenu::show() const
{
    dev << "\n\tSelect the Record to save(1-5):" << endl;
    dev << "1. 1" << endl;
    dev << "2. 2" << endl;
    dev << "3. 3" << endl;
    dev << "4. 4" << endl;
    dev << "5. 5" << endl;
    dev << "0. Back" << endl;
    dev << " Your selected:";
}
bool SaveMenu::doChoice( int choice)
{
    switch(choice) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        dev << "Save Recording..." << endl;
        break;
    default:
        Game::getGame()->setCurMenu(MenuID::MAIN_MENU);
    }
    return true;
}

///-------选项菜单----------------------------------
void OptionMenu::show() const
{
    dev << "\n\tSet options :" << endl;
    dev << "1.Set the value of Volume(0-100)" << endl;
    dev << "2.Set the resolution" << endl;
    dev << "0. Back" << endl;
    dev << " Your selected:";
}
bool OptionMenu::doChoice(int choice)
{
    switch(choice) {
    case 1:
        Game::getGame()->setCurMenu(MenuID::VOLUME_MENU);
        break;
    case 2:
        Game::getGame()->setCurMenu(MenuID::RESOLUTION_MENU);
        break;
    default:
        Game::getGame()->setCurMenu(MenuID::MAIN_MENU);
        break;
    }
    return true;
}
///-------音量选项菜单----------------------------------
void VolumeMenu::show() const
{
    dev << "\n\tSet Volume" << endl;
    dev << "input value(0-100)：";
}
bool VolumeMenu::doChoice( int choice)
{
    dev << "Set Volume = " << choice << endl;
    Game::getGame()->setCurMenu(MenuID::OPTION_MENU);
    return true;
}
///-------分辨率选项菜单----------------------------------
void ResolutionMenu::show() const
{
    dev << "\n\tSet resolution" << endl;
    dev << "1. 640X320" << endl;
    dev << "2. 800X600" << endl;
    dev << "3. 1024X768" << endl;
    dev << " Your selected:";
}
bool ResolutionMenu::doChoice( int choice)
{
    switch(choice) {
    case 1:
        dev << "640x320" << endl;
        break;
    case 2:
        dev << "800x600" << endl;
        break;
    case 3:
        dev << "1024x768" << endl;
        break;
    default:
        break;
    }
    Game::getGame()->setCurMenu(MenuID::OPTION_MENU);
    return true;
}

