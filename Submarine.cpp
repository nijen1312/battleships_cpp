#include"Submarine.hpp"
Submarine::~Submarine()
{
  delete[] m_hitsTaken;
}
Submarine::Submarine(bool hostality,int battleshipLength,WINDOW *p,int widthStep,int heightStep)
:Ship(hostality, battleshipLength,p, widthStep, heightStep)
{}
void Submarine::repair()
{

}
