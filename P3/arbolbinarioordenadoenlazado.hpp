#ifndef __ARBOLBINARIOORDENADO_HPP__
#define __ARBOLBINARIOORDENADOENLAZADO_HPP__

#include <iostream>
#include <cassert>
#include "arbolbinarioordenado.hpp"
#include "operadornodo.hpp"

using namespace std;
/*!
\brief Espacio de nombres para la asignatura Estructura de datos.
*/
namespace ed
{
	/*!\brief Interfaz para definir un ArbolBinario ordenado.

	Define una interfaz para definir un ArbolBinarioOrdenado.

	\arg G define el campo de información a contener en el arbol.
	\pre G debe tener definidos los operadores < y ==.
	*/
	template<class G>
	class ArbolBinarioOrdenadoEnlazado:public ArbolBinarioOrdenado<G>
	{
	private:

		/*!\brief Define un nodo del arbol binario.*/
		class NodoArbolBinario
		{
		private:
			G _info;  //Valor informativo almacenado en el nodo
			NodoArbolBinario * _izquierdo;  //Puntero al hijo izquierdo
			NodoArbolBinario * _derecho;  //Puntero al hijo derecho

		public:
			NodoArbolBinario (const G &info)
			{//Crea un nuevo nodo sin hijos
				this->setInfo(info);
				_izquierdo=NULL;
				_derecho=NULL;
				//Postcondicion
				#ifndef NDEBUG
					//El nodo creado no tiene hijos
					assert((this->getIzquierdo()==NULL) and (this->getDerecho()==NULL));
				#endif
			}

			NodoArbolBinario (const NodoArbolBinario &n)
			{//Constructor de copia de un nodo
				//En el nodo nuevo se va a copiar la informacion del nodo n
				NodoArbolBinario nuevo = new NodoArbolBinario();
				nuevo->setInfo(n.getInfo());
				nuevo->setIzquierdo(n.getIzquierdo());
				nuevo->setDerecho(n.getDerecho());
				//Postcondicion
				#ifndef NDEBUG
					//Los nodos son iguales
					assert(nuevo==n);
				#endif
			}

			/*!\brief Observadores.*/
			const G & getInfo() const
			{//Obtiene la informacion del nodo
				return _info;
			}

			NodoArbolBinario *getIzquierdo() const
			{//Obtiene el hijo izquierdo
				return _izquierdo;
			}

			NodoArbolBinario *getDerecho() const
			{//Obtiene el hijo derecho
				return _derecho;
			}

			bool esHoja() const
			{//Comprueba si el nodo tiene hijos
				if(this->getIzquierdo()==NULL && this->getDerecho()==NULL)
					return true;

				return false;
			}

			void recorridoPreOrden (OperadorNodo<G> &operador) const
			{//Los hijos realizan el recorrido pre-orden
				//Mostramos la informacdion del nodo
				operador.aplicar(this->getInfo());
				//Si tiene hijo izquierdo, recorre desde la izquierda
				if(this->getIzquierdo() != NULL)
					this->getIzquierdo()->recorridoInOrden(operador);
				//Si tiene hijo derecho, lo recorremos
				if(this->getDerecho() != NULL)
					this->getDerecho()->recorridoInOrden(operador);
			}

			void recorridoPostOrden (OperadorNodo<G> &operador) const
			{//Los hijos realizanel recorrido post-orden
				//Si tiene hijo izquierdo, recorre desde la izquierda
				if(this->getIzquierdo() != NULL)
					this->getIzquierdo()->recorridoInOrden(operador);
				//Si tiene hijo derecho, lo recorremos
				if(this->getDerecho() != NULL)
					this->getDerecho()->recorridoInOrden(operador);
				//Mostramos la informacdion del nodo
				operador.aplicar(this->getInfo());
			}

			void recorridoInOrden (OperadorNodo<G> &operador) const
			{//Los hijos realizan el recorrido en-orden
				//Si tiene hijo izquierdo, recorre desde la izquierda
				if(this->getIzquierdo() != NULL)
					this->getIzquierdo()->recorridoInOrden(operador);
				//Mostramos la informacdion del nodo
				operador.aplicar(this->getInfo());
				//Si tiene hijo derecho, lo recorremos
				if(this->getDerecho() != NULL)
					this->getDerecho()->recorridoInOrden(operador);
			}

			/*!\brief Modificadores. */
			void setInfo(const G &info)
			{//Establece la informacion del nodo
				_info=info;
			}

			void setIzquierdo(NodoArbolBinario *n)
			{//Establece el hijo izquierdo del nodo
				_izquierdo=n;
			}

			void setDerecho(NodoArbolBinario *n)
			{//Establece el hijo derecho del nodo
				_derecho=n;
			}

