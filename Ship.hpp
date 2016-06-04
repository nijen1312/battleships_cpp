#include<ncurses.h>
#ifndef SHIP_HPP
#define SHIP_HPP
class Ship
{
  public:
    Ship(bool hostality,int battleshipLength,WINDOW *p,int widthStep,int heightStep);
    ~Ship();
    void setOrientation(int o);
    int getOrientation();
    int getXCoordinates();
    int getYCoordinates();
    int getBattleshipLength();
    void setYCoordinates(int y);
    void setXCoordinates(int x);
    void setPlacement(bool placement);
    bool getPlacement();
    void printShip(int y,int x);
    void printShip();
    bool checkValidCoordinates(int c=0);
    void calcModuleCoordinates(int *py,int *px,int moduleNumber);
    void setHit(int i);
    int getHit(int i);
    virtual void repair()=0;

  protected:
    void calcFutureCoordinates(int *by,int *bx,int *ey,int *ex, int key);
    WINDOW *m_pWin;
    bool m_hostile;
    bool m_isPlaced;
    int m_xCoordinates;
    int m_yCoordinates;
    int *m_hitsTaken;
    int m_orientation;
    int m_battleshipLength;
    int m_widthStep;
    int m_heightStep;
  private:
    static int counter;
};
#endif
