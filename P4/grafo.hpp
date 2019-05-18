#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__

#include <cassert>
#include <iostream>

using namespace std;

namespace ed
{

	template <class G_Nodo, class G_Lado>
	class Grafo
	{
	private:

		G_Lado **_lados;

		G_Nodo *_nodos;

	public:
		// constructores
		Grafo(){
			_lados=NULL;
			_nodos=NULL;
			//Postcondicion
			#ifndef NDEBUG
				assert(estaVacio());
			#endif
		}

		Grafo(int n){
			Grafo g= new Grafo();
			g._nodos=n;
		}

		Grafo(Grafo &g){
			*this=g;
		}

		// destructor
		~Grafo(){
			if (not estaVacio())
				borrarGrafo();
		}

		void setLados(G_Lado **lados){
			_lados=lados;
		}

		int getLados(){
			return _lados;
		}

		void setNodos(G_Nodo *nodos){
			_nodos=nodos;
		}

		int getNodos(){
			return (int)_nodos;
		}
		G_Nodo nodoActual(){
			
		}
		//TODO

		// funciones
		void borrarGrafo() {	// cabecera indicada para que compile
			_nodos=NULL;
			_lados=NULL;
		}

		Grafo & operator=(const Grafo &g){
			this->_nodos=g._nodos;
			this->_lados=g._lados;

			return *this;
		}

		bool estaVacio(){
			if(_nodos==NULL)
				return true;
			return false;
		}

	};
}

#endif
