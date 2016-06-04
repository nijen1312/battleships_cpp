#include<menu.h>
#include"Menu.hpp"
#include<cstdlib>
#include<cstring>

Menu::Menu(int numOfOpt,int menuWidth,int menuHeigth,char *mainMenuOptions[],void(**mainMenuFunctions)(void))
  :m_numOfOpt(numOfOpt)
  ,m_menuWidth(menuWidth)
  ,m_menuHeigth(menuHeigth)
  ,m_mainMenuOptions(mainMenuOptions)
  ,m_mainMenuFunctions(mainMenuFunctions)
{
  m_optionsPosY=2;
  m_optionsPosX=3;
}
Menu::~Menu()
{

}

void Menu::displayMenu(char title[])
{
	int i,c;
  const int enterKey=10;
	WINDOW *menuWindow;
	MENU *myMenu;
	ITEM **myOptions;
	ITEM *currentOption;
	initscr();
	noecho();
	cbreak();
	keypad(stdscr,TRUE);
	init_pair(1,COLOR_CYAN,COLOR_BLACK);
  myOptions=new ITEM*[m_numOfOpt];
	for(i=0;i<m_numOfOpt;i++){
		myOptions[i]=new_item(m_mainMenuOptions[i]," ");
    set_item_userptr(myOptions[i],(void*)m_mainMenuFunctions[i]);
	}
	myMenu=new_menu(myOptions);
	menuWindow = newwin(m_menuHeigth,m_menuWidth,(LINES - m_menuHeigth)/2,(COLS - m_menuWidth)/2);
  box(menuWindow,0,0);
	keypad(menuWindow,TRUE);
	set_menu_win(myMenu,menuWindow);
	set_menu_sub(myMenu, derwin(menuWindow,m_numOfOpt,m_menuWidth-2,m_optionsPosX,m_optionsPosY));
	set_menu_format(myMenu,m_numOfOpt,1);
	menu_opts_off(myMenu, O_SHOWDESC);
	set_menu_mark(myMenu," * ");
	post_menu(myMenu);
	wrefresh(menuWindow);
	while((c=wgetch(menuWindow))!=KEY_F(2)){
		switch(c){
			case KEY_UP:
				menu_driver(myMenu,REQ_UP_ITEM);
				break;
			case KEY_DOWN:
				menu_driver(myMenu,REQ_DOWN_ITEM);
				break;
			case enterKey:{
				ITEM *temp;
				temp=current_item(myMenu);
				void(*pointer)(void);
				pointer=(void(*)())item_userptr(temp);
        wclear(menuWindow);
        wrefresh(menuWindow);
        pointer();
        pos_menu_cursor(myMenu);
        menu_driver(myMenu,REQ_DOWN_ITEM);
        // endwin(menuWindow);
				break;
				}
			// wrefresh(menuWindow);
		}
	}
  unpost_menu(myMenu);
  free_menu(myMenu);
  for(int i=0;i<m_numOfOpt;++i){
    free_item(myOptions[i]);
  }
  delete[] myOptions;
  delwin(menuWindow);

}
