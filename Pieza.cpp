#include "Pieza.h"
#include <iostream>

using namespace std;

Pieza::Pieza(int ptipo){
  tipo=ptipo;
}

string Pieza::getSimbolo(){
  if(tipo == 1){
      return "[+]";
  }
  else if(tipo == 2){
      return "[0]";
  }
}
