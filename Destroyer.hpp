#ifndef DESTROYER_HPP
#define DESTROYER_HPP

#include"Ship.hpp"

class Destroyer : public Ship
{
public:
  Destroyer(bool hostality,int battleshipLength,WINDOW *p,int widthStep,int heightStep);
  ~Destroyer();
  void repair();

};
#endif
