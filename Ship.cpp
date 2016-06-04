#include"Ship.hpp"
int Ship::counter=0;
void Ship::setYCoordinates(int y)
{
  m_yCoordinates=y;
}
void Ship::setXCoordinates(int x)
{
  m_xCoordinates=x;
}

Ship::Ship(bool hostality,int battleshipLength, WINDOW *p,int ws,int hs)
:m_hostile(hostality),m_battleshipLength(battleshipLength),m_pWin(p),m_heightStep(hs),m_widthStep(ws)
{
  m_hitsTaken=new int[m_battleshipLength]();
  m_xCoordinates=-2;
  m_yCoordinates=-1;
  m_isPlaced=false;
  m_orientation=Ship::counter%2;
  Ship::counter++;
}
Ship::~Ship()
{
  delete[] m_hitsTaken;
}
int Ship::getBattleshipLength()
{
  return m_battleshipLength;
}
void Ship::setPlacement(bool placement)
{
  m_isPlaced=placement;
}
bool Ship::getPlacement()
{
  return m_isPlaced;
}
int Ship::getYCoordinates()
{
  return m_yCoordinates;
}
int Ship::getXCoordinates()
{
  return m_xCoordinates;
}
int Ship::getOrientation()
{
  return m_orientation;
}
void Ship::setOrientation(int o)
{
    m_orientation=o;
}
void Ship::setHit(int i)
{
  m_hitsTaken[i]=1;
}
int Ship::getHit(int i)
{
  return m_hitsTaken[i];
}

void Ship::calcModuleCoordinates(int *moduleY,int *moduleX,int moduleNumber)
{
  if(m_orientation){
		*moduleY=m_yCoordinates;
		*moduleX=m_xCoordinates+m_widthStep*moduleNumber;
	}else{
		*moduleX=m_xCoordinates;
		*moduleY=m_yCoordinates+m_heightStep*moduleNumber;
	}
}
void Ship::printShip(int y, int x)
{

  attron(A_STANDOUT);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  attron(COLOR_PAIR(1));
  // refresh();
  wrefresh(m_pWin);
  // if(m_isPlaced)
  // {
  // start_color();			/* Start color 			*/
  init_pair(1, COLOR_RED, COLOR_BLACK);
  attron(COLOR_PAIR(1));
    int i,j;
  	if(m_orientation){
  		for(i=0,j=0;i<=(m_widthStep*(m_battleshipLength)-m_widthStep);i=i+m_widthStep,j++){
  			if(m_hitsTaken[j]==0){

          if(!m_hostile)
  				    mvwprintw(m_pWin,y,x+i,"#");
  			}else{
  				mvwprintw(m_pWin,y,x+i,"x");
  			}
  		}
  	}else{
  		for(i=0,j=0;i<=(m_heightStep*(m_battleshipLength)-m_heightStep);i=i+m_heightStep,j++){
  			if(m_hitsTaken[j]==0){
          if(!m_hostile)
  				    mvwprintw(m_pWin,y+i,x,"#");
  			}else{
  				mvwprintw(m_pWin,y+i,x,"x");
  			 }

  		}
  	}
    // refresh();
  	wrefresh(m_pWin);
  // }
}
void Ship::printShip()
{
  Ship::printShip(m_yCoordinates,m_xCoordinates);
}
void Ship::calcFutureCoordinates(int *by,int *bx,int *ey,int *ex, int key)
{
  switch(key){
    case KEY_UP:
      *by=*by - m_heightStep;
      break;
    case KEY_DOWN:
      *by=*by+ m_heightStep;
      break;
    case KEY_LEFT:
      *bx=*bx- m_widthStep;
      break;
    case KEY_RIGHT:
      *bx=*bx+ m_widthStep;
  }
  if(m_orientation){
    *ey=*by;
    *ex=*bx+(m_widthStep*(m_battleshipLength-1));
  }else{
    *ex=*by;
    *ey=*by+(m_heightStep*(m_battleshipLength-1));
  }

}
bool Ship::checkValidCoordinates(int c)
{
  int futureBegY,futureBegX,futureEndY,futureEndX;
  futureBegY=m_yCoordinates;
  futureBegX=m_xCoordinates;
  if(c!=0)
  {
    calcFutureCoordinates(&futureBegY,&futureBegX,&futureEndY,&futureEndX,c);
  }else{
    calcModuleCoordinates(&futureEndY,&futureEndX,m_battleshipLength-1);
  }
  if(m_orientation){
    if(futureBegY<1 || futureBegY>19||futureBegX<2 || futureBegX>38||futureEndX<2 || futureEndX>38){
      return 0;
    }
    // if(futureBegX<2 || futureBegX>38){
    //   return 0;
    // }
    // if(futureBegX<2 || futureBegX>38){
    //   return 0;
    // }
  }else{
    if(futureBegX<2 || futureBegX>38){
      return 0;
    }
    if(futureBegY<1 || futureBegY>19){
      return 0;
    }
    if(futureEndY<1 || futureEndY>19){
      return 0;
    }
  }
  return 1;
}
