/*! 
	\file operadoresExternosMonomios.hpp
	\brief Ficheros con los prototipos de los operadores externos de la clase Monomio
*/

#ifndef _OperadoresExternosMonomios_HPP_
#define _OperadoresExternosMonomios_HPP_

// Facilita la entrada y salida
#include <iostream>

#include "Monomio.hpp"

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

// Espacio de nombre de la asigantura: ed
namespace ed
{
//////////////////////////////////////////////////////////////////////////////////////
	// Operadores externos que no pertenecen a la clase Monomio

	//! \name Operadores de igualdad  

	/*!
		\brief Compara la igualdad entre dos monomios
		\param m1
		\param m2
		\return Devuelve true o false
	*/
	bool operator==(ed::Monomio & m1, ed::Monomio & m2);

	/*!
		\brief Compara la igualdad entre un monomio y un numero real
		\param m
		\param x
		\return Devuelve true o false
	*/
	bool operator==(ed::Monomio const & m, double &x);

	/*!
		\brief Compara la igualdad entre un numero real y un monomio
		\param x
		\param m
		\return Devuelve true o false
	*/
	bool operator==(double &x, ed::Monomio const & m);


	//! \name Operadores de desigualdad 

	/*!
		\brief Compara la igualdad entre dos monomios
		\param m1
		\param m2
		\return Devuelve true o false
	*/
	bool operator!=(ed::Monomio & m1, ed::Monomio & m2);

	/*!
		\brief Compara la igualdad entre un monomio y un numero real
		\param m
		\param x
		\return Devuelve true o false
	*/
	bool operator!=(ed::Monomio const & m, double &x);

	/*!
		\brief Compara la igualdad entre un numero real y un monomio
		\param x
		\param m
		\return Devuelve true o false
	*/
	bool operator!=(double &x, ed::Monomio const & m);

	///////////////////////////////////////////////////

	//! \name Operadores unarios prefijos

	/*!
		\brief Crea una copia del monomio
		\param m
		\return Devuelve la copia del monomio tal y como estaba
	*/
	ed::Monomio & operator+(ed::Monomio const & m);

	/*!
		\brief Crea una copia del opuesto del monomio
		\param m
		\return Devuelve una copia del monomio con su opuesto
	*/
	ed::Monomio & operator-(ed::Monomio const & m);


	//////////////////////////////////////////////////////////

	//! \name Operador binario de la suma 
	/*!
		\brief Suma dos monomios
		\param m1
		\param m2
		\return Devuelve un monomio con la suma
	*/

	 ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2);
	//////////////////////////////////////////////////////////
	//! \name Operador binario de la resta 
	/*!
		\brief Resta dos monomios
		\param m1
		\param m2
		\return Devuelve un monomio con la resta
	*/
	 ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2);
	

	///////////////////////////////////////////////////////////////////////////
	//! \name Operadores binarios de la multiplicación 
	/*!
		\brief Multiplica dos monomios
		\param m1
		\param m2
		\return Devuelve un monomio con la multiplicacion
	*/
	 ed::Monomio & operator* (ed::Monomio const &m1, ed::Monomio const &m2);

	/*!
		\brief Multiplica un monomio y un numero real
		\param m
		\param x
		\return Devuelve un monomio con la multiplicacion
	*/
	 ed::Monomio & operator* (ed::Monomio const &m, double &x);

	/*!
		\brief Multiplica un numero real y un monomio
		\param x
		\param m
		\return Devuelve un monomio con la multiplicacion
	*/
	 ed::Monomio & operator* (double &x, ed::Monomio const & m);

	///////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la división 

	/*!
		\brief Divide dos monomios
		\param m1
		\param m2
		\return Devuelve un monomio con la division
	*/
	 ed::Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2);

	/*!
		\brief Divide un monomio y un numero real
		\param m
		\param x
		\return Devuelve un monomio con la division
	*/
	 ed::Monomio & operator/ (ed::Monomio const &m, double &x);

	/*!
		\brief Divide un numero real y un monomio
		\param x
		\param m
		\return Devuelve un monomio con la division
	*/
	 ed::Monomio & operator/ (double &x, ed::Monomio const & m);


	/////////////////////////////////////////////////////////////////////////////

	//! \name Sobrecarga de los operadores de entrada y salida 

	/*!
		\brief Lee desde el flujo de entrada
		\param stream
		\param m
		\return Devuelve un flujo de entrada
	*/
	 istream &operator>>(istream &stream, ed::Monomio &m);


	/*!
		\brief Escribe en el flujo de salida
		\param stream
		\param m
		\return Devuelve un flujo de salida
	*/
	 ostream &operator<<(ostream &stream, ed::Monomio const &m);

}  // Fin de namespace ed.

#endif // _OperadoresExternosMonomios_HPP_


