#include<cstdlib>
#include <cstddef>
#include"Board.hpp"
#include"Fleet.hpp"
#include"Ship.hpp"
#include"Submarine.hpp"
#include"Patrol.hpp"
#include"Destroyer.hpp"
#include"Cruiser.hpp"


Fleet::Fleet(int size,Board *pBoard)
:m_fleetSize(size),m_pBoard(pBoard)
{
  m_realFleetSize=0;
  m_heightStep=2;
  m_widthStep=4;
  m_fleetArray=new Ship*[m_fleetSize]();
  m_pWin=m_pBoard->getWindow();
}
Fleet::~Fleet()
{
  for(int i=0;i<m_fleetSize;i++)
  {
    delete m_fleetArray[i];
  }
  delete[] m_fleetArray;
}
void Fleet::setWindow(WINDOW *p)
{
  m_pWin=p;
}
void Fleet::setWidthStep(int ws)
{
  m_widthStep=ws;
}
void Fleet::setHeightStep(int hs)
{
  m_heightStep=hs;
}
int Fleet::getHP()
{
  return m_HP;
}
void Fleet::initializeFleet(bool hostality)
{
  Destroyer* desTemp;
  Cruiser* cruTemp;
  Patrol* patTemp;
  Submarine* subTemp;
  int destoyerLength=5;
  int cruiserLength=4;
  int patrolLength=2;
  int submarineLength=3;
  m_HP=destoyerLength+cruiserLength+submarineLength+patrolLength;
  int i,randomYPos,randomXPos;
  for(i=0;i<m_fleetSize;i++)
  {
    switch(i%4)
    {
      case 0:
      desTemp=new Destroyer(hostality,destoyerLength,m_pWin,m_widthStep,m_heightStep);
      if(hostality)
      {
        while(checkColision(desTemp) != desTemp->checkValidCoordinates() )
        {
          desTemp->setYCoordinates(1+(rand()%10)*m_heightStep);
          desTemp->setXCoordinates(2+(rand()%10)*m_widthStep);
        }
        desTemp->setPlacement(true);
      }
      m_fleetArray[i]=desTemp;
      m_realFleetSize++;
      break;

      case 1:
      cruTemp=new Cruiser(hostality,cruiserLength,m_pWin,m_widthStep,m_heightStep);
      if(hostality)
      {
        while(checkColision(cruTemp) != cruTemp->checkValidCoordinates() )
        {
          cruTemp->setYCoordinates(1+(rand()%10)*m_heightStep);
          cruTemp->setXCoordinates(2+(rand()%10)*m_widthStep);
        }
        cruTemp->setPlacement(true);
      }
      m_fleetArray[i]=cruTemp;
      m_realFleetSize++;
      break;

      case 2:
      patTemp=new Patrol(hostality,patrolLength,m_pWin,m_widthStep,m_heightStep);
      if(hostality)
      {
        while(checkColision(patTemp) != patTemp->checkValidCoordinates() )
        {
          patTemp->setYCoordinates(1+(rand()%10)*m_heightStep);
          patTemp->setXCoordinates(2+(rand()%10)*m_widthStep);
        }
        patTemp->setPlacement(true);
      }
      m_fleetArray[i]=patTemp;
      m_realFleetSize++;
      break;

      case 3:
      subTemp=new Submarine(hostality,submarineLength,m_pWin,m_widthStep,m_heightStep);
      if(hostality)
      {
        while(checkColision(subTemp) != subTemp->checkValidCoordinates() )
        {
          subTemp->setYCoordinates(1+(rand()%10)*m_heightStep);
          subTemp->setXCoordinates(2+(rand()%10)*m_widthStep);
        }
        subTemp->setPlacement(true);
      }
      m_fleetArray[i]=subTemp;
      m_realFleetSize++;
      break;

    }
  }
}
bool Fleet::checkHit(int y, int x)
{
  int i,k,xd,yd;
int placedShipY,placedShipX;
refresh();
for(i=0;i<m_fleetSize;i++){
    for(k=0;k<m_fleetArray[i]->getBattleshipLength();k++){
      m_fleetArray[i]->calcModuleCoordinates(&placedShipY,&placedShipX,k);
      xd=abs(x-placedShipX);
      yd=abs(y-placedShipY);
      if(xd==0 && yd==0 && (m_fleetArray[i]->getHit(k)==0)){
        m_fleetArray[i]->setHit(k);
        m_HP=m_HP-1;
        return true;
      }
      if(xd==0 && yd==0 && (m_fleetArray[i]->getHit(k)==1)){
        return true;
      }
    }
}
return false;
}
void Fleet::printFleet()
{
  for(int i=0;i<m_fleetSize;i++){
		if(m_fleetArray[i]->getYCoordinates()!=-1){
      m_fleetArray[i]->printShip();
		}
	}
}
int Fleet::checkColision(Ship *ship){
	int i,j,k,xd,yd;
	int curShipModuleY,curShipModuleX,placedShipModuleY,placedShipModuleX;
	for(i=0;i<m_realFleetSize;i++)
  {
    if(!(m_fleetArray[i]->getPlacement()))
    {
      break;
    }
		for(j=0;j<ship->getBattleshipLength();j++)
    {
			ship->calcModuleCoordinates(&curShipModuleY,&curShipModuleX,j);
      if(m_fleetArray[i]!=0)
      {
  			for(k=0;k<m_fleetArray[i]->getBattleshipLength();k++)
        {
          m_fleetArray[i]->calcModuleCoordinates(&placedShipModuleY,&placedShipModuleX,k);
    			xd=abs(curShipModuleX-placedShipModuleX);
    			yd=abs(curShipModuleY-placedShipModuleY);
    			if(xd<=m_widthStep && yd<=m_heightStep)
          {
    				return 0;
    			}
  			}
      }
		}
	}
	return 1;

}
void Fleet::deployFleet()
{
  int i = 0;
  int c = 1;
  m_fleetArray[i]->setYCoordinates(1);
  m_fleetArray[i]->setXCoordinates(2);
  m_fleetArray[i]->printShip();
  wrefresh(m_pWin);
  while(c!='q' && i<m_fleetSize){
    c=wgetch(m_pWin);
    switch(c){
      case KEY_UP:{
        if(m_fleetArray[i]->checkValidCoordinates(c)){
          m_fleetArray[i]->setYCoordinates(m_fleetArray[i]->getYCoordinates()-m_heightStep);
          wclear(m_pWin);
          m_pBoard->drawBoard(this);
          m_fleetArray[i]->printShip();
          wrefresh(m_pWin);
        }
        break;
      }
      case KEY_DOWN:{
        if(m_fleetArray[i]->checkValidCoordinates(c)){
          m_fleetArray[i]->setYCoordinates(m_fleetArray[i]->getYCoordinates()+m_heightStep);
          wclear(m_pWin);
          m_pBoard->drawBoard(this);
          m_fleetArray[i]->printShip();
          wrefresh(m_pWin);
        }
        break;
      }
      case KEY_LEFT:{
        if(m_fleetArray[i]->checkValidCoordinates(c)){
          m_fleetArray[i]->setXCoordinates(m_fleetArray[i]->getXCoordinates()-m_widthStep);
          wclear(m_pWin);
          m_pBoard->drawBoard(this);
          m_fleetArray[i]->printShip();
          wrefresh(m_pWin);
        }
        break;
      }
      case KEY_RIGHT:{
        if(m_fleetArray[i]->checkValidCoordinates(c)){
          m_fleetArray[i]->setXCoordinates(m_fleetArray[i]->getXCoordinates()+m_widthStep);
          wclear(m_pWin);
          m_pBoard->drawBoard(this);
          m_fleetArray[i]->printShip();
          wrefresh(m_pWin);
        }
        break;
      }
      case '\n':{
        if(checkColision(m_fleetArray[i])){
          m_fleetArray[i]->setPlacement(true);
          i=i+1;
          if(i<m_fleetSize)
          {
            m_fleetArray[i]->setYCoordinates(1);
            m_fleetArray[i]->setXCoordinates(2);
            wclear(m_pWin);
            m_fleetArray[i]->printShip();
            m_pBoard->drawBoard(this);
          }
          // m_fleetArray[i]->setYCoordinates(1);
          // m_fleetArray[i]->setXCoordinates(2);
          // wclear(m_pWin);
          // m_fleetArray[i]->printShip();
          // m_pBoard->drawBoard(this);
          wrefresh(m_pWin);
        }
        break;
      }
      case 'r':{
           if(m_fleetArray[i]->getOrientation())
           {
            if(!((m_fleetArray[i]->getYCoordinates()+m_heightStep*(m_fleetArray[i]->getBattleshipLength()-1))>19))
            {
                 m_fleetArray[i]->setOrientation(0);
            }
           }else{
            if(!((m_fleetArray[i]->getXCoordinates()+m_widthStep*(m_fleetArray[i]->getBattleshipLength()-1))>38))
            {
                m_fleetArray[i]->setOrientation(1);
            }
           }
           wclear(m_pWin);
           m_pBoard->drawBoard();
           m_fleetArray[i]->printShip();
           wrefresh(m_pWin);
           break;
         }
    }
    wrefresh(m_pWin);
  }
}
