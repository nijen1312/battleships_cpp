#ifndef BOARD_HPP
#define BOARD_HPP
#include<ncurses.h>

class Fleet;

class Board
{
public:
  Board(int xCoor,int yCoor,int width,int height);
  ~Board();
  void drawBoard(Fleet *pFleet=NULL);
  int getWidthStep();
  int getHeightStep();
  void setMiss(int y,int x);
  WINDOW* getWindow();
private:
  int m_xCoor;
  int m_yCoor;
  int m_width;
  int m_height;
  int m_widthStep;
  int m_heightStep;
  int m_horizontalLength;
  int m_verticalLength;
  int m_firstY;
  int m_lastY;
  int m_firstX;
  int m_lastX;
  int m_logicalX;
  int m_logicalY;
  int m_numOfSquares,m_missCount;
  int *m_missTab;
  WINDOW *m_pBoard;

};
#endif
