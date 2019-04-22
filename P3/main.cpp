#include <iostream>
#include <cstdlib> //para usar srand()

#include "arbolbinarioordenadoenlazado.hpp"
#include "operadornodo.hpp"
#include "persona.hpp"
#include "generarpersona.hpp"

using namespace ed;

int main()
{
  srand(time(0));
  ArbolBinarioOrdenadoEnlazado<Persona> a;
  AlmacenarNodo<G> aux();

  std::cout<<"1. Insertar un numero de personas en el arbol"<<std::endl;
  std::cout<<"2. Comprobar si una persona se encuentra en el arbol"<<std::endl;
  std::cout<<"3. Mostrar todos los elementos del arbol. PreOrden, PostOrden, InOrden"<<std::endl;
  std::cout<<"4. Borra una persona dando sus datos"<<std::endl;
  std::cout<<"5. Borra el arbol completo"<<std::endl;

  int x;
  std::cout<<"Introduce la opcion que desse ejecutar"<<std::endl;
  std::cin>>x;

  switch(x){
    case 1:

      break;
    case 2:
      int dni;
      std::cout<<"Introduce el dni"<<std::endl;
      std::cin>>dni;
      buscar(dni);

      break;
    case 3:
      std::cout<<"Recorrido pre-orden:"<<std::endl;
      recorridoPreOrden(&aux);
      std::cout<<"Recorrido post-orden:"<<std::endl;
      recorridoPostOrden(&aux);
      std::cout<<"Recorrido en-orden:"<<std::endl;
      recorridoInOrden(&aux);

      break;
    case 4:
      std::cout<<"Introduce el dni"<<std::endl;
      std::cin>>dni;

      buscar(dni);
      borrar();
      std::cout<<"Persona borrada"<<std::endl;

      break;
    case 5:
      borrarArbol();
      std::cout<<"Arbol borrado"<<std::endl;

      break;
    default:
      std::cout<<"Ha introducido un numero incorrecto"<<std::endl;
      exit(-1);

      break;
  };
}