			NodoArbolBinario & operator=(const NodoArbolBinario &n)
			{//Asigna la informacion del nodo n al nodo actual
				//Precondicion
				#ifndef NDEBUG
					//Los nodos deben ser diferentes
					assert(this != n);
				#endif
				this->setInfo(n.getInfo());
				this->setIzquierdo(n.getIzquierdo());
				this->setDerecho(n.getDerecho());

				return *this;
				//Postcondicion
				#ifndef NDEBUG
					//LOs nodos deben ser iguales
					assert(this == n);
				#endif
			}

		}; //Fin clase NodoArbolBinario

		//Implementación de la raíz
		NodoArbolBinario * _raiz; /*!<La raiz del árbol*/
		NodoArbolBinario * _actual; /*!<Cursor al nodo actual*/
		NodoArbolBinario * _padre; /*!<Cursor al nodo padre*/


	public:

		ArbolBinarioOrdenadoEnlazado ()
		{//Creamos un arbol vacio, para ello, asignamos NULL a la raiz
			this->_raiz=NULL;
			//Postcondicion
			#ifndef NDEBUG
				//El arbol debe estar vacio
				assert(this->estaVacio());
			#endif
		}

		ArbolBinarioOrdenadoEnlazado (const ArbolBinarioOrdenadoEnlazado<G>& a)
		{//Constructor de copia del arbol a al arbol actual
			*this = a;
			//Postcondicion
			#ifndef NDEBUG
				//Los arboles deben ser iguales
				assert(this->_raiz == a._raiz);
				assert(this->_raiz->getIzquierdo == a._raiz->getIzquierdo());
				assert(this->_raiz->getDerecho() == a._raiz->getDerecho());
			#endif
		}

		~ArbolBinarioOrdenadoEnlazado ()
		{//Destructor de la clase arbol
			//Si el arbol esta lleno lo borra
			if (not estaVacio())
				borrarArbol();
			cout << "Destructor Usado \n";
		}

		ArbolBinarioOrdenadoEnlazado &operator=(const ArbolBinarioOrdenadoEnlazado& a)
		{//Asigna la informacion del arbol a al arbol actual
			this->_raiz = a._raiz;
			this->_actual = a._actual;
			this->_padre = a._padre;

		}

		bool insertar(const G &x)
		{//Inserta un nodo en el arbol de forma ordenada
			bool insertado=false;
			if (this->estaVacio()){//Si el arbol esta vacio se inserta el nodo como raiz
				_raiz = new NodoArbolBinario(x);
				insertado = true;
			}
			else{//Si no esta vacio se pone el cursor _actual en la raiz
				_padre = NULL;
				_actual = _raiz;
			}//Mientras que no se haya insertado el nodo se hara el bucle
			while(insertado==false){
				/*Para insertarlo comprobamos si es menor o mayor que el nodo actual para insertarlo
					como hoja en el lugar correspondiente del arbol*/
				if(x<_actual->getInfo()){
					//Si es menor nos vamos al hijo izquierdo y comprobamos si tiene hijo izquiedo
					if(_actual->getIzquierdo()!=NULL){
						//Actualizamos los cursores
						_padre=_actual;//Movemos el padre al hijo izquierdo
						_actual=_actual->getIzquierdo();//El cursor _actual pasa a ser el hijo izquierdo
					}
					else{//Si no tiene hijo izquierdo insertamos el nodo como su hijo izquierdo
						_actual->setIzquierdo(new NodoArbolBinario(x));
						insertado=true;
					}
				}
				else{//Si el nodo es mayor nos vamos al hijo derecho y comprobamos si tiene mas hijos derechos
					if(_actual->getDerecho()!=NULL){
						//Actualizamops los cursores
						_padre=_actual;//MOvemos el poadre al hijo derecho
						_actual=_actual->getDerecho();//El cursor _actual pasa a ser el hijo izquierdo
					}
					else{
						//Si no tiene hijo derecho, insertamos el nodo como hijo derecho
						_actual->setDerecho(new NodoArbolBinario(x));
						insertado=true;
					}
				}
			}
			return insertado;
			//Postcondicion
			#ifndef NDEBUG
				//Comprobamos que el nodo se encuentra en el arbol
				assert(buscar(x));
			#endif
		}

		void borrarArbol()
		{//Borra el arbol por completo
			//Precondicion
			#ifndef NDEBUG
				//Comprobamos que el arbol a borrar no este vacio
				assert(!this->estaVacio());
			#endif

			_raiz = NULL;//Asignamos NULL a la raiz para indicar que el arbol se encuentra vacio
			//Postcondicion
			#ifndef NDEBUG
				//Confirmamos que el arbol se ha vaciado despues de ejecutar la funcion
				assert(this->estaVacio());
			#endif
		}

