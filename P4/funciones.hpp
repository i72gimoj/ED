#ifndef __FUNCIONES_HPP
#define __FUNCIONES_HPP

#include <iostream>
#include <cstring>
#include <cstdlib> //Para usar system
#include <fstream> //Para trabajar con ficheros

#include "grafo.hpp"
#include "algoritmosgrafos.hpp"

using namespace std;
using namespace ed;

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

  // TODO

  ifstream fm, fe;
  fm.open(ficheroMatriz.c_str(), ios::in);
  fe.open(ficheroEtiquetas.c_str(), ios::in);

  if((fm.is_open()) && (fe.is_open()))
    return true;
  fm.close();
  fe.close();
  return false;

}

template <class G_Nodo, class G_Lado>
void algoritmoFloyd(Grafo<G_Nodo, G_Lado> &g)
{
  // TODO
  G_Lado **matriz;
  for(int i=0; i<g.getNodos(); i++)
    matriz[i][i]=0;
  for(int k=0; k<g.getNodos(); k++)
    for(int i=0; i<g.getNodos(); i++)
      for(int j=0; j<g.getNodos(); j++)
        if(matriz[i][j]>(matriz[i][k]+matriz[k][j]))
          matriz[i][j]=matriz[i][k]+matriz[k][j];
}

#endif
