///======================================================================
///  Project:   Richer01
/// FileName:	menu.cpp
///     Desc:   Richer 01
///   Author:	Chen Wei
///======================================================================
#include <iostream>
#include "menumgr.h"
#include "mapmgr.h"
using namespace std;

#include "global.h"
#include "menu.h"
#include "map.h"
#include "game.h"
#include "block.h"
#include "blockmgr.h"

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
    cout << "\n\t" << "主菜单" << endl;
    cout << "1: New" << endl;
    cout << "2: Load" << endl;
    cout << "3: Save" << endl;
    cout << "4: Option" << endl;
    cout << "5: Play..." << endl;
    cout << "6: Change To EF"<<endl;
    cout << "0: Exit" << endl;
    cout << " Your selected:";
}

bool MainMenu::doChoice(int choice)
{
    switch(choice) {
    case 1:
        MenuMgr::getMgr()->setCurMenu(MenuID::PLAYERS_MENU);
        break;
    case 2:
        MenuMgr::getMgr()->setCurMenu(MenuID::LOAD_MENU);
        break;
    case 3:
        MenuMgr::getMgr()->setCurMenu(MenuID::SAVE_MENU);
        break;
    case 4:
        MenuMgr::getMgr()->setCurMenu(MenuID::OPTION_MENU);
        break;
    case 5:
        cout << "Playing ...." << endl;
        MapMgr::getMgr()->getCurMap()->show();
        break;
    case 6:
        BlockMgr::getMgr()->setPrototype(BlockID::MONEY_BLOCK,new EBlock);
        BlockMgr::getMgr()->setPrototype(BlockID::BAR_BLOCK,new FBlock);
        MapMgr::getMgr()->createMap();
        break;
    default:
        return false;
    }
    return true;
}

///------玩家人数菜单--------------------------------
void PlayersMenu::show() const
{
    cout << "\n\tSet number of players(2-8):" << endl;
    cout << "2. 2" << endl;
    cout << "3. 3" << endl;
    cout << "4. 4" << endl;
    cout << "5. 5" << endl;
    cout << "6. 6" << endl;
    cout << "7. 7" << endl;
    cout << "8. 8" << endl;
    cout << "0. Back" << endl;
    cout << " Your selected:";
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
        cout << "Set Players count" << endl;
        break;
    default:
        MenuMgr::getMgr()->setCurMenu(MenuID::MAIN_MENU);
    }
    return true;
}
///-------载入菜单----------------------------------
void LoadMenu::show() const
{
    cout << "\n\tSelect the Record to be loaded(1-5):" << endl;
    cout << "1. 1" << endl;
    cout << "2. 2" << endl;
    cout << "3. 3" << endl;
    cout << "4. 4" << endl;
    cout << "5. 5" << endl;
    cout << "0. Back" << endl;
    cout << " Your selected:";
}
bool LoadMenu::doChoice( int choice)
{
    switch(choice) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        cout << "Load Recording..." << endl;
        break;
    default:
        MenuMgr::getMgr()->setCurMenu(MenuID::MAIN_MENU);
    }
    return true;
}
///-------保存菜单----------------------------------
void SaveMenu::show() const
{
    cout << "\n\tSelect the Record to save(1-5):" << endl;
    cout << "1. 1" << endl;
    cout << "2. 2" << endl;
    cout << "3. 3" << endl;
    cout << "4. 4" << endl;
    cout << "5. 5" << endl;
    cout << "0. Back" << endl;
    cout << " Your selected:";
}
bool SaveMenu::doChoice( int choice)
{
    switch(choice) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        cout << "Save Recording..." << endl;
        break;
    default:
        MenuMgr::getMgr()->setCurMenu(MenuID::MAIN_MENU);
    }
    return true;
}

///-------选项菜单----------------------------------
void OptionMenu::show() const
{
    cout << "\n\tSet options :" << endl;
    cout << "1.Set the value of Volume(0-100)" << endl;
    cout << "2.Set the resolution" << endl;
    cout << "0. Back" << endl;
    cout << " Your selected:";
}
bool OptionMenu::doChoice(int choice)
{
    switch(choice) {
    case 1:
        MenuMgr::getMgr()->setCurMenu(MenuID::VOLUME_MENU);
        break;
    case 2:
        MenuMgr::getMgr()->setCurMenu(MenuID::RESOLUTION_MENU);
        break;
    default:
        MenuMgr::getMgr()->setCurMenu(MenuID::MAIN_MENU);
        break;
    }
    return true;
}
///-------音量选项菜单----------------------------------
void VolumeMenu::show() const
{
    cout << "\n\tSet Volume" << endl;
    cout << "input value(0-100)：";
}
bool VolumeMenu::doChoice( int choice)
{
    cout << "Set Volume = " << choice << endl;
    MenuMgr::getMgr()->setCurMenu(MenuID::OPTION_MENU);
    return true;
}
///-------分辨率选项菜单----------------------------------
void ResolutionMenu::show() const
{
    cout << "\n\tSet resolution" << endl;
    cout << "1. 640X320" << endl;
    cout << "2. 800X600" << endl;
    cout << "3. 1024X768" << endl;
    cout << " Your selected:";
}
bool ResolutionMenu::doChoice( int choice)
{
    switch(choice) {
    case 1:
        cout << "640x320" << endl;
        break;
    case 2:
        cout << "800x600" << endl;
        break;
    case 3:
        cout << "1024x768" << endl;
        break;
    default:
        break;
    }
    MenuMgr::getMgr()->setCurMenu(MenuID::OPTION_MENU);
    return true;
}

