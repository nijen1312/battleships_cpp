#include"AuxBox.hpp"
#include<cstring>
AuxBox::AuxBox()
{
  m_pWin=newwin(5,84,21,0);
}
AuxBox::~AuxBox()
{
  delwin(m_pWin);
}
void AuxBox::displayHints()
{
    wrefresh(m_pWin);
    box(m_pWin,0,0);
  	mvwprintw(m_pWin,1,20,"Arrow keys - move around");
  	mvwprintw(m_pWin,2,20,"R - rotate ship");
  	mvwprintw(m_pWin,3,20,"Enter - place ship (keep distance of 1 field from other ships)");
  	wrefresh(m_pWin);
}
void AuxBox::displayScore(int pHP, int eHP)
{
  int y,x;
  char mess1[]="Player HP: ";
  char mess2[]="Enemy HP: ";
  getmaxyx(m_pWin, y,x);
  wclear(m_pWin);
  box(m_pWin,0,0);
  mvwprintw(m_pWin,y/2,(x-strlen(mess1))/2,"%s%3d",mess1,pHP);
  mvwprintw(m_pWin,(y/2)+1,(x-strlen(mess2))/2,"%s%3d",mess2,eHP);
  wrefresh(m_pWin);
}

void AuxBox::displayWinner(int playerHP)
{
  int c;
  char mess1[]="You Win!";
  char mess2[]="You Lose!";
  char mess3[]="Hit 'Q' to quit.";
  wclear(m_pWin);
  box(m_pWin,0,0);
	wrefresh(m_pWin);
	if(playerHP){
		mvwprintw(m_pWin,2,(getmaxx(m_pWin)-strlen(mess1))/2,mess1);
	}else{
		mvwprintw(m_pWin,2,(getmaxx(m_pWin)-strlen(mess2))/2,mess2);
	}
  mvwprintw(m_pWin,4,(getmaxx(m_pWin)-strlen(mess3))/2,mess3);
  wrefresh(m_pWin);
  while(c=getch()!='q'){}
}
