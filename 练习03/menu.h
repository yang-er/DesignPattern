///======================================================================
///  Project:   Richer01
/// FileName:	menu.h
///     Desc:
///   Author:	Chen Wei
///  History:
///======================================================================
#ifndef MENU_H
#define MENU_H

#include "outputdevice.h"

class Game;
class Menu
{
public:
    Menu() {}
    virtual ~Menu() {}
    virtual bool process() ;
    static std::shared_ptr<OutputDevice> dev;
protected:
    virtual void show() const = 0;
    virtual int  getChoice() const;
    virtual bool doChoice(int choice) = 0;
};

class CoolMenu : public Menu
{
public:
    CoolMenu(Menu* in) : inner(in) {}
    Menu* inner;
    virtual ~CoolMenu() { delete inner; }

    virtual bool process()
    {
        // PlayMusic
        dev << "======================" << endl;
        dev << "=                    =" << endl;
        dev << "======================" << endl;
        bool ret = inner->process();
        // StopMusic
        return ret;
    }

protected:
    virtual void show() const { }
    virtual bool doChoice(int choice) { return false; }
};

///------主菜单--------------------------------
class MainMenu: public Menu
{
protected:
    virtual void show() const;
    virtual bool doChoice(int choice);
};
///------玩家人数菜单--------------------------------
class PlayersMenu: public Menu
{
protected:
    virtual void show() const;
    virtual bool doChoice(int choice);
};
///-------载入菜单----------------------------------
class LoadMenu: public Menu
{
protected:
    virtual void show() const;
    virtual bool doChoice(int choice);
};
///-------保存菜单----------------------------------
class SaveMenu: public Menu
{
protected:
    virtual void show() const;
    virtual bool doChoice(int choice);
};
///-------选项菜单----------------------------------
class OptionMenu: public Menu
{
protected:
    virtual void show() const;
    virtual bool doChoice(int choice);
};
///-------音量选项菜单----------------------------------
class VolumeMenu: public Menu
{
protected:
    virtual void show() const;
    virtual bool doChoice(int choice);
};
///-------分辨率选项菜单----------------------------------
class ResolutionMenu: public Menu
{
protected:
    virtual void show() const;
    virtual bool doChoice(int choice);
};
#endif // MENU_H
