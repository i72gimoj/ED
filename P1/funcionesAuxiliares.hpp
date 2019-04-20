/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 1
  \author Javier Gil Moya
  \date  25-02-2019
*/


#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

namespace ed
{
	/*! 
		\fn int menu ()
		\brief   Muestra el menú del programa principal 
		\return  Devuelve el número de opción elegido
	*/
	int menu();

	/*!
		\fn void testMonomio ()
		\brief Realiza las pruebas de la clase Monomio
		\return No devuelve nada
	*/
	void testMonomio();


	/*!
		\fn void operadoresExternosMonomios ()
		\brief Realiza las pruebas de operadores externos de la clase Monomios
		\return No devuelve nada
	*/
	void operadoresExternosMonomios();

} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif

