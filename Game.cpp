#include<ncurses.h>
#include<cstdlib>
#include<fstream>
#include"Board.hpp"
#include"AuxBox.hpp"
#include"Fleet.hpp"
#include"Game.hpp"
Game::Game()
{

}
Game::~Game()
{
  delete m_playerFleet;
  delete m_enemyFleet;
  delete m_playerBoard;
  delete m_enemyBoard;
  delete m_auxWin;
}
void Game::newGame()
{
  int score;
  refresh();
  m_playerBoard=new Board(0,0,41,21);
  m_playerFleet=new Fleet(4,m_playerBoard);
  m_enemyBoard=new Board(42,0,41,21);
  m_enemyFleet=new Fleet(4,m_enemyBoard);
  m_auxWin=new AuxBox();
  m_playerFleet->initializeFleet(false);
  m_enemyFleet->initializeFleet(true);
  refresh();
  m_enemyBoard->drawBoard();
  m_auxWin->displayHints();
  refresh();
  m_playerBoard->drawBoard();
  m_playerFleet->deployFleet();
  score=this->barrage();
  m_auxWin->displayWinner(score);
  std::ofstream scoreFile;
  scoreFile.open("score.txt");
  scoreFile << "Player HP: "<<m_playerFleet->getHP()<<" "<<"Enemy HP: "<<m_enemyFleet->getHP();
  scoreFile.close();
  clear();
	erase();
	refresh();
}
int Game::barrage()
{
  curs_set(1);
	int c=1;
	int y=1;
	int x=2;
  int ry,rx;
  WINDOW* enemyWin=m_enemyBoard->getWindow();
  WINDOW* playerWin=m_playerBoard->getWindow();
  int widthS=m_playerBoard->getWidthStep();
  int heightS=m_playerBoard->getHeightStep();
  m_auxWin->displayScore(m_playerFleet->getHP(),m_enemyFleet->getHP());
  while(c!='q' && m_enemyFleet->getHP() && m_playerFleet->getHP()){
		c=wgetch(enemyWin);
		switch(c){
			case KEY_UP:{
				if(y>1){
					y-=heightS;
					wmove(enemyWin,y,x);
					wrefresh(enemyWin);
				}
				break;
			}
			case KEY_DOWN:{
				if(y<19){
					y+=heightS;
					wmove(enemyWin,y,x);
					wrefresh(enemyWin);
				}
				break;
			}
			case KEY_LEFT:{
				if(x>2){
					x-=widthS;
					wmove(enemyWin,y,x);
					wrefresh(enemyWin);
				}
				break;
			}
			case KEY_RIGHT:{
				if(x<38){
					x+=widthS;
					wmove(enemyWin,y,x);
					wrefresh(enemyWin);
				}
        break;
			}
      case'\n':
      {
        if(m_enemyFleet->checkHit(y,x))
        {

        }else{
          m_enemyBoard->setMiss(y,x);
        }
        ry=1+(rand()%10)*2;
				rx=2+(rand()%10)*4;
        refresh();
        if(m_playerFleet->checkHit(ry,rx))
        {

        }else{
          m_playerBoard->setMiss(ry,rx);
        }
        m_enemyBoard->drawBoard(m_enemyFleet);
        m_playerBoard->drawBoard(m_playerFleet);
        wmove(enemyWin,y,x);
        m_auxWin->displayScore(m_playerFleet->getHP(),m_enemyFleet->getHP());
        break;
      }
    }
  }
  return (m_playerFleet->getHP())-(m_enemyFleet->getHP());
}
void Game::showStats(){}
void Game::exitGame(){}
