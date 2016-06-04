#ifndef CRUISER_HPP
#define CRUISER_HPP

#include"Ship.hpp"

class Cruiser : public Ship
{
public:
  Cruiser(bool hostality,int battleshipLength,WINDOW *p,int widthStep,int heightStep);
  ~Cruiser();
  void repair();

};
#endif
