#include<ncurses.h>
class AuxBox
{
public:
  AuxBox();
  ~AuxBox();
  void displayHints();
  void displayScore(int pHP,int eHP);
  void displayWinner(int score);
private:
  WINDOW *m_pWin;

};
