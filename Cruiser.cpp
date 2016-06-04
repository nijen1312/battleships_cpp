#include"Cruiser.hpp"
Cruiser::Cruiser(bool hostality,int battleshipLength,WINDOW *p,int widthStep,int heightStep)
: Ship(hostality, battleshipLength,p, widthStep, heightStep)
{}
Cruiser::~Cruiser()
{
  delete[] m_hitsTaken;
}
void Cruiser::repair()
{

}
