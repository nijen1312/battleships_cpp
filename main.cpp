#include<ncurses.h>
#include<ctime>
#include<cstdlib>
#include"Menu.hpp"
#include"Game.hpp"

void newGame()
{
		Game *coreGame = new Game();
		coreGame->newGame();
		delete coreGame;
}
void showStats()
{

}
void exitGame()
{
	endwin();
	exit(0);
}


int main(){
	srand(time(NULL));
	curs_set(0);
	int numberOfOptions=3;
	int menuWidth=20;
	int menuHeigth=9;

	char *mainMenuOptions[]={
		"New game",
		"Show stats",
		"Exit"
	};

	void(*mainMenuFunctions[])(void)={
		newGame,showStats,exitGame
	};
	Menu *gameMenu = new Menu(numberOfOptions,menuWidth,menuHeigth,mainMenuOptions,mainMenuFunctions);
	gameMenu->displayMenu("BATTLESHIPS");
	delete gameMenu;
	endwin();
	exit(0);
	return 0;
}
