#ifndef __FUNCIONES_HPP
#define __FUNCIONES_HPP

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <cstdlib> //Para usar system
#include <fstream> //Para trabajar con ficheros

#include "grafo.hpp"
#include "algoritmosgrafos.hpp"

using namespace std;
using namespace ed;

int nodo_=0;

int menu()
{
  int opcion;

  system("clear");
  cout << "  0. Salir................................\n";
  cout << "  1. Cargar grafo desde fichero...........\n";
  cout << "  2. Algoritmo de Floyd (GD y GND)......\n";

  cout << "Introduzca opcion...:";
  cin >> opcion;

  return opcion;
}

template <class G_Nodo, class G_Lado>
bool cargarGrafo(Grafo<G_Nodo, G_Lado> * &g)
{
  string ficheroMatriz, ficheroEtiquetas;

  cout << "Fichero de la matriz de conexion: ";
  cin >> ficheroMatriz;

  cout << "Fichero de las etiquetas: ";
  cin >> ficheroEtiquetas;

  ifstream fm, fe;
  fm.open(ficheroMatriz.c_str());
  fe.open(ficheroEtiquetas.c_str());

  if(!((fm.is_open()) && (fe.is_open()))){
    cout<<"Error al abrir los ficheros"<<endl;
    return false;
  }
  else{
    string aux;
    while(getline(fm,aux)){
      nodo_++;
    }
    fm.close();
    fe.close();
    return true;
  }
}

template <class G_Nodo, class G_Lado>
void algoritmoFloyd(Grafo<G_Nodo, G_Lado> &g)
{
  int mDistancias[nodo_][nodo_];
  int mIntermedios[nodo_][nodo_];
  
  //Intermedios
  for(int i=1; i<nodo_; i++)
    for(int j=1; j<nodo_; i++){
      if(i==j)
        mIntermedios[i][j]=0;
      else
        mIntermedios[j][i]=i;
    }
  //Distancias
  for(int i=0; i<nodo_; i++){
    for(int j=0; j<nodo_; j++){
      mIntermedios[i][j]=0;
    }
  }

  for(int k=0; k<nodo_; k++)
    for(int i=0; i<nodo_; i++)
      for(int j=0; j<nodo_; j++)
        if((mDistancias[i][k]+mDistancias[k][j])<mDistancias[i][j]){
          mDistancias[i][j]=(mDistancias[i][k]+mDistancias[k][j]);
          mIntermedios[i][j]=mIntermedios[i][k];
        }
  
  cout<<"Matriz distancias"<<endl;
  for(int i=1; i<nodo_; i++){
    for(int j=1; j<nodo_; j++)
      cout<<mDistancias[i][j];
    cout<<endl;
  }
  cout<<"Matriz intermedios"<<endl;
  for(int i=1; i<nodo_; i++){
    for(int j=1; j<nodo_; j++)
      cout<<mIntermedios[i][j];
    cout<<endl;
  }
  string ciudad1, ciudad2;
  cout<<"Introduce dos nodos para calcular la distancia minima"<<endl;
  cin>>ciudad1;
  cin>>ciudad2;

  getchar();
}

#endif
