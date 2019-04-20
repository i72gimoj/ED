/*!
  \file   operacionAmpliacionMonomio.hpp
  \brief  Operaciones de ampliacion para el programa principal de la práctica 1
  \author Javier Gil Moya
  \date  25-02-2019
*/


#ifndef _OperacionAmpliacionMonomio_HPP_
#define _OperacionAmpliacionMonomio_HPP_

#include <iostream>
#include "Monomio.hpp"

namespace ed{

	/*!
		\brief Realiza la potencia de un monomios con un entero como parametro
		\param m
		\param x
		\pre El grado de la potencia es diferente de 0
		\post El grado del monomio se ha modificado
		\post El coeficiente del monomio se ha modificado
		\return Devuelve un monomio con el resultado de la potencia
	*/
	ed::Monomio & potenciaMonomios(ed::Monomio const & m, int x);


}

#endif // _OperacionAmpliacionMonomio_HPP_