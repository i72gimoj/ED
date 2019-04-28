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
  Persona p;
  EscribirNodo<Persona> op;
  int opcion, n;
  cout<<"Introduce el numero de personas a insertar"<<endl;
  cin>>n;
  for(int i=0; i<n; i++)
    a.insertar(generarDatosPersonales());

  do{
    cout<<"\e[1;92m"<<"\n-----------Menu Principal----------------------\n"<<"\e[0m"<<endl;
    cout<<"0. Salir del programa"<<endl;
    cout<<"1. Comprobar si una persona se encuentra en el arbol"<<endl;
    cout<<"2. Mostrar todos los elementos del arbol. PreOrden, PostOrden, InOrden"<<endl;
    cout<<"3. Borra una persona dando sus datos"<<endl;
    cout<<"4. Borra el arbol completo"<<endl;
    cout<<"5. Volver a insertar personas en el arbol\n"<<endl;
    cout<<"\e[1;92m"<<"--------------------------------------------------"<<"\e[0m"<<endl;
    
    cout<<"\nIntroduce la opcion que desee ejecutar"<<endl;
    cin>>opcion;
    
    switch(opcion){
      case 0:
        cout<<"Saliendo del programa"<<endl;
        exit(0);
        break;
      case 1:
        if(a.estaVacio()){
          cout<<"No se puede buscar en el arbol porque esta vacio"<<endl;
          break;
        }
        cout<<"Introduce la persona a buscar"<<endl;
        cin>>p;
        if(a.buscar(p))
          cout<<"La persona se encuentra en el arbol"<<endl;
        else{
          cout<<"Error al buscar la persona en el arbol, NO se encuentra en el"<<endl;
        }
        break;
      case 2:
        if(a.estaVacio()){
          cout<<"El arbol se encuentra vacio por lo que no se puede mostrar"<<endl;
          break;
        }
        else{
          cout<<"\e[1;31m"<<"Recorrido pre-orden:"<<"\e[0m"<<endl;
          a.recorridoPreOrden(op);
          cout<<"\e[1;34m"<<"Recorrido post-orden:"<<"\e[0m"<<endl;
          a.recorridoPostOrden(op);
          cout<<"\e[1;33m"<<"Recorrido en-orden:"<<"\e[0m"<<endl;
          a.recorridoInOrden(op);
          break;
        }
      case 3:
        cout<<"Introduce la persona a borrar"<<endl;
        cin>>p;
        if(!a.buscar(p))
          cout<<"La persona que se quiere borrar no se encuentra en el arbol"<<endl;
        else{
          a.borrar();
          if(!a.buscar(p))
            cout<<"Persona borrada correctamente"<<endl;        
        }  
        break;
      case 4:
        if(a.estaVacio()){
          cout<<"No se puede borrar el arbol porque esta vacio"<<endl;
          break;
        }
        else{
          a.borrarArbol();
          if(a.estaVacio())
            cout<<"Arbol borrado correctamente"<<endl;

          break;
        }
      case 5:
        if(a.estaVacio()){
          cout<<"\nIntroduce el numero de personas a insertar"<<endl;
          cin>>n;
          for(int i=0; i<n; i++)
            a.insertar(generarDatosPersonales());
          break;
        }
        else{
          cout<<"El arbol ya tiene datos insertados, borrelos antes de insertar nuevos datos"<<endl;
          break;
        }
      default:
        cout<<"Ha introducido un numero incorrecto"<<endl;
    };
  }while(opcion!=0);
}
