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
			{
				this->setInfo(info);
				_izquierdo=NULL;
				_derecho=NULL;
				//Postcondicion
				#ifndef NDEBUG
					assert((this->getIzquierdo()==NULL) and (this->getDerecho()==NULL));
				#endif
			}

			NodoArbolBinario (const NodoArbolBinario &n)
			{
				// TODO
				NodoArbolBinario nuevo = new NodoArbolBinario();
				nuevo->setInfo(n.getInfo());
				nuevo->setIzquierdo(n.getIzquierdo());
				nuevo->setDerecho(n.getDerecho());
				//Postcondicion
				#ifndef NDEBUG
					assert(nuevo==n);
				#endif
			}

			/*!\brief Observadores.*/
			const G & getInfo() const
			{
				return _info;
			}

			NodoArbolBinario *getIzquierdo() const
			{
				return _izquierdo;
			}

			NodoArbolBinario *getDerecho() const
			{
				return _derecho;
			}

			bool esHoja() const
			{
				if(this->getIzquierdo()==NULL && this->getDerecho()==NULL)
					return true;

				return false;
			}

			void recorridoPreOrden (OperadorNodo<G> &operador) const
			{
				// TODO
				if(operador != NULL){
					operador.aplicar(this->getInfo());
					recorridoPreOrden(operador->_izquierda);
					recorridoPreOrden(operador->_derecha);
				}
			}

			void recorridoPostOrden (OperadorNodo<G> &operador) const
			{
				// TODO
				if(operador != NULL){
					recorridoPostOrden(operador->_izquierda);
					recorridoPostOrden(operador->_derecha);
					operador.aplicar(this->getInfo());
				}
			}

			void recorridoInOrden (OperadorNodo<G> &operador) const
			{
				// TODO
				if(operador != NULL){
					recorridoInOrden(operador->_izquierda);
					operador.aplicar(this->getInfo());
					recorridoInOrden(operador->_derecha);
				}
			}

			/*!\brief Modificadores. */
			void setInfo(const G &info)
			{
				_info=info;
			}

			void setIzquierdo(NodoArbolBinario *n)
			{
				_izquierdo=n;
			}

			void setDerecho(NodoArbolBinario *n)
			{
				_derecho=n;
			}

			NodoArbolBinario & operator=(const NodoArbolBinario &n)
			{
				// TODO
				//Precondicion
				#ifndef NDEBUG
					assert(this != n);
				#endif
				this->setInfo(n.getInfo());
				this->setIzquierdo(n.getIzquierdo());
				this->setDerecho(n.getDerecho());

				return *this;
				//Postcondicion
				#ifndef NDEBUG
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
		{
			this->_raiz=NULL;
			//Postcondicion
			#ifndef NDEBUG
				assert(estaVacio());
			#endif
		}

		ArbolBinarioOrdenadoEnlazado (const ArbolBinarioOrdenadoEnlazado<G>& a)
		{
			*this = a;
			//Postcondicion
			#ifndef NDEBUG
				assert(this->_raiz == a._raiz);
				assert(this->_raiz->getIzquierdo == a._raiz->getIzquierdo());
				assert(this->_raiz->getDerecho() == a._raiz->getDerecho());	
			#endif
		}

		~ArbolBinarioOrdenadoEnlazado ()
		{
			if (not estaVacio())
			borrarArbol();
			cout << "Destructor Usado \n";
		}

		ArbolBinarioOrdenadoEnlazado &operator=(const ArbolBinarioOrdenadoEnlazado& a)
		{
			this->_raiz = a._raiz;
			this->_actual = a._actual;
			this->_padre = a._padre;
			
		}

		bool insertar(const G &x)
		{
			// TODO
			bool insertado=false;
			while(x!=_actual->getInfo()){
				if(x<_actual->getInfo()){
					if(_actual->getIzquierdo()!=NULL){
						_padre=_actual;
						_actual=_actual->getIzquierdo();
					}
					else{
						_actual->setIzquierdo(new NodoArbolBinario(x));
						insertado=true;
					}
				}
				else{
					if(_actual->getDerecho()!=NULL){
						_padre=_actual;
						_actual=_actual->getDerecho();
					}
					else{
						_actual->setDerecho(new NodoArbolBinario(x));
						insertado=true;
					}
				}
			}
			return insertado;
		}

		void borrarArbol()
		{
			//Precondicion
			#ifndef NDEBUG
				assert(! this->estaVacio());
			#endif

			_raiz = NULL;
			//Postcondicion
			#ifndef NDEBUG
				assert(this->estaVacio());
			#endif
		}

		bool borrar()
		{
			// TODO
			return false;
		}

		void recorridoPreOrden (OperadorNodo<G> &operador) const
		{
			// TODO
		}

		void recorridoPostOrden (OperadorNodo<G> &operador) const
		{
			// TODO
		}

		void recorridoInOrden (OperadorNodo<G> &operador) const
		{
			// TODO
		}

		bool buscar(const G& x) const
		{
			// TODO
			/*if(x==_raiz->getInfo())
				return true;
			*_actual=*_raiz;
			while(_actual->getInfo()!=x){
				if(x<_actual->getInfo())
					_actual=_actual->getIzquierdo();
				else{
					_actual=_actual->getDerecho();
				}
				*_actual++;
			}
			return true;
			//Postcondicion
			#ifndef NDEBUG
				assert(_actual->getInfo()==x);
			#endif*/
			return false;
		}

		bool estaVacio() const
		{
			if(this->_raiz==NULL)
				return true;
			return false;
		}

		G raiz() const
		{
			//Precondicion
			#ifndef NDEBUG
				assert(!estaVacio());
			#endif
			this->_raiz->getInfo();
		}

		bool existeActual() const
		{
			//Precondicion
			#ifndef NDEBUG
				assert(!estaVacio());
			#endif
			if((this->_actual->getDerecho() != NULL) || (this->_actual->getIzquierdo() != NULL))
				return true;
			return false;
		}

		G actual() const
		{
			#ifndef NDEBUG
				assert(!existeActual());
			#endif
			return this->_actual->getInfo();
		}

		/*!@}*/
	};

} //namespace ed

#endif //__ARBOLORDENADO_HPP__
