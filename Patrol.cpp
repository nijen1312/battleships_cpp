#include"Patrol.hpp"
Patrol::Patrol(bool hostality,int battleshipLength,WINDOW *p,int widthStep,int heightStep)
: Ship(hostality, battleshipLength,p, widthStep, heightStep)
{}
Patrol::~Patrol()
{
  delete[] m_hitsTaken;
}

void Patrol::repair()
{

}
