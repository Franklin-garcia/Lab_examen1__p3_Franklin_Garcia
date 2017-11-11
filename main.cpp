#include <iostream>
#include "Pieza.h"
#include <string>
#include <stdlib.h>
using namespace std;

string**crearTablero();
string**llenarMatriz(string**);
void imp_tablero(string**);
void eliminarTablero(string**);
int mov_marine(int,int,int,int);

int main(){
  string**temp=NULL;
  temp=crearTablero();
  temp=llenarMatriz(temp);
  imp_tablero(temp);

  int turno=1;
  bool seguir=true;
  int codx1,cody1,codx2,cody2;

  while(seguir){
    if(turno==1){
        cout<<"Ingrese coordenadas de la posicion para moverse"<<endl;
        cout<<"Ingrese coordenada x"<<endl;
        cin>>codx1;
        cout<<"Ingrese coordenada y"<<endl;
        cin>>cody1;
        cout<<"Ingrese coordenadas de la posicion a moverse"<<endl;
        cout<<"Ingrese coordenada x"<<endl;
        cin>>codx2;
        cout<<"Ingrese coordenada y"<<endl;
        cin>>cody2;
        while(codx1>7 || cody1>7 || codx2>7 || cody2>7 || mov_marine(codx1,cody1,codx2,cody2)){
          cout<<"Coordenadas incorrectas"<<endl;
          cout<<"Ingrese coordenadas de la posicion para moverse"<<endl;
          cout<<"Ingrese coordenada x"<<endl;
          cin>>codx1;
          cout<<"Ingrese coordenada y"<<endl;
          cin>>cody1;
          cout<<"Ingrese coordenadas de la posicion a moverse"<<endl;
          cout<<"Ingrese coordenada x"<<endl;
          cin>>codx2;
          cout<<"Ingrese coordenada y"<<endl;
          cin>>cody2;
        }
        temp[codx2][cody2]=temp[codx1][cody1];
        temp[codx1][cody1]="[ ]";
        imp_tablero(temp);
        turno=2;
    }else if(turno==2){
        cout<<"Ingrese coordenadas de la posicion para moverse"<<endl;
        cout<<"Ingrese coordenada x"<<endl;
        cin>>codx1;
        cout<<"Ingrese coordenada y"<<endl;
        cin>>cody1;
        cout<<"Ingrese coordenadas de la posicion a moverse"<<endl;
        cout<<"Ingrese coordenada x"<<endl;
        cin>>codx2;
        cout<<"Ingrese coordenada y"<<endl;
        cin>>cody2;
        while(codx1>7 || cody1>7 || codx2>7 || cody2>7 || mov_marine(codx1,cody1,codx2,cody2)){
          cout<<"Coordenadas incorrectas"<<endl;
          cout<<"Ingrese coordenadas de la posicion para moverse"<<endl;
          cout<<"Ingrese coordenada x"<<endl;
          cin>>codx1;
          cout<<"Ingrese coordenada y"<<endl;
          cin>>cody1;
          cout<<"Ingrese coordenadas de la posicion a moverse"<<endl;
          cout<<"Ingrese coordenada x"<<endl;
          cin>>codx2;
          cout<<"Ingrese coordenada y"<<endl;
          cin>>cody2;
      }
        temp[codx2][cody2]=temp[codx1][cody1];
        temp[codx1][cody1]="[ ]";
        imp_tablero(temp);
        turno=1;
    }

  }

  //liberar memoria
  eliminarTablero(temp);
  return 0;
}//fin del main

string**crearTablero(){
    string**tablero=new string*[8];
    for(int i=0;i<8;i++){
      tablero[i]=new string[8];
    }

    return tablero;
}


string**llenarMatriz(string**tablero){
    int tipo=1;
    for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
        tablero[i][j]="[ ]";
      }
    }
    Pieza*objeto,*objeto2;
    objeto=new Pieza(1);
    objeto2=new Pieza(2);

      tablero[0][1]=objeto->getSimbolo();
      tablero[0][3]=objeto->getSimbolo();
      tablero[0][5]=objeto->getSimbolo();
      tablero[0][7]=objeto->getSimbolo();
      tablero[1][0]=objeto->getSimbolo();
      tablero[1][2]=objeto->getSimbolo();
      tablero[1][4]=objeto->getSimbolo();
      tablero[1][6]=objeto->getSimbolo();
      tablero[2][1]=objeto->getSimbolo();
      tablero[2][3]=objeto->getSimbolo();
      tablero[2][5]=objeto->getSimbolo();
      tablero[2][7]=objeto->getSimbolo();
      tablero[5][0]=objeto2->getSimbolo();
      tablero[5][2]=objeto2->getSimbolo();
      tablero[5][4]=objeto2->getSimbolo();
      tablero[5][6]=objeto2->getSimbolo();
      tablero[6][1]=objeto2->getSimbolo();
      tablero[6][3]=objeto2->getSimbolo();
      tablero[6][5]=objeto2->getSimbolo();
      tablero[6][7]=objeto2->getSimbolo();
      tablero[7][0]=objeto2->getSimbolo();
      tablero[7][2]=objeto2->getSimbolo();
      tablero[7][4]=objeto2->getSimbolo();
      tablero[7][6]=objeto2->getSimbolo();

  return tablero;
}

void imp_tablero(string**tablero){
    for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
        cout<<tablero[i][j];
      }
      cout<<endl;
    }
}

void eliminarTablero(string**tablero){
  for(int i=0;i<8;i++){
    delete [] tablero[i];
  }
  delete []tablero;
}

int mov_marine(int x1,int y1,int x2, int y2){
    int absoluto1=abs(x1-x2);
    int absoluto2=abs(y1-y2);
    if(absoluto1==absoluto2){
      return 1;
    }else {
      return 2;
  }
}
