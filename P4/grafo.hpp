#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__

#include <cassert>
#include <iostream>
#include <stdio.h>

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
			_lados=new G_Lado*[0];
			_nodos=new G_Nodo[0];
			//Postcondicion
			#ifndef NDEBUG
				assert(estaVacio());
			#endif
		}

		Grafo(int n){
			_nodos=new G_Nodo[n];
			_lados=new G_Lado*[n];
			for(int i=0; i<n; i++)
				_lados[i]=new G_Lado[n];
		}

		Grafo(Grafo &g){
			*this=g;
		}

		// destructor
		~Grafo(){
			if (not estaVacio())
				borrarGrafo();
		}

		void setLados(G_Lado **&lados){
			_lados=new G_Lado*[lados.size()];
			for (size_t i = 0; i < sizeof(nodos); i++)
				this->_nodos[i] = new G_Lado[sizeof(lados)];
			for(int i=0; i<sizeof(_nodos); i++)
				for(int j=0; j<sizeof(_nodos); j++)
					_lados[i][j]=lados[i][j];
		}
		G_Lado ** getLados()const{
			return _lados;
		}

		void setNodos(vector<G_Nodo> *&nodos){
			_nodos=new G_Nodo[nodos.size()];
			for (size_t i = 0; i < nodos.size(); i++)
				this->_nodos[i] = nodos[i];
		}
		G_Nodo *getNodos()const{
			return _nodos;
		} 

		// funciones
		void borrarGrafo() {	// cabecera indicada para que compile
			_nodos=NULL;
			_lados=NULL;
		}

		Grafo & operator=(const Grafo &g){
			this->setNodos(g._nodos);
			this->setLados(g._lados);
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
