/*! 
   \file  operacionAmpliacionMonomio.cpp
	\brief Ficheros con el código de los operaciones de ampliacion de la clase Monomio
*/

#include "operacionAmpliacionMonomio.hpp"

#include <cmath>

namespace ed{
	
	ed::Monomio & potenciaMonomios(ed::Monomio const &m, int x){
		//Precondicion
		#ifndef NDEBUG
			assert(x!=0);
		#endif //NDEBUG

		ed::Monomio *nuevo = new ed::Monomio();
		std::cout<<"coeficiente elevado = "<<pow(m.getCoeficiente(), x)<<std::endl;
		nuevo->setCoeficiente(std::pow(m.getCoeficiente(),x));
		nuevo->setGrado(m.getCoeficiente()*x);

		//Postcondicion
		#ifndef NDEBUG
			assert(std::abs(nuevo->getGrado()-(m.getGrado()*x))<COTA_ERROR);
			assert(std::abs(nuevo->getCoeficiente()-(std::pow(m.getCoeficiente(),x)))<COTA_ERROR);
		#endif //NDEBUG

		return *nuevo;
	}


}//namespace ed
