#pragma once
#include <functional>
#include <vector>
#include <string>

class MenuBase {
public:
	virtual void execute();
	std::string title, echo;
protected:
	MenuBase(std::string tit, std::string ech) : title(tit), echo(ech) {}
};

class MenuItem : public MenuBase {
public:
	std::function<void(void)> action;
	virtual void execute();
	MenuItem(std::string tit, std::function<void(void)> sm) : MenuBase(tit, ""), action(sm) {}
};

class Menu : public MenuBase {
public:
	std::vector<MenuBase*> sub_menu;
	virtual void execute();
	bool back_strategy;
protected:
	Menu(std::string tit, std::string echo, std::string bm, std::initializer_list<MenuBase*> sm) : MenuBase(tit, echo), sub_menu(sm), back_name(bm) { back_strategy = false; }
private:
	std::string back_name;
};

class MainMenu : public Menu {
public:
	MainMenu(std::initializer_list<MenuBase*> sm) : Menu("Main menu", "Main menu", "Exit", sm) { back_strategy = true; }
};

class NewMenu : public Menu {
public:
	NewMenu(std::string tit, std::string echo, std::initializer_list<MenuBase*> sm) : Menu(tit, echo, "Back", sm) {}
};

Menu *initMenu();
