#include"Board.hpp"
#include "Fleet.hpp"
  Board::Board(int xCoor,int yCoor,int width,int height)
    :m_xCoor(xCoor),
    m_yCoor(yCoor),
    m_width(width),
    m_height(height),
    m_firstY(1),
    m_lastY(19),
    m_firstX(2),
    m_lastX(38)
  {
    m_missCount=0;
    m_widthStep=(4);
    m_heightStep=(2);
    m_horizontalLength=(m_width-2);
    m_verticalLength=(m_height-2);
    m_logicalX=((m_width-1)/m_widthStep);
    m_logicalY=((m_height-1)/m_heightStep);
    m_numOfSquares=(m_logicalY*m_logicalX);
    m_pBoard=newwin(m_height,m_width,m_yCoor,m_xCoor);
    m_missTab=new int[m_numOfSquares*2]();
    keypad(m_pBoard,true);
  }
  Board::~Board()
  {
    delete[] m_missTab;
    delwin(m_pBoard);
  }
  void Board::setMiss(int y, int x)
  {
    for(int i=0;i<m_missCount;i+=2)
    {
      if(m_missTab[i]==y && m_missTab[i+1]==x)
        return;
    }
    m_missTab[m_missCount]=y;
    m_missTab[m_missCount+1]=x;
    m_missCount+=2;
  }
  // Board::getMiss(int i)
  // {
  //
  // }
  void Board::drawBoard(Fleet *pFleet)
  {
      int i;
    	refresh();
      wrefresh(m_pBoard);
    	box(m_pBoard,0,0);
    	for(i=m_heightStep;i<m_height-1;i+=m_heightStep){
    		mvwhline(m_pBoard,i,1,ACS_HLINE,m_horizontalLength);
    	}
    	for(i=m_widthStep;i<m_width-1;i+=m_widthStep){
    		mvwvline(m_pBoard,1,i,ACS_VLINE,m_verticalLength);
    	}
      if(pFleet!=NULL)
      {
        pFleet->printFleet();
      }
      for(i=0;i<m_missCount;i+=2){
        mvwprintw(m_pBoard,m_missTab[i],m_missTab[i+1],"O");
      }
      // for(i=0;i<m_logicalY;i++){
    	// 	if(m_missTab[i*m_logicalY]){
    	// 		mvwprintw(m_pBoard,m_missTab[i*m_logicalY],m_missTab[i*m_logicalY+1],"O");
    	// 	}
      // }
      refresh();
      wrefresh(m_pBoard);
  }
  WINDOW* Board::getWindow()
  {
    return m_pBoard;
  }
  int Board::getWidthStep()
  {
    return m_widthStep;
  }
  int Board::getHeightStep()
  {
    return m_heightStep;
  }
