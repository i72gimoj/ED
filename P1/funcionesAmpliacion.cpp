/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares para el programa principal de la práctica 1
*/

#include <iostream>
#include <string>
#include <cmath>

#include "macros.hpp"
#include "funcionesAmpliacion.hpp"
#include "Monomio.hpp"
#include "operadoresExternosMonomios.hpp"

void ed::operacionAmpliacionMonomio()
{
	int x;

	//Constructor sin argumentos
	ed::Monomio m1;
	ed::Monomio coeficiente(m1);

	int grado;

	// Lectura y escritura de un número
	std::cout << BIGREEN;
	std::cout<< "Introduzca un número real" << std::endl;
	std::cout << RESET;
	std::cout<< "x --> ";
	std::cin >> x;

	// Lectura y escritura usando funciones de la clase Monomio
	std::cout << BIGREEN;
	std::cout<< "Lectura y escritura"<< std::endl << std::endl;
	std::cout << RESET;
	m1.leerMonomio();
	std::cout << std::endl;

	std::cout<< "Escritura de los monomios"<< std::endl << std::endl;
	std::cout<< "m1 = ";
	m1.escribirMonomio();
	std::cout << std::endl << std::endl;

	std::cout << "Para continuar, pulse ";
	std::cout << INVERSE ;
	std::cout << "ENTER";
	std::cout << RESET;

	// Pausa
	std::cin.ignore();

	// Potencia enesima
	std::cout << BIYELLOW;
	std::cout<< "Potencia de un monomio"<< std::endl<< std::endl;
	std::cout << RESET;

	std::cout<< "Potencia (m1)^x"<<std::endl;
    std::cout << "resultado = ";
    m1.getCoeficiente();
    m1.getGrado();
    coeficiente = std::pow(m1.getCoeficiente(), x);
    grado = m1.getGrado()*x;
    std::cout <<"(" << m1.getCoeficiente() << "^" << m1.getGrado() << ") X^ "<< x << " = ";
    coeficiente.escribirMonomio();
    std::cout<<"X^"<<grado;
    std::cout<<std::endl;

	return;

}
