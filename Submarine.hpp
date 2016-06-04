#ifndef SUBMARINE_HPP
#define SUBMARINE_HPP

#include"Ship.hpp"

class Submarine : public Ship
{
public:
  Submarine(bool hostality,int battleshipLength,WINDOW *p,int widthStep,int heightStep);
  ~Submarine();
  void repair();

};
#endif
