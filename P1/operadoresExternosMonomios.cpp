/*! 
   \file  operadoresExternosMonomios.cpp
	\brief Ficheros con el código de los operadores externos de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "operadoresExternosMonomios.hpp"


//  Se incluyen los operadores sobrecargados dentro del espacio de nombres ed
namespace ed 
{
	// Operadores de igualdad

	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		bool valor=((std::abs (m1.getCoeficiente() - m2.getCoeficiente()) < COTA_ERROR)   
              and (std::abs (m1.getGrado() - m2.getGrado()) < COTA_ERROR));
		#ifndef NDEBUG
			assert(valor==((std::abs (m1.getCoeficiente() - m2.getCoeficiente()) < COTA_ERROR)   
              and (std::abs (m1.getGrado() - m2.getGrado()) < COTA_ERROR)));
		#endif //NDEBUG
		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return valor;
	}

	bool operator==(ed::Monomio const & m, double &x){
		bool valor;
		
		valor=((std::abs (m.getCoeficiente()-x)<COTA_ERROR)
				and (m.getGrado()==0));
		#ifndef NDEBUG
			assert(valor==((std::abs (m.getCoeficiente()-x)<COTA_ERROR)
				and (m.getGrado()==0)));
		#endif //NDEBUG
		return valor;
	}

	bool operator==(double &x, ed::Monomio const &m){
		bool valor;
		
		valor=((std::abs (x-m.getCoeficiente())<COTA_ERROR)
			and (m.getGrado()==0));
		#ifndef NDEBUG
		 assert(valor==((std::abs (x-m.getCoeficiente())<COTA_ERROR)
			and (m.getGrado()==0)));
		#endif //NDEBUG

		return valor;
	}



	// Operadores de desigualdad

	// COMPLETAR
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		bool valor=((std::abs (m1.getCoeficiente() - m2.getCoeficiente()) > COTA_ERROR)   
              or (std::abs (m1.getGrado() - m2.getGrado()) > COTA_ERROR));
		#ifndef NDEBUG
			assert(valor==((std::abs (m1.getCoeficiente() - m2.getCoeficiente()) > COTA_ERROR)   
              or (std::abs (m1.getGrado() - m2.getGrado()) > COTA_ERROR)));
		#endif //NDEBUG
		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return valor;
	}

	bool operator!=(double &x, ed::Monomio const &m)
	{
		bool valor=((std::abs (m.getCoeficiente()-x)>COTA_ERROR)
			or (m.getGrado()!=0));
		#ifndef NDEBUG
		 assert(valor==((std::abs (m.getCoeficiente()-x)>COTA_ERROR)
			or (m.getGrado()!=0)));
		#endif //NDEBUG

		return valor;
	}

	bool operator!=(ed::Monomio const &m, double &x)
	{
		bool valor=((std::abs (x-m.getCoeficiente())>COTA_ERROR)
			or (m.getGrado()!=0));
		#ifndef NDEBUG
		 assert(valor==((std::abs (x-m.getCoeficiente())>COTA_ERROR)
			or (m.getGrado()!=0)));
		#endif //NDEBUG
		return valor;
	}

	////////////////////////////////////////////////////////////

	// Operadores unarios prefijos 

	ed::Monomio & operator+(ed::Monomio const & m)
	{
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();
		nuevo->setCoeficiente(m.getCoeficiente());
		nuevo->setGrado(m.getGrado());

		#ifndef NDEBUG //postcondicion
			assert(std::abs(m.getGrado()-nuevo->getGrado())<COTA_ERROR);
			assert(std::abs(m.getCoeficiente()-nuevo->getCoeficiente())<COTA_ERROR);
		#endif //NDEBUG
		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator-(ed::Monomio const & m)
	{
		ed::Monomio *nuevo = new ed::Monomio();
		nuevo->setCoeficiente(-m.getCoeficiente());
		nuevo->setGrado(m.getGrado());

		#ifndef NDBUG //postcondicion
			assert(std::abs(m.getGrado()-nuevo->getGrado())<COTA_ERROR);
			assert(std::abs(m.getCoeficiente()+nuevo->getCoeficiente())<COTA_ERROR);
		#endif //NDEBUG

		return *nuevo;
	}

	////////////////////////////////////////////////////////////
	// Operadores aritméticos binarios

	// Suma
	ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		// Se crea un nuevo objeto
		#ifndef NDEBUG //precondicion
			assert(std::abs(m1.getGrado()-m2.getGrado())<COTA_ERROR);
		#endif //NDEBUG

		ed::Monomio *nuevo = new ed::Monomio();
		nuevo->setCoeficiente(m1.getCoeficiente()+m2.getCoeficiente());
		nuevo->setGrado(m1.getGrado());

		#ifndef NDEBUG //postcondicion
			assert((std::abs(nuevo->getGrado()-m1.getGrado())<COTA_ERROR) 
				and (std::abs(nuevo->getGrado()-m2.getGrado())<COTA_ERROR));
			assert(std::abs(nuevo->getCoeficiente()-(m1.getCoeficiente()+m2.getCoeficiente()))<COTA_ERROR);
		#endif //NDEBUG
		// Se devuelve el resultado
		return *nuevo;
	}


	////////////
	// Resta
	ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		// Se crea un nuevo objeto
		#ifndef NDEBUG //precondicion
			assert(std::abs(m1.getGrado()-m2.getGrado())<COTA_ERROR);
		#endif //NDEBUG

		ed::Monomio *nuevo = new ed::Monomio();
		nuevo->setCoeficiente(m1.getCoeficiente()-m2.getCoeficiente());
		nuevo->setGrado(m1.getGrado());

		#ifndef NDEBUG //postcondicion
			assert((std::abs(nuevo->getGrado()-m1.getGrado())<COTA_ERROR) 
				and (std::abs(nuevo->getGrado()-m2.getGrado())<COTA_ERROR));
			assert(std::abs(nuevo->getCoeficiente()-(m1.getCoeficiente()-m2.getCoeficiente()))<COTA_ERROR);
		#endif //NDEBUG
		// Se devuelve el resultado
		return *nuevo;
	}



	//////////////////
	// Multiplicación
	ed::Monomio & operator* (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();
		nuevo->setCoeficiente(m1.getCoeficiente()*m2.getCoeficiente());
		nuevo->setGrado(m1.getGrado()+m2.getGrado());

		#ifndef NDEBUG //postcondicion
			assert(std::abs(nuevo->getGrado()-(m1.getGrado()+m2.getGrado()))<COTA_ERROR);
			assert(std::abs(nuevo->getCoeficiente()-(m1.getCoeficiente()*m2.getCoeficiente()))<COTA_ERROR);
		#endif //NDEBUG
		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator* (ed::Monomio const &m, double &x)
	{
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();
		nuevo->setCoeficiente(m.getCoeficiente()*x);
		nuevo->setGrado(m.getGrado());

		#ifndef NDEBUG //postcondicion
			assert(std::abs(nuevo->getGrado()-m.getGrado())<COTA_ERROR);
			assert(std::abs(nuevo->getCoeficiente()-(m.getCoeficiente()*x))<COTA_ERROR);
		#endif //NDEBUG
		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator* (double &x, ed::Monomio const &m)
	{
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();
		nuevo->setCoeficiente(x*m.getCoeficiente());
		nuevo->setGrado(m.getGrado());

		#ifndef NDEBUG //postcondicion
			assert((std::abs(nuevo->getGrado()-m.getGrado())<COTA_ERROR));
			assert(std::abs(nuevo->getCoeficiente()-(x*m.getCoeficiente()))<COTA_ERROR);
		#endif //NDEBUG
		// Se devuelve el resultado
		return *nuevo;
	}

	////////////
	// División

	ed::Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		// Se crea un nuevo objeto
		#ifndef NDEBUG //precondicion
			assert(m2.getGrado()<=m1.getGrado());
			assert(m2.getCoeficiente()!=0.0);
		#endif //NDEBUG

		ed::Monomio *nuevo = new ed::Monomio();
		nuevo->setCoeficiente(m1.getCoeficiente()/m2.getCoeficiente());
		nuevo->setGrado(m1.getGrado()-m2.getGrado());

		#ifndef NDEBUG //postcondicion
			assert(std::abs(nuevo->getGrado()-(m1.getGrado()-m2.getGrado()))<COTA_ERROR);
			assert(std::abs(nuevo->getCoeficiente()-(m1.getCoeficiente()/m2.getCoeficiente()))<COTA_ERROR);
		#endif //NDEBUG
		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator/ (ed::Monomio const &m, double &x)
	{
		// Se crea un nuevo objeto
		#ifndef NDEBUG //precondicion
			assert(x!=0.0);
		#endif //NDEBUG

		ed::Monomio *nuevo = new ed::Monomio();
		nuevo->setCoeficiente(m.getCoeficiente()/x);
		nuevo->setGrado(m.getGrado());

		#ifndef NDEBUG //postcondicion
			assert(std::abs(nuevo->getGrado()-m.getGrado())<COTA_ERROR);
			assert(std::abs(nuevo->getCoeficiente()-(m.getCoeficiente()/x))<COTA_ERROR);
		#endif //NDEBUG
		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator/ (double &x, ed::Monomio const &m)
	{
		// Se crea un nuevo objeto
		#ifndef NDEBUG //precondicion
			assert(m.getGrado()==0);
			assert(m.getCoeficiente()!=0.0);
		#endif //NDEBUG

		ed::Monomio *nuevo = new ed::Monomio();
		nuevo->setCoeficiente(x/m.getCoeficiente());
		nuevo->setGrado(0);

		#ifndef NDEBUG //postcondicion
			assert(nuevo->getGrado()==0);
			assert(std::abs(nuevo->getCoeficiente()-(x/m.getCoeficiente()))<COTA_ERROR);
		#endif //NDEBUG
		// Se devuelve el resultado
		return *nuevo;
	}


	/////////////////////////////////////////////////////////////////////////////

	//  Sobrecarga del operador de entrada
	istream &operator>>(istream &stream, ed::Monomio &m) 
	{
		double a;
		int b;
		stream>>a;
		stream>>b;
		m.setCoeficiente(a);
		m.setGrado(b);

   		// Se devuelve el flujo de entrada
		return stream;
	}


	//  Sobrecarga del operador de salida
	ostream &operator<<(ostream &stream, ed::Monomio const &m) 
	{
		stream<<m.getCoeficiente()<<" "<<m.getGrado()<<std::endl;

		// Se devuelve el flujo de salida
		return stream;
	}


}  // namespace ed
