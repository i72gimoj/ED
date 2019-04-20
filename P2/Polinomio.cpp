/*!
   \file Polinomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>

#include "Polinomio.hpp"


void ed::Polinomio::ordenaPolinomio()
{
	#ifndef NDEBUG
		assert( this->esNulo() == false );
	#endif

	Monomio aux;
	int j;

	//bucle para ordenar por inserción
	for( int i = 1; i<this->getNumeroMonomios(); i++)
	{
			aux = this->polinomio_[i];
			j = i - 1;
			while( (this->polinomio_[j].getGrado() < aux.getGrado()) && (j >= 0) )
			{
				this->polinomio_[j+1] = this->polinomio_[j];
				j--;
			}
			this->polinomio_[j+1] = aux;
	}

	//bucle que suma aquellos monomios con mismo grado
	for( int i = 0; i<this->getNumeroMonomios()-1; i++)
	{
		if(this->polinomio_[i].getGrado() == this->polinomio_[i+1].getGrado())
		{
			this->polinomio_[i] += this->polinomio_[i+1];
			this->polinomio_.erase(this->polinomio_.begin()+i+1);
		}
	}
}

// Operadores de asignación

/////////////////////////////////////////////////////////////

ed::Polinomio & ed::Polinomio::operator=(ed::Polinomio const &p)
{
	//Precondicion
	#ifndef NDEBUG
		assert(this != &p);
	#endif //NDEBUG

	this->polinomio_.clear();
	for(int i=0; i<p.getNumeroMonomios(); i++){
		this->polinomio_.push_back(p.polinomio_[i]);
	}
	// Se devuelve el objeto actual
	return *this;
}


ed::Polinomio & ed::Polinomio::operator=(ed::Monomio const &m)
{
	this->polinomio_.clear();
	this->polinomio_.push_back(m);

	// Se devuelve el objeto actual
	return *this;
}


ed::Polinomio & ed::Polinomio::operator=(double const &x)
{
	this->polinomio_.clear();
	ed::Monomio m;
	m=x;
	this->polinomio_.push_back(m);

	// Se devuelve el objeto actual
	return *this;
}

//////////////////////////////////////////////////////////////
///			SUMA
ed::Polinomio & ed::Polinomio::operator+=(ed::Polinomio &p)
{
	for( int i = 0; i<p.getNumeroMonomios(); i++)
		this->polinomio_.push_back(p.polinomio_[i]);

	this->ordenaPolinomio();
	// Se devuelve el objeto actual
	return *this;
}
ed::Polinomio & ed::Polinomio::operator+=(ed::Monomio const &m){
	this->polinomio_.push_back(m);
	this->ordenaPolinomio();
	//Se devuelve el objeto actual
	return *this;
}
ed::Polinomio & ed::Polinomio::operator+=(double const &x){
	Monomio m=x;
	this->polinomio_.push_back(m);
	//this->ordenaPolinomio();
	return *this;
}
///			RESTA
ed::Polinomio & ed::Polinomio::operator-=(Polinomio &p){
	for( int i = 0; i<p.getNumeroMonomios(); i++)
		this->polinomio_.push_back(-p.polinomio_[i]);

	this->ordenaPolinomio();
	// Se devuelve el objeto actual
	return *this;
}
ed::Polinomio & ed::Polinomio::operator-=(Monomio &m){
	this->polinomio_.push_back(-m);
	this->ordenaPolinomio();
	//Se devuelve el objeto actual
	return *this;
}
ed::Polinomio & ed::Polinomio::operator-=(double const &x){
	Monomio m=x;
	this->polinomio_.push_back(-m);
	//this->ordenaPolinomio();
	return *this;
}
///			MULTIPLICACION
ed::Polinomio & ed::Polinomio::operator*=(Polinomio &p){
	for(int i=0; i<p.getNumeroMonomios(); i++){
		for(int j=0; j<getNumeroMonomios(); j++){
			this->polinomio_[j].setCoeficiente( p.polinomio_[i].getCoeficiente() * this->polinomio_[j].getCoeficiente());
			this->polinomio_[j].setGrado( p.polinomio_[i].getGrado() + this->polinomio_[j].getGrado() );
		}
	}
	return *this;
}
ed::Polinomio & ed::Polinomio::operator*=(Monomio const &m){
	for(int i=0; i<this->getNumeroMonomios(); i++){
		this->polinomio_[i].setCoeficiente( m.getCoeficiente() * this->polinomio_[i].getCoeficiente());
		this->polinomio_[i].setGrado( m.getGrado() + this->polinomio_[i].getGrado() );
	}
	return *this;
}
ed::Polinomio & ed::Polinomio::operator*=(double const &x){
	for(int i=0; i<this->getNumeroMonomios(); i++)
		this->polinomio_[i].setCoeficiente(x * this->polinomio_[i].getCoeficiente());	

	return *this;
}
///			DIVISION
ed::Polinomio & ed::Polinomio::operator/=(Polinomio &p){
	//Precondicion
	#ifndef NDEBUG
		assert((this->polinomio_[0].getGrado() >= p.polinomio_[0].getGrado()) and (p.esNulo() == false));
	#endif //NDEBUG

	for(int i=0; i<p.getNumeroMonomios(); i++){
		for(int j=0; j<this->getNumeroMonomios(); j++){
			this->polinomio_[j].setCoeficiente( p.polinomio_[i].getCoeficiente() / this->polinomio_[j].getCoeficiente());
			this->polinomio_[j].setGrado( p.polinomio_[i].getGrado() - this->polinomio_[j].getGrado() );
		}
	}

	return *this;
}
ed::Polinomio & ed::Polinomio::operator/=(Monomio const &m){
	//Precondicion
	#ifndef NDEBUG
		assert((this->getGrado() >= m.getGrado()) and (this->esNulo() == false));
	#endif //NDEBUG

	for(int i=0; i<getNumeroMonomios(); i++){
		this->polinomio_[i].setCoeficiente( m.getCoeficiente() / this->polinomio_[i].getCoeficiente());
		this->polinomio_[i].setGrado( m.getGrado() - this->polinomio_[i].getGrado() );
	}
	return *this;	
}
ed::Polinomio & ed::Polinomio::operator/=(double const &x){
	for(int i=0; i<getNumeroMonomios(); i++)
		this->polinomio_[i].setCoeficiente(x / this->polinomio_[i].getCoeficiente());

	return *this;
}


///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Polinomio

void ed::Polinomio::leerPolinomio(){
	int x, grd;
	double coef;
	std::cout<<"Introduce el numero de monomios del polinomio"<<std::endl;
	std::cin>>x;
	ed::Monomio m;
	this->polinomio_.clear();
	for(int i=0; i<x; i++){
		std::cout<<"Monomio "<<i+1<<"\n";
		std::cout<<"Coeficiente: ";
		std::cin>>coef;
		std::cout<<"Grado: ";
		std::cin>>grd;
		for(int j = 0; j<x; j++)
		{
			if( (this->polinomio_[j].getGrado() == grd) || (grd < 0) )
			{
				std::cout<<"No puedes introducir dos monomios con el mismo grado en un mismo Polinomio ni un grado negativo, se ha asignado un valor de 0 al ultimo grado introducido\n";
				grd = 0;
			}
		}
		m.setCoeficiente(coef);
		m.setGrado(grd);
		this->polinomio_.push_back(m);
		if(this->estaOrdenado() == false)
			this->ordenaPolinomio();
	}
}

void ed::Polinomio::escribirPolinomio(){
	for(int i=0; i<this->getNumeroMonomios(); i++){
		if(i!=0)
			std::cout<<" + ";
		this->polinomio_[i].escribirMonomio();
	}
}


///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Polinomio

double ed::Polinomio::calcularValor(double &x){
	int resultado=0;
	for(int i=0;i<getNumeroMonomios();i++){
		resultado = resultado + pow(x,polinomio_[i].getGrado()) * polinomio_[i].getCoeficiente();
	}

	return resultado;
}
