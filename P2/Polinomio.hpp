/*!
   \file Polinomio.hpp
   \brief Definición de la clase Polinomio
*/

#ifndef _POLINOMIO_HPP_
#define _POLINOMIO_HPP_

// Control de asertos
#include <cassert>

// Vector de STL
#include <vector>

// Para usar la función abs
#include <cmath>

#include "PolinomioInterfaz.hpp"
#include "operadoresExternosMonomios.hpp"


// Se incluye la clase Polinomio dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Polinomio que hereda de PolinomioInterfaz
class Polinomio: public ed::PolinomioInterfaz
{

  //! \name Atributos privados de la clase Polinomio
	private:

   		std::vector <Monomio> polinomio_;

   //! \name Funciones o métodos públicos de la clase Polinomio
	public:

		//! \name Constructores de la clase Polinomio
	   	inline Polinomio(){
			this->polinomio_.clear();
	   		ed::Monomio m(0.0, 0);
			this->polinomio_.push_back(m);
			
			#ifndef NDEBUG
			// Se comprueba la postcondicion
				assert(this->esNulo());
			#endif //NDEBUG
		};
	  	inline Polinomio(Polinomio &p){
			this->polinomio_=p.polinomio_;
			#ifndef NDEBUG
			// Se comprueba la postcondicion
	  			for(int i=0; i<p.getNumeroMonomios(); i++){
					assert(this->polinomio_[i]==p.polinomio_[i]);
				}
			#endif //NDEBUG
	  	};

	  //! \name Observadores: funciones de consulta de la clase Polinomio

		inline bool esNulo()const{
			if(this->getNumeroMonomios()==1){
				if(this->polinomio_[0].getCoeficiente()==0.0 && this->polinomio_[0].getGrado()==0)
					return true;
				else{return false;}
			}
			else
				return false;
		};

		inline int getGrado()const{
			//Precondicion
			#ifndef NDEBUG
				for(int i=0; i<this->getNumeroMonomios(); i++)
					assert(this->polinomio_.front().getGrado() >= polinomio_[i].getGrado());
			#endif //NDEBUG

			return this->polinomio_.front().getGrado();
		};

		inline int getNumeroMonomios() const {
			return this->polinomio_.size();
		};

		inline bool existeMonomio(int n)const{
			//PRECONDICION
			#ifndef NDEBUG
				assert(not this->esNulo());
			#endif //NDEBUG

			for(int i=0; i<this->getNumeroMonomios(); i++){
				if(this->polinomio_[i].getGrado()==n){
					return true;
				}
				else{return false;}
			}
			return false;
		};

		inline ed::Monomio & getMonomio(int n){
			//Precondicion
			#ifndef NDEBUG
				assert((existeMonomio(n)) and (not this->esNulo()));
			#endif //NDEBUG

			ed::Monomio *m =  new ed::Monomio();

			for(int i=0; i<getNumeroMonomios(); i++)
				if(this->polinomio_[i].getGrado()==n)
					*m=this->polinomio_[i];
			return *m;
		};

		inline bool estaOrdenado() const{
      		#ifndef NDEBUG
        		assert(!this->esNulo());
      		#endif //NDEBUG

      		for( int i = 0; i < this->getNumeroMonomios()-1; i++){
        		if( this->polinomio_[i].getGrado() <= this->polinomio_[i+1].getGrado() )
          			return false;
				else
					return true;
			}
      		return true;
    	};

		inline Monomio & getMonomioPolinomio(int x){
			//Precondicion
      		#ifndef NDEBUG
        		assert( this->esNulo() == false );
      		#endif

      		return this->polinomio_[x];
   		};

		void ordenaPolinomio();


	 	////////////////////////////////////////////////////////////////

	   //! \name Operadores de la clase Polinomio

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		Polinomio & operator=(Polinomio const &p);

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		Polinomio & operator=(Monomio const &m);

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		Polinomio & operator=(double const &x);

	  // Operadores aritméticos y asignación

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		Polinomio & operator+=(Polinomio &p);

		Polinomio & operator+=(Monomio const &m);

		Polinomio & operator+=(double const &x);


		Polinomio & operator-=(Polinomio &p);

		Polinomio & operator-=(Monomio &m);

		Polinomio & operator-=(double const &x);


		Polinomio & operator*=(Polinomio &p);

		Polinomio & operator*=(Monomio const &m);

		Polinomio & operator*=(double const &x);


		Polinomio & operator/=(Polinomio &p);

		Polinomio & operator/=(Monomio const &m);

		Polinomio & operator/=(double const &x);


	  /////////////////////////////////////////////////////////////////////////////////////

		//! \name Funciones lectura y escritura de la clase Polinomio

		void leerPolinomio();

		void escribirPolinomio();


		///////////////////////////////////////////////////////////////////////

		//! \name Funciones auxiliares de la clase Polinomio
		double calcularValor(double &x);


}; // Fin de la definición de la clase Polinomio

} // \brief Fin de namespace ed.

//  _POLINOMIO_HPP_
#endif
