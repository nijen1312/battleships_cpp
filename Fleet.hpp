#ifndef FLEET_HPP
#define FLEET_HPP
#include<ncurses.h>

class Ship;
class Board;
class Fleet
{
  public:
    Fleet(int size,Board *pBoard);
    ~Fleet();
    void setWindow(WINDOW *pWin);
    void setHeightStep(int hs);
    void setWidthStep(int ws);
    void initializeFleet(bool hostality);
    void deployFleet();
    void printFleet();
    int getHP();
    bool checkHit(int y, int x);

  private:
    WINDOW *m_pWin;
    Board *m_pBoard;
    int m_heightStep,m_widthStep,m_realFleetSize,m_HP;
    Ship** m_fleetArray;
    int m_fleetSize;
    int checkColision(Ship *sh);
};
#endif