		bool borrar()
		{//Borra el nodo donde se encuentre el cursor _actual
			//Precondicion
			#ifndef NDEBUG
				assert(existeActual());
			#endif
			bool borrado=false;
			if(_actual==_raiz){//Si el nodo actual es la raiz se borra la raiz quedando el arbol vacio
				_raiz=NULL;
				borrado=true;
			}
			else if(_actual->esHoja()){//Si el nodo es una hoja se borra el nodo y el arbol se queda como estaba
				_actual=_padre;
				borrado=true;
			}
			else{//En caso de que no sea una hoja, se borra el nodo y se cambia la estructura del arbol
				//Si solo tiene hijo izquierdo
				if(_actual->getDerecho()==NULL && _actual->getIzquierdo()!=NULL)
					_padre->setDerecho(_actual->getIzquierdo());
				//Si solo tiene hijo derecho
				if(_actual->getIzquierdo()==NULL && _actual->getDerecho()!=NULL)
					_padre->setIzquierdo(_actual->getDerecho());
				//Si tiene hijo derecho e izquierdo
				if(_actual->getDerecho()!=NULL && _actual->getIzquierdo()!=NULL){
					_actual=_actual->getDerecho();
					while(_actual!=NULL){
						_actual=_actual->getIzquierdo();
					}
					_actual->setInfo(_actual->getDerecho()->getDerecho()->getInfo());
				}
				borrado=true;
			}
			return borrado;
			//Postcondicion
			#ifndef NDEBUG
				//assert();
			#endif
		}

		void recorridoPreOrden (OperadorNodo<G> &operador) const
		{//La raiz hace el recorrido pre-orden
			//Precondicion
			#ifndef NDEBUG
				assert(!this->estaVacio());
			#endif
			_raiz->recorridoPreOrden(operador);
		}

		void recorridoPostOrden (OperadorNodo<G> &operador) const
		{//La raiz hace el recorrrido post-orden
			//Precondicion
			#ifndef NDEBUG
				assert(!this->estaVacio());
			#endif
			_raiz->recorridoPostOrden(operador);
		}

		void recorridoInOrden (OperadorNodo<G> &operador) const
		{//La raiz hace el recorrido en-orden
			//Precondicion
			#ifndef NDEBUG
				assert(!this->estaVacio());
			#endif
			_raiz->recorridoInOrden(operador);
		}

		bool buscar(const G& x)
		{
			bool encontrado=false;
			if(estaVacio())
				return false;
			if(x==_raiz->getInfo()){
				return true;
			}
			_padre=NULL;
			_actual=_raiz;
			while(_actual->getInfo()!=x){
				if(x<_actual->getInfo()){
					if(_actual->getIzquierdo()!=NULL){
						_padre=_actual;
						_actual=_actual->getIzquierdo();
					}
					else{
						_actual=NULL;
					}
				}
				else if(_actual->getInfo()<x){
					if(_actual->getDerecho()==NULL){
						_padre=_actual;
						_actual=_actual->getDerecho();
					}
					else{
						_actual=NULL;
					}
				}
				else{
					encontrado=true;
				}
			}
			if(_actual==NULL){
				_padre=NULL;
				_actual=_raiz;
			}
			return encontrado;
			//Postcondicion
			#ifndef NDEBUG
				//El nodo actual debe apuntar al nodo buscado
				assert(_actual->getInfo()==x);
			#endif
		}

		bool estaVacio() const
		{//Comprueba si el arbol esta vacio
			if(this->_raiz==NULL)
				return true;
			return false;
		}

		G raiz() const
		{//Devuelve la informacion de la raiz
			//Precondicion
			#ifndef NDEBUG
				//El arbol no puede estar vacio
				assert(!estaVacio());
			#endif
			this->_raiz->getInfo();
		}

		bool existeActual() const
		{//Comprueba si existe el nodo al cual se esta apuntado con el cursor _actual
			//Precondicion
			#ifndef NDEBUG
				//Para ello el arbol no puede estar vacio
				assert(!estaVacio());
			#endif
			//Mientras tenga hijos o sea hoja, el nodo actual existe
			if((this->_actual->getDerecho() != NULL) || (this->_actual->getIzquierdo() != NULL) || (this->_actual->esHoja()))
				return true;
			return false;
		}

		G actual() const
		{//Devuelve la informacion del nodo donde se encuentre el cursor _actual
			//Precondicion
			#ifndef NDEBUG
				//El nodo actual debe existir para poder obtener su informacion
				assert(existeActual());
			#endif
			return this->_actual->getInfo();
		}

		/*!@}*/
	};

} //namespace ed

#endif //__ARBOLORDENADO_HPP__
