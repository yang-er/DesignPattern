#include "menu.h"

int main()
{
	Menu *menu = initMenu();
	menu->execute();
	return 0;
}