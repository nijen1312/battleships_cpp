#ifndef PATROL_HPP
#define PATROL_HPP

#include"Ship.hpp"

class Patrol : public Ship
{
  public:
    Patrol(bool hostality,int battleshipLength,WINDOW *p,int widthStep,int heightStep);
   ~Patrol();
   void repair();
};
#endif
