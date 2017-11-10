#ifndef PIEZA_H
#define PIEZA_H
#include <string>
#include <iostream>

using namespace std;

class Pieza{
  public:
    int tipo;
    Pieza(int);
    string getSimbolo();
};
#endif
