/*!
   \file operadoresExternosPolinomios.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>
#include <vector>
#include <cmath>

#include "operadoresExternosPolinomios.hpp"

#include "operadoresExternosMonomios.hpp"

// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed
{
/*
	bool operator==(ed::Polinomio & p1, ed::Polinomio & p2)
	{	
		if(p1.getNumeroMonomios()==p2.getNumeroMonomios())
			for(int i=0; i<p1.getNumeroMonomios(); i++)
				if(p1.getMonomioPolinomio(i)==p2.getMonomioPolinomio(i))
					return true;
		else
			return false;
		//Postcondicion
		#ifndef NDEBUG
			for(int i=0; i<p1.getNumeroMonomios(); i++)
				assert(p1.getMonomioPolinomio(i)==p2.getMonomioPolinomio(i));
		#endif //NDEBUG
		
	}

	bool operator==(ed::Polinomio & p, ed::Monomio & m){
	
		if(p.getNumeroMonomios()==1 && p.getMonomioPolinomio(0)==m)
			return true;
		else 
			return false;
		//Postcondicion
		#ifndef NDEBUG
			assert((p.getNumeroMonomios()==1) and (p.getMonomioPolinomio(0)==m));
		#endif //NDEBUG
		
	}

	bool operator==(ed::Monomio & m, ed::Polinomio & p){
		if(p.getNumeroMonomios()==1 && m==p.getMonomioPolinomio(0))
			return true;
		return false;
		//Postcondicion
		#ifndef NDEBUG
			assert((p.getNumeroMonomios()==1) and (m==p.getMonomioPolinomio(0)));
		#endif //NDEBUG
		
	}

	bool operator==(ed::Polinomio & p, double x){
		if(p.getNumeroMonomios()==1 && p.getMonomioPolinomio(0)==x)
			return true;
		return false;
		//Postcondicion
		#ifndef NDEBUG
			assert((p.getNumeroMonomios()==1) and (p.getMonomioPolinomio(0)==x));
		#endif //NDEBUG
		
	}

	bool operator==(double x, ed::Polinomio & p){
		if(p.getNumeroMonomios()==1 && x==p.getMonomioPolinomio(0))
			return true;
		return false;
		//Postcondicion
		#ifndef NDEBUG
			assert((p.getNumeroMonomios()==1) and (x==p.getMonomioPolinomio(0)));
		#endif //NDEBUG
		
	}

	////////////////////////////////////////////////////////////////////////////////////
	// Operadores de desigualdad
	bool operator!=(ed::Polinomio & p1, ed::Polinomio & p2)
	{
		if(p1.getNumeroMonomios()!=p2.getNumeroMonomios())
			for(int i=0; i<p1.getNumeroMonomios(); i++)
				if(p1.getMonomioPolinomio(i)!=p2.getMonomioPolinomio(i))
					return true;
		else
			return false;
		//Postcondicion
		#ifndef NDEBUG
			for(int i=0; i<p1.getNumeroMonomios(); i++)
				assert(p1.getMonomioPolinomio(i)!=p2.getMonomioPolinomio(i));
		#endif //NDEBUG
		
	}

	bool operator!=(ed::Polinomio & p, ed::Monomio & m){
		if(p.getNumeroMonomios()!=1 || p.getMonomioPolinomio(0)!=m)
			return true;
		else 
			return false;
		//Postcondicion
		#ifndef NDEBUG
			assert((p.getNumeroMonomios()!=1) or (p.getMonomioPolinomio(0)!=m));
		#endif //NDEBUG
		
	}

	bool operator!=(ed::Monomio & m, ed::Polinomio & p){
		if(p.getNumeroMonomios()!=1 || m!=p.getMonomioPolinomio(0))
			return true;
		return false;
		//Postcondicion
		#ifndef NDEBUG
			assert((p.getNumeroMonomios()!=1) or (m!=p.getMonomio(0)));
		#endif //NDEBUG
		
	}

	bool operator!=(ed::Polinomio & p, double x){
		if(p.getNumeroMonomios()!=1 || p.getMonomioPolinomio(0)!=x)
			return true;
		return false;
		//Postcondicion
		#ifndef NDEBUG
			assert((p.getNumeroMonomios()!=1) or (p.getMonomioPolinomio(0)!=x));
		#endif //NDEBUG
		
	}

	bool operator!=(double x, ed::Polinomio & p){
		if(p.getNumeroMonomios()!=1 || x!=p.getMonomioPolinomio(0))
			return true;
		return false;
		//Postcondicion
		#ifndef NDEBUG
			assert((p.getNumeroMonomios()!=1) or (x!=p.getMonomio(0)));
		#endif //NDEBUG
		
	}

	//////////////////////////////////////////////////////////////////////////////////////

	// Operadores unarios

	//Suma
	ed::Polinomio & operator+(ed::Polinomio & p)
	{
		// Se crea un nuevo objeto
		ed::Polinomio *nuevo = new ed::Polinomio(p);
		//Postcondicion
		#ifndef NDEBUG
			assert( p == *nuevo );
		#endif
		// Se devuelve el resultado
		return *nuevo;
		
	}

	//Resta
	ed::Polinomio & operator-(ed::Polinomio & p){
		// Se crea un nuevo objeto
		ed::Polinomio *nuevo = new ed::Polinomio(-p);
		//Postcondicion
		#ifndef NDEBUG
			assert( p == *nuevo );
		#endif
		// Se devuelve el resultado
		return *nuevo;
		
	}
	//////////////////////////////////////////////////////////////////////////////////////

	// Operadores binarios de la suma
	ed::Polinomio & operator+(ed::Polinomio const &p1,  ed::Polinomio const &p2)
	{
		// Se crea un nuevo objeto
		ed::Polinomio *nuevo = new ed::Polinomio;
		
		for(int i=0; i<p1.getNumeroMonomios(); i++){
			nuevo->polinomio_.push_back(p1.getMonomioPolinomio(i));
			nuevo->polinomio_.push_back(p2.getMonomioPolinomio(i));
		}
		nuevo->ordenaPolinomio();
		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Polinomio & operator+(ed::Polinomio const & p, ed::Monomio const & m){
		// Se crea un nuevo objeto
		ed::Polinomio *nuevo = new ed::Polinomio;
		for(int i=0; i<p.getNumeroMonomios(); i++){
			nuevo->polinomio_.push_back(p.getMonomioPolinomio(i));	
			nuevo->polinomio_.push_back(m);
		}
		nuevo->ordenaPolinomio();
		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Polinomio & operator+(ed::Monomio const & m, ed::Polinomio const & p){
		// Se crea un nuevo objeto
		ed::Polinomio *nuevo = new ed::Polinomio;
		for(int i=0; i<p.getNumeroMonomios(); i++){
			nuevo->polinomio_.push_back(m);
			nuevo->polinomio_.push_back(p.getMonomioPolinomio(i));	
		}
		nuevo->ordenaPolinomio();
		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Polinomio & operator+(ed::Polinomio const & p, double x){
		// Se crea un nuevo objeto
		ed::Polinomio *nuevo = new ed::Polinomio;
		Monomio m;
		m=x;
		for(int i=0; i<p.getNumeroMonomios(); i++){
			nuevo->polinomio_.push_back(p.getMonomioPolinomio(i));	
			nuevo->polinomio_.push_back(m);
		}
		nuevo->ordenaPolinomio();
		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Polinomio & operator+(double x, ed::Polinomio const & p){
		// Se crea un nuevo objeto
		ed::Polinomio *nuevo = new ed::Polinomio;
		Monomio m;
		m=x;
		for(int i=0; i<p.getNumeroMonomios(); i++){
			nuevo->polinomio_.push_back(m);
			nuevo->polinomio_.push_back(p.getMonomioPolinomio(i));		
		}
		nuevo->ordenaPolinomio();
		// Se devuelve el resultado
		return *nuevo;
	}

	///////////////////////////////////////////////////////////////////////////
	// Resta

	ed::Polinomio & operator-(ed::Polinomio const &p1,  ed::Polinomio const &p2){
		// Se crea un nuevo objeto
		ed::Polinomio *nuevo = new ed::Polinomio;
		for(int i=0; i<p1.getNumeroMonomios(); i++){
			nuevo->polinomio_.push_back(p1.getMonomioPolinomio(i));
			nuevo->polinomio_.push_back(-p2.getMonomioPolinomio(i));
		}
		nuevo->ordenaPolinomio();
		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Polinomio & operator-(ed::Polinomio const & p, ed::Monomio const & m){
		// Se crea un nuevo objeto
		ed::Polinomio *nuevo = new ed::Polinomio;
		for(int i=0; i<p.getNumeroMonomios(); i++){
			nuevo->polinomio_.push_back(p.getMonomioPolinomio(i));	
			nuevo->polinomio_.push_back(-m);
		}
		nuevo->ordenaPolinomio();
		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Polinomio & operator-(ed::Monomio const & m, ed::Polinomio const & p){
		// Se crea un nuevo objeto
		ed::Polinomio *nuevo = new ed::Polinomio;
		for(int i=0; i<p.getNumeroMonomios(); i++){
			nuevo->polinomio_.push_back(m);
			nuevo->polinomio_.push_back(-p.getMonomioPolinomio(i));	
		}
		nuevo->ordenaPolinomio();
		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Polinomio & operator-(ed::Polinomio const & p, double x){
		// Se crea un nuevo objeto
		ed::Polinomio *nuevo = new ed::Polinomio;
		Monomio m;
		m=x;
		for(int i=0; i<p.getNumeroMonomios(); i++){
			nuevo->polinomio_.push_back(p.getMonomioPolinomio(i));	
			nuevo->polinomio_.push_back(-m);
		}
		nuevo->ordenaPolinomio();
		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Polinomio & operator-(double x, ed::Polinomio const & p){
		ed::Polinomio *nuevo = new ed::Polinomio;
		Monomio m;
		m=x;
		for(int i=0; i<p.getNumeroMonomios(); i++){
			nuevo->polinomio_.push_back(m);
			nuevo->polinomio_.push_back(-p.getMonomioPolinomio(i));		
		}
		nuevo->ordenaPolinomio();
		// Se devuelve el resultado
		return *nuevo;
	}

	/////////////////////////////////////////////////////////////////////////////
	// Multiplicación

	ed::Polinomio & operator*(ed::Polinomio const &p1,  ed::Polinomio const &p2){
		// Se crea un nuevo objeto
		ed::Polinomio *nuevo = new ed::Polinomio;
		for(int i=0; i<p1.getNumeroMonomios(); i++){
			for(int j = 0; j < p2.getNumeroMonomios(); j++)
				nuevo->polinomio_.push_back(p1.getMonomioPolinomio(i) * p2.getMonomioPolinomio(j));
		nuevo->ordenaPolinomio();
		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Polinomio & operator*(ed::Polinomio const & p, ed::Monomio const & m){
		// Se crea un nuevo objeto
		ed::Polinomio *nuevo = new ed::Polinomio;
		for(int i=0; i<p.getNumeroMonomios(); i++)
			nuevo->polinomio_.push_back(p.getMonomioPolinomio(i) * m);
		nuevo->ordenaPolinomio();
		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Polinomio & operator*(ed::Monomio const & m, ed::Polinomio const & p){
		// Se crea un nuevo objeto
		ed::Polinomio *nuevo = new ed::Polinomio;
		for(int i=0; i<p.getNumeroMonomios(); i++)
			nuevo->polinomio_.push_back(m * p.getMonomioPolinomio(i));
		nuevo->ordenaPolinomio();
		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Polinomio & operator*(ed::Polinomio const & p, double x){
		// Se crea un nuevo objeto
		ed::Polinomio *nuevo = new ed::Polinomio;
		ed::Monomio m;
		m=x;
		for(int i=0; i<p.getNumeroMonomios(); i++)
			nuevo->polinomio_.push_back(p1.getMonomioPolinomio(i) * m);
		nuevo->ordenaPolinomio();
		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Polinomio & operator*(double x, ed::Polinomio const & p){
		// Se crea un nuevo objeto
		ed::Polinomio *nuevo = new ed::Polinomio;
		ed::Monomio m;
		m=x;
		for(int i=0; i<p.getNumeroMonomios(); i++)
			nuevo->polinomio_.push_back(m * p.getMonomioPolinomio(i));
		nuevo->ordenaPolinomio();
		// Se devuelve el resultado
		return *nuevo;
	}

	/////////////////////////////////////////////////////////////////////////////
	// División

	ed::Polinomio & operator/(ed::Polinomio const &p1,  ed::Polinomio const &p2){
		//Precondicion
		#ifndef NDEBUG
			assert(p2.getGrado() <= p1.polinomio_.getGrado());
		#endif //NDEBUG
		// Se crea un nuevo objeto
		ed::Polinomio *nuevo = new ed::Polinomio;
		for(int i=0; i<p1.getNumeroMonomios(); i++)
			for(int j = 0; j < p2.getNumeroMonomios(); j++)
				nuevo->polinomio_.push_back(p1.getMonomioPolinomio(i) / p2.getMonomioPolinomio(j));
		nuevo->ordenaPolinomio();
		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Polinomio & operator/(ed::Polinomio const & p, ed::Monomio const & m){
		//Precondicion
		#ifndef NDEBUG
			assert(m.getGrado() <= p.polinomio_.getGrado());
		#endif //NDEBUG
		// Se crea un nuevo objeto
		ed::Polinomio *nuevo = new ed::Polinomio;
		for(int i=0; i<p.getNumeroMonomios(); i++)
			nuevo->polinomio_.push_back(p.getMonomioPolinomio(i) / m);
		nuevo->ordenaPolinomio();
		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Polinomio & operator/(ed::Monomio const & m, ed::Polinomio const & p){
		//Precondicion
		#ifndef NDEBUG
			assert(p.polinomio_.getGrado() <= m.getGrado());
		#endif //NDEBUG
		// Se crea un nuevo objeto
		ed::Polinomio *nuevo = new ed::Polinomio;
		for(int i=0; i<p.getNumeroMonomios(); i++)
			nuevo->polinomio_.push_back(m / p.getMonomioPolinomio(i));
		nuevo->ordenaPolinomio();
		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Polinomio & operator/(ed::Polinomio const & p, double x){
		//Precondicion
		#ifndef NDEBUG
			assert(x!=0.0);
		#endif //NDEBUG
		// Se crea un nuevo objeto
		ed::Polinomio *nuevo = new ed::Polinomio;
		ed::Monomio m;
		m=x;
		for(int i=0; i<p.getNumeroMonomios(); i++)
			nuevo->polinomio_.push_back(p1.getMonomioPolinomio(i) / m);
		nuevo->ordenaPolinomio();
		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Polinomio & operator/(double x, ed::Polinomio const & p){
		//Precondicion
		#ifndef NDEBUG
			assert((p.getGrado()==0) and (p.polinomio_[0].getGrado()!=0.0));
		#endif //NDEBUG
		// Se crea un nuevo objeto
		ed::Polinomio *nuevo = new ed::Polinomio;
		ed::Monomio m;
		m=x;
		for(int i=0; i<p.getNumeroMonomios(); i++)
			nuevo->polinomio_.push_back(m / p.getMonomioPolinomio(i));
		nuevo->ordenaPolinomio();
		// Se devuelve el resultado
		return *nuevo;
	}


	////////////////////////////////////////////////////////////////////////////

	// Sobrecarga del operador de entrada
	istream &operator>>(istream &stream, Polinomio &p)
	{
		int x;
		std::cout<<"Introduce el numero de monomios del polinomio"<<std::endl;
		std::cin>>x;
		Monomio m;
		for(int i=0; i<x; i++){
			stream>>m;
			p.polinomio_.push_back(m);
		}
		if(p.estaOrdenado() == false)
			p.ordenaPolinomio();
		// Se devuelve el flujo de entrada
	  return stream;
	}

	// Sobrecarga del operador de salida
	ostream &operator<<(ostream &stream, Polinomio &p)
	{
		stream<<p.getMonomioPolinomio(0);
		for(int i=1; i<p.getNumeroMonomios(); i++)
			stream<<" + "<<p.getMonomioPolinomio(i);
		stream<<std::endl;
		// Se devuelve el flujo de salida
		return stream;
	}
*/
} // Fin del espacio de nombres ed
