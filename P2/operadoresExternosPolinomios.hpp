/*!
	\file operadoresExternosPolinomios.hpp
	\brief Ficheros con operadores de monomios y polinomios
*/

#ifndef _OperadoresPolinomios_HPP_
#define _OperadoresPolinomios_HPP_

// Facilita la entrada y salida
#include <iostream>

#include "Polinomio.hpp"

using std::istream;
using std::ostream;

// Espacio de nombre de la asigantura: ed
namespace ed
{

////////////////////////////////////////////////////////////////////////////
	// Funciones y operadores que no pertenecen a la clase Polinomio


	////////////////////////////////////////////////////////////
	//! \name Operadores de igualdad

	/*!
		\brief Compara la igualdad entre dos polinomios
		\param p1
		\param p2
		\return Devuelve true o false
	*/
	bool operator==(ed::Polinomio & p1, ed::Polinomio & p2);

	/*!
		\brief Compara la igualdad entre un polinomio y un monomio
		\param p
		\param m
		\return Devuelve true o false
	*/
	bool operator==(ed::Polinomio & p, ed::Monomio & m);

	/*!
		\brief Compara la igualdad entre un monomio y un polinomio
		\param m
		\param p
		\return Devuelve true o false
	*/
	bool operator==(ed::Monomio & m, ed::Polinomio & p);

	/*!
		\brief Compara la igualdad entre un monomio y un real
		\param m
		\param p
		\return Devuelve true o false
	*/
	bool operator==(ed::Polinomio & p, double x);

	/*!
		\brief Compara la igualdad entre un real y un polinomio
		\param p
		\param x
		\return Devuelve true o false
	*/
	bool operator==(double x, ed::Polinomio & p);


	////////////////////////////////////////////////////////////////////////////////////
	//! \name Operadores de desigualdad

	/*!
		\brief Compara la desigualdad entre dos polinomios
		\param p1
		\param p2
		\return Devuelve true o false
	*/
	bool operator!=(ed::Polinomio & p1, ed::Polinomio & p2);

	/*!
		\brief Compara la desigualdad entre un polinomio y un monomio
		\param p
		\param m
		\return Devuelve true o false
	*/
	bool operator!=(ed::Polinomio & p, ed::Monomio & m);

	/*!
		\brief Compara la desigualdad entre un monomio y un polinomio
		\param m
		\param p
		\return Devuelve true o false
	*/
	bool operator!=(ed::Monomio & m, ed::Polinomio & p);

	/*!
		\brief Compara la desigualdad entre un monomio y un real
		\param m
		\param p
		\return Devuelve true o false
	*/
	bool operator!=(ed::Polinomio & p, double x);

	/*!
		\brief Compara la desigualdad entre un real y un polinomio
		\param p
		\param x
		\return Devuelve true o false
	*/
	bool operator!=(double x, ed::Polinomio & p);

//////////////////////////////////////////////////////////////////////////////////////

	//! \name Operadores unarios

		/*!
			\brief Crea una copia del polinomio
			\param m
			\return Devuelve la copia del polinomio tal y como estaba
		*/
		ed::Polinomio & operator+(ed::Polinomio & p);

	// COMPLETAR EL OTRO OPERADOR UNARIO PREFIJO: resta
		/*!
			\brief Crea una copia del opuesto del polinomio
			\param m
			\return Devuelve la copia del opuesto del polinomio
		*/
		ed::Polinomio & operator-(ed::Polinomio & p);

//////////////////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la suma

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		ed::Polinomio & operator+(ed::Polinomio const &p1,  ed::Polinomio const &p2);

		ed::Polinomio & operator+(ed::Polinomio const & p, ed::Monomio const & m);

		ed::Polinomio & operator+(ed::Monomio const & m, ed::Polinomio const & p);

		ed::Polinomio & operator+(ed::Polinomio const & p, double x);

		ed::Polinomio & operator+(double x, ed::Polinomio const & p);


		//////////////////////////////////////////////////////////
		//! \name Operador binario de la resta

		ed::Polinomio & operator-(ed::Polinomio const &p1,  ed::Polinomio const &p2);

		ed::Polinomio & operator-(ed::Polinomio const & p, ed::Monomio const & m);

		ed::Polinomio & operator-(ed::Monomio const & m, ed::Polinomio const & p);

		ed::Polinomio & operator-(ed::Polinomio const & p, double x);

		ed::Polinomio & operator-(double x, ed::Polinomio const & p);


		///////////////////////////////////////////////////////////////////////////
		//! \name Operadores binarios de la multiplicación

		ed::Polinomio & operator*(ed::Polinomio const &p1,  ed::Polinomio const &p2);

		ed::Polinomio & operator*(ed::Polinomio const & p, ed::Monomio const & m);

		ed::Polinomio & operator*(ed::Monomio const & m, ed::Polinomio const & p);

		ed::Polinomio & operator*(ed::Polinomio const & p, double x);

		ed::Polinomio & operator*(double x, ed::Polinomio const & p);

		///////////////////////////////////////////////////////////////////////////

		//! \name Operadores binarios de la división

		ed::Polinomio & operator/(ed::Polinomio const &p1,  ed::Polinomio const &p2);

		ed::Polinomio & operator/(ed::Polinomio const & p, ed::Monomio const & m);

		ed::Polinomio & operator/(ed::Monomio const & m, ed::Polinomio const & p);

		ed::Polinomio & operator/(ed::Polinomio const & p, double x);

		ed::Polinomio & operator/(double x, ed::Polinomio const & p);

	/////////////////////////////////////////////////////////////////////////////

   //! \name Sobrecarga de los operadores de flujo de la clase Polinomio.

    // COMPLETAR LOS COMENTARIOS DE DOXYGEN
    ostream &operator<<(ostream &stream, ed::Polinomio &p);

    // COMPLETAR LOS COMENTARIOS DE DOXYGEN
    istream &operator>>(istream &stream, ed::Polinomio &p);

}  // Fin de namespace ed.

#endif // _OperadoresPolinomios_HPP_
