#include <iostream>
#include <cstdlib> //para usar srand()

#include "arbolbinarioordenadoenlazado.hpp"
#include "operadornodo.hpp"
#include "persona.hpp"
#include "generarpersona.hpp"

using namespace ed;
using namespace std;

int main()
{
  srand(time(0));
  ArbolBinarioOrdenadoEnlazado<Persona> a;
  //AlmacenarNodo<G> aux;
  Persona p;
  AlmacenarNodo<Persona> op;
  cout<<"\n---------------------------------------\n"<<endl;
  cout<<"0. Salir del programa"<<endl;
  cout<<"1. Insertar un numero de personas en el arbol"<<endl;
  cout<<"2. Comprobar si una persona se encuentra en el arbol"<<endl;
  cout<<"3. Mostrar todos los elementos del arbol. PreOrden, PostOrden, InOrden"<<endl;
  cout<<"4. Borra una persona dando sus datos"<<endl;
  cout<<"5. Borra el arbol completo"<<endl;

  int x;
  cout<<"\nIntroduce la opcion que desee ejecutar"<<endl;
  cin>>x;
  
  switch(x){
    case 0:
      cout<<"Saliendo del programa"<<endl;
      exit(0);
      break;
    case 1:
      int n;
      cout<<"Introduce el numero de personas a insertar"<<endl;
      cin>>n;
      for(int i=0; i<n; i++)
        a.insertar(generarDatosPersonales());
      main();

      break;
    case 2:
      cout<<"Introduce la persona a buscar"<<endl;
      cin>>p;
      a.buscar(p);
      main();

      break;
    case 3:
      cout<<"Recorrido pre-orden:"<<endl;
      a.recorridoPreOrden(op);
      cout<<"Recorrido post-orden:"<<endl;
      a.recorridoPostOrden(op);
      cout<<"Recorrido en-orden:"<<endl;
      a.recorridoInOrden(op);
      main();

      break;
    case 4:
      cout<<"Introduce la persona a borrar"<<endl;
      cin>>p;
      a.buscar(p);
      a.borrar();
      if(!a.buscar(p))
        cout<<"Persona borrada"<<endl;
      main();

      break;
    case 5:
      a.borrarArbol();
      if(a.estaVacio())
        cout<<"Arbol borrado correctamente"<<endl;
      main();

      break;
    default:
      cout<<"Ha introducido un numero incorrecto"<<endl;
      main();
  };
}
