//! Clase cromosoma. 
/*!
  Define un cromosoma como una matriz, donde la fila representa una claúsula y la columna el estado de una variable y su negada
*/
#ifndef CROMOSOMA_H
#define CROMOSOMA_H
#include <string>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Cromosoma
{
	public:
		//! Constructor
		/*! Constructor de la clase Cromosoma
		\param numClausulas es un número entero que representa el número de claúsulas que tendrá el cromosoma
		\param numVariables es número entero que representa el número de variable y su negada que tendrá el cromosoma
       */
		Cromosoma(int numClausulas, int numVariables, bool maxiTerminos);
		//! Destructor
		/*! Destructor de la clase Cromosoma
       */
		~Cromosoma();

		
		bool get(int x, int y);
		void set(int x, int y, bool z);
		
 		//! getNumeroClausulas
		/*! Retorna el número de claúsulas que tiene el cromosoma
        */		
		int getNumeroClausulas();
 		//! getNumeroVariables
		/*! Retorna el número de variables que tiene cada claúsula en el cromosoma
        */	
		int getNumeroVariables();
		
		//! obtenerSalida
		/*! Obtiene una salida ante una entrada decimal de un cromosoma (En cualquier representación, maxitérminos o minitérminos)
		\param posicionDecimal es un número entero que representa la posición que se desea conocer
		\return booleano que representa el valor que toma la función ante la entrada especificada
        */        
        bool obtenerSalida(int posicionDecimal);
        
		//! getAptitud
		/*! Obtiene la aptitud que tiene el cromosoma
		\return double que representa el valor de la aptitud del cromosoma
        */        
        double getAptitud();
        
 		//! setAptitud
		/*! Establece la aptitud que tiene el cromosoma
        */
        void setAptitud(double value);
		
	private:
		int numeroClausulas;
		int numeroVariables;
		int numeroVariablesARepresentar;
		int numeroEntrada;
		
		vector<bool *> estadoCromosoma;
		vector<bool> cromosomaEvaluado;
		bool usarMaxiTerminos;
		
		//! GenerarIndividuo
		/*! Genera los valores de cada variable en cada claúsula en la clase Cromosoma
		\param numClausulas es un número entero que representa el número de claúsulas que tendrá el cromosoma
		\param numVariables es número entero que representa el número de variable y su negada que tendrá el cromosoma
		\return The test results
       */
		void GenerarIndividuo();		
		
		void evaluarCromosoma();
		
		string decimalABinario(int number);
        double aptitud;
};
 
#endif
