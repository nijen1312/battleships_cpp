#include"Destroyer.hpp"
Destroyer::~Destroyer()
{
  delete[] m_hitsTaken;
}
Destroyer::Destroyer(bool hostality,int battleshipLength,WINDOW *p,int widthStep,int heightStep)
:Ship(hostality, battleshipLength,p, widthStep, heightStep)
{}
void Destroyer::repair()
{

}
