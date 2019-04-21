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
				operador.aplicar(this->getInfo());
				if(this->getIzquierdo() != NULL)
					this->getIzquierdo()->recorridoInOrden(operador);
				if(this->getDerecho() != NULL)
					this->getDerecho()->recorridoInOrden(operador);
			}

			void recorridoPostOrden (OperadorNodo<G> &operador) const
			{
				if(this->getIzquierdo() != NULL)
					this->getIzquierdo()->recorridoInOrden(operador);
				if(this->getDerecho() != NULL)
					this->getDerecho()->recorridoInOrden(operador);
				operador.aplicar(this->getInfo());
			}

			void recorridoInOrden (OperadorNodo<G> &operador) const
			{
				if(this->getIzquierdo() != NULL)
					this->getIzquierdo()->recorridoInOrden(operador);
				operador.aplicar(this->getInfo());
				if(this->getDerecho() != NULL)
					this->getDerecho()->recorridoInOrden(operador);
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
				assert(this->estaVacio());
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
			bool insertado=false;
			if (this->estaVacio()){
				NodoArbolBinario nuevo(x);
				_raiz = &nuevo;
				insertado = true;
			}
			else{
				_padre = NULL;
				_actual = _raiz;
			}
			while(insertado=false){
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
			}
			return insertado;
			//Postcondicion
			#ifndef NDEBUG
				assert(buscar(x));
			#endif
		}

		void borrarArbol()
		{
			//Precondicion
			#ifndef NDEBUG
				assert(!this->estaVacio());
			#endif

			_raiz = NULL;
			//Postcondicion
			#ifndef NDEBUG
				assert(this->estaVacio());
			#endif
		}

		bool borrar()
		{
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
				if(_actual->getDerecho()==NULL && _actual->getIzquierdo()!=NULL)
					_padre->setDerecho(_actual->getIzquierdo());
				if(_actual->getIzquierdo()==NULL && _actual->getDerecho()!=NULL)
					_padre->setIzquierdo(_actual->getDerecho());
				if(_actual->getDerecho()!=NULL && _actual->getIzquierdo()!=NULL){
					_actual=_actual->getDerecho()->getIzquierdo();
					_actual->getDerecho()->getIzquierdo()->setInfo(_actual->getDerecho()->getDerecho()->getInfo());
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
		{
			_raiz->recorridoPreOrden(operador);
		}

		void recorridoPostOrden (OperadorNodo<G> &operador) const
		{
			_raiz->recorridoPostOrden(operador);
		}

		void recorridoInOrden (OperadorNodo<G> &operador) const
		{
			_raiz->recorridoInOrden(operador);
		}

		bool buscar(const G& x) const
		{
			// TODO
			bool encontrado=false;
			if(x==_raiz->getInfo())
				return true;
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
				assert(_actual->getInfo()==x);
			#endif
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
