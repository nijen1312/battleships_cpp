#ifndef GAME_HPP
#define GAME_HPP

class Board;
class Fleet;
class AuxBox;
class Game
{
public:
  Game();
  ~Game();
  void newGame();
  void exitGame();
  void showStats();
private:
  int barrage();
  Fleet* m_playerFleet;
  Board* m_playerBoard;
  Fleet* m_enemyFleet;
  Board* m_enemyBoard;
  AuxBox* m_auxWin;

};
#endif
