/*! 
	\file Monomio.hpp
	\brief Definición de la clase Monomio
*/

#ifndef _MONOMIO_HPP_
#define _MONOMIO_HPP_

// Para usar la funciones pow y std::abs
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

#define COTA_ERROR 1.0e-6  //!< Cota de error para la comparación números reales

// Se incluye la clase Monomio dentro del espacio de nombre de la asigantura: ed
namespace ed
{
//!  Definición de la clase Monomio:  \f$ coeficiente \hspace{1ex} X^{grado} \f$ 
class Monomio
{
	//! \name Atributos privados de la clase Monomio
	private:

		double coeficiente_;
		int grado_;

	//! \name Funciones o métodos públicos de la clase Monomio
	public:

	//! \name Constructores de la clase Monomio

		inline Monomio(const double& coeficiente=0.0, const int& grado=0){
			//Se comprueba la precondicion
			#ifndef NDEBUG
				assert(grado>=0);
			#endif	
				setCoeficiente(coeficiente);
				setGrado(grado);
			
			#ifndef NDEBUG
			// Se comprueba la postcondicion
				assert( std::abs (this->getCoeficiente() - coeficiente) < COTA_ERROR ); 
				assert( std::abs (this->getGrado() - grado) < COTA_ERROR ); 
			#endif //NDEBUG
		};
		
		inline Monomio(Monomio const &m){
			setCoeficiente(m.getCoeficiente());
			setGrado(m.getGrado());
		#ifndef NDEBUG
			// Se comprueba la postcondicion
			assert(std::abs (this->getCoeficiente() - m.getCoeficiente()) < COTA_ERROR); 
			assert(std::abs (this->getGrado() - m.getGrado()) < COTA_ERROR);   
		#endif //NDEBUG
		};


	//! \name Observadores: funciones de consulta de la clase Monomio

		inline double getCoeficiente()const{return coeficiente_;};
		inline int getGrado()const{return grado_;};



	//! \name Funciones de modificación de la clase Monomio

		inline void setCoeficiente(double x){
			coeficiente_=x;
			#ifndef NDEBUG
				// Se comprueba la postcondicion
				assert(std::abs (this->getCoeficiente() - x) < COTA_ERROR); 
			#endif //NDEBUG
		};
		inline void setGrado(int n){
			#ifndef NDEBUG
				assert(n>=0);
			#endif
				grado_=n;
			#ifndef NDEBUG
			// Se comprueba la postcondicion
				assert(std::abs (this->getGrado() - n) < COTA_ERROR); 
			#endif //NDEBUG
		};

	/////////////////////////////////////////////////

	//! \name Operadores de la clase Monomio

	// Operadores de asignación

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	/*!
		\brief Asigna los atributos del monomio m al monomio actual
		\param m
		\post El coeficiente del monomio es igual al coeficiente del monomio m
		\post El grado del monomio es igual al grado del monomio m
		\return Devuelve el monomio actual
	*/
		Monomio & operator=(Monomio const &m);

	/*!
		\brief Asigna un valor real al monomio actual 
		\param x
		\post El grado del monomio es igual a 0
		\post El coeficie4nte del monomio es igual al numero real x
		\return Devuelve el monomio actual
	*/
		Monomio & operator=(double const &x);


	// Operadores aritméticos y asignación

	/*!
		\brief Suma de monomios del mismo grado
		\param m
		\pre El monomio m tiene el mismo grado que el monomio actual
		\post EL coeficiente del monomio actual se ha incrementado con el coeficiente del monomio m
		\post El grado del monomio actual no ha cambiado
		\return Devuelve el monomio actual                                
	*/
		Monomio & operator+=(Monomio &m);

	/*!
		\brief Resta de monomios del mismo grado
		\param m
		\pre El monomio m tiene el mismo grado que el monomio actual
		\post El coeficiente del monomio actual se ha decrementado con el coeficiente del monomio m
		\post El grado del monomio actual no se ha modificado
		\return Devuelve el monomio actual                                
	*/
		Monomio & operator-=(Monomio &m);

	/*!
		\brief Multiplicacion del monomio actual con el monomio m
		\param m
		\post El coeficiente del monomio actual se ha multiplicado por el coeficiente del monomio m
		\post El grado del monomio actual se ha incrementado con el grado del monomio m
		\return Devuelve el monomio actual                                
	*/
		Monomio & operator*=(Monomio &m);

	/*!
		\brief Division del monomio actual con el monomio m
		\param m
		\pre El grado del monomio m es igual o inferior al grado del monomio actual
		\pre El coeficiente del monomios m no es 0.0
		\post El coeficiente del monomio actual se ha decrementado con el coeficiente del monomio m
		\post El grado del monomio actual se ha incrementado con el grado del monomio m
		\return Devuelve el monomio actual                                
	*/
		Monomio & operator/=(Monomio &m);

	/*!
		\brief Multiplicacion del monomio actual por un numero real
		\param x
		\post El coeficiente del monomio actual se ha multiplicado por el número real x
		\post El grado del monomio actual no ha sido modificado
		\return Devuelve el monomio actual                                
	*/
		Monomio & operator*=(double &x);

	/*!
		\brief Dvision del monomio actual con un numero real
		\param x
		\pre El numero real x no es 0.0
		\post El coeficiente del monomio actual se ha dividido por el número real x
		\post El grado del monomio actual no ha sido modificado
		\return Devuelve el monomio actual                                
	*/
		Monomio & operator/=(double &x);


	/////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Monomio

	/*!
		\brief Lee desde el teclado los atributos del monomio
		\post El grado del monomio es mayor o igual a 0
		\return No devuelve nada                              
	*/
		void leerMonomio();

	/*!
		\brief Escribe por pantalla los atributos del monomio
		\return No devuelve nada                              
	*/
		void escribirMonomio();


	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Monomio

	/*!
		\brief Calcula el valor del monomio para un valor real dado
		\param x
		\return Devuelve un numero real                              
	*/
		double calcularValor(double x);



};  // Fin de la definición de la clase Monomio

}  //  Fin de namespace ed.

// _MONOMIO_HPP_
#endif
