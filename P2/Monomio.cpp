/*! 
   \file  Monomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "Monomio.hpp"

// Operadores de asignación


ed::Monomio & ed::Monomio::operator=(ed::Monomio const &m)
{
	// Se comprueba que no sean el mismo objeto
		if (this != &m) 
		{
			this->setCoeficiente(m.getCoeficiente());
			this->setGrado(m.getGrado());

			#ifndef NDEBUG
				// Se comprueba la postcondiciÃ³n
				assert(std::abs (this->getCoeficiente() - m.getCoeficiente()) < COTA_ERROR); 
				assert(std::abs (this->getGrado() - m.getGrado()) < COTA_ERROR);
			#endif //NDEBUG
		}
	// Se devuelve el objeto actual
	return *this;
}


ed::Monomio & ed::Monomio::operator=(double const &x)
{
	// Se comprueba que no sean el mismo objeto
	this->setCoeficiente(x);
	this->setGrado(0);

	#ifndef NDEBUG
		// Se comprueba la postcondicion
		assert(getGrado()==0); 
		assert(std::abs (this->getCoeficiente() - x) < COTA_ERROR);
	#endif //NDEBUG

	// Se devuelve el objeto actual
	return *this;
}



//////////////////////////////////////////////////////////////

// Operadores aritméticos y asignación


ed::Monomio & ed::Monomio::operator+=(ed::Monomio &m)
{
	
	//Precondicion
	#ifndef NDEBUG
		assert(std::abs (this->getGrado()-m.getGrado())<COTA_ERROR);
	#endif //NDEBUG
	this->setCoeficiente(this->getCoeficiente()+m.getCoeficiente());

	//Postcondicion
	#ifndef NDEBUG
		assert(std::abs (m.getGrado()-this->getGrado())<COTA_ERROR);
	#endif //NDEBUG


	// Se devuelve el objeto actual
	return *this;
}

ed::Monomio & ed::Monomio::operator-=(ed::Monomio &m)
{
	//Precondicion
	#ifndef NDEBUG
		assert(std::abs (this->getGrado()-m.getGrado())<COTA_ERROR);
	#endif //NDEBUG
	double c=coeficiente_;
	this->coeficiente_-=m.getCoeficiente();

	//Postcondicion
	#ifndef NDEBUG
		assert(this->coeficiente_<c);
		assert(std::abs (m.getGrado()-this->getGrado())<COTA_ERROR);
	#endif //NDEBUG


	// Se devuelve el objeto actual
	return *this;
}
ed::Monomio & ed::Monomio::operator*=(ed::Monomio &m)
{	
	double c=coeficiente_;
	int g=grado_;
	this->coeficiente_*=m.getCoeficiente();
	this->grado_+=m.getGrado();

	//Postcondicion
	#ifndef NDEBUG
		assert(this->coeficiente_==(c*m.getCoeficiente()));
		assert((this->grado_)>g);
	#endif //NDEBUG
	// Se devuelve el objeto actual
	return *this;
}
ed::Monomio & ed::Monomio::operator/=(ed::Monomio &m)
{
	
	//Precondicion
	#ifndef NDEBUG
		assert(m.getGrado()<=this->getGrado());
		assert(m.getCoeficiente()!=0.0);
	#endif //NDEBUG
	double c=coeficiente_;
	int g=grado_;
	this->coeficiente_/=m.getCoeficiente();
	this->grado_-=m.getGrado();

	//Postcondicion
	#ifndef NDEBUG
		assert(this->coeficiente_==(c/m.getCoeficiente()));
		assert((this->grado_)<g);
	#endif //NDEBUG

	// Se devuelve el objeto actual
	return *this;
}

ed::Monomio & ed::Monomio::operator*=(double &x){
	double c=coeficiente_;
	this->coeficiente_*=x;
	//Postcondicion
	#ifndef NDEBUG
		assert(this->coeficiente_==c*x);
		assert(std::abs(grado_-this->getGrado())<COTA_ERROR);
	#endif //NDEBUG
		return *this;
}

ed::Monomio & ed::Monomio::operator/=(double &x){
	//Precondicion
	#ifndef NDEBUG
		assert(x!=0.0);
	#endif //NDEBUG
		double c=coeficiente_;
		this->coeficiente_/=x;
	//Postcondicion
	#ifndef NDEBUG
		assert(this->coeficiente_==c/x);
		assert(std::abs(grado_-this->getGrado())<COTA_ERROR);
	#endif //NDEBUG
		return *this;
}


///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Monomio

void ed::Monomio::leerMonomio(){
	double coeficiente;
	int grado;
	std::cout<<"Introduce el coeficiente del monomio"<<std::endl;
	std::cin>>coeficiente;
	std::cout<<"Introduce el grado del monomio"<<std::endl;
	std::cin>>grado;

	this->setCoeficiente(coeficiente);
	this->setGrado(grado);
	//Postcondicion
	#ifndef NDEBUG
		assert(grado>=0);
	#endif //NDEBUG

}

void ed::Monomio::escribirMonomio(){
	if(getCoeficiente()==1){
		if(getGrado()==0){
				std::cout<<getCoeficiente()<<std::endl;
		}
		else{
			if(getGrado()==1){
				std::cout<<"X"<<std::endl;
			}
			else{
				std::cout<<"X^"<<this->getGrado()<<std::endl;
			}
		}
	}
	else{
		if(getCoeficiente()==-1){
			if(getGrado()==0){
				std::cout<<getCoeficiente()<<std::endl;
			}
			else{
				if(getGrado()==1){
					std::cout<<"-X"<<std::endl;
				}
				else{
					std::cout<<"-X^"<<this->getGrado()<<std::endl;
				}
			}
		}
		else{
			if(getGrado()==0){
				std::cout<<getCoeficiente()<<std::endl;
			}
			else{
				if(getGrado()==1){
					std::cout<<getCoeficiente()<<" X"<<std::endl;
				}
				else{
					std::cout<<this->getCoeficiente()<<" X^"<<this->getGrado()<<std::endl;
				}
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Monomio

double ed::Monomio::calcularValor(double x){
	double monomio;
	return monomio=getCoeficiente()*pow(x, getGrado());
}

