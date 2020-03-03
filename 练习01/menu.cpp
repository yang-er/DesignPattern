#include "menu.h"

void MenuBase::execute() {}
void MenuItem::execute() { action(); }

void Menu::execute()
{
	do
	{
		printf("        %s\n", title.data());
		int i = 0;
		for (auto menu: sub_menu)
			printf("%d. %s\n", ++i, menu->title.data());
		printf("0. Back\nYour choice: ");
		scanf("%d", &i);
		if (i == 0) break;
		sub_menu[i-1]->execute();
	}
	while (back_strategy);
}

int volume, resolution;

Menu *initMenu()
{
	std::function<void(void)> a = [] (void) -> void {};
	std::function<void(void)> b = [] (void) -> void
	{
		printf("Set Volume\ninput value(0-100): ");
		scanf("%d", &volume);
	};
	
	auto saveRecord = new NewMenu("save", "Select the record to save(1-5)", { new MenuItem("1", a), new MenuItem("2", a), new MenuItem("3", a), new MenuItem("4", a), new MenuItem("5", a) });
	auto loadRecord = new NewMenu("load", "Select the record to be loaded(1-5)", { new MenuItem("1", a), new MenuItem("2", a), new MenuItem("3", a), new MenuItem("4", a), new MenuItem("5", a) });
	auto setPlayers = new NewMenu("new", "Select number of players", { new MenuItem("default = 2", a), new MenuItem("2", a), new MenuItem("3", a), new MenuItem("4", a), new MenuItem("5", a), new MenuItem("6", a), new MenuItem("7", a), new MenuItem("8", a) });
	auto setResolution = new NewMenu("Set the resolution", "Set resolution", { new MenuItem("640x320", a), new MenuItem("800x600", a), new MenuItem("1024x768", a) });
	auto setVolume = new MenuItem("Set Volume", b);
	auto setOptions = new NewMenu("Option", "Set options for game", { setVolume, setResolution });
	setOptions->back_strategy = true;
	return new MainMenu({ setPlayers, loadRecord, saveRecord, setOptions, new MenuItem("Play", a) });
}
