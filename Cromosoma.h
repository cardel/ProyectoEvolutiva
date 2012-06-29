#ifndef CROMOSOMA_H
#define CROMOSOMA_H
#include <string>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
//! Clase cromosoma. 
/*! 
 *  \brief     Clase cromosoma
 *  \details   Define un cromosoma como una matriz, donde la fila representa una claúsula y la columna el estado de una variable y su negada
 *  \author    Carlos Andres Delgado
 *  \author    Edgar Andres Moncada
 *  \author    Luis Felipe Vargas
 *  \version   1.0
 *  \date      2012
 *  \copyright GNU Public License. *  
 */

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

		//! get
		/*! Obtiene un elemento específico de una claúsula
		\param x es un número entero que indica la claúsula deseada
		\param y es número entero que indica la variable deseada (recordar que están duplicada) normal y negada
       */		
		bool get(int x, int y);

		//! getClausula
		/*! Obtiene una claúsula
		\param x es un número entero que indica la claúsula deseada
       */			
		vector<bool> getClausula(int x);
		
		//! set
		/*! Obtiene un elemento específico de una claúsula
		\param x es un número entero que indica la claúsula deseada
		\param y es número entero que indica la variable deseada (recordar que están duplicada) normal y negada
		\param z es booleano que indica el valor de la variable y deseada en la claúsula x
       */	
		void set(int x, int y, bool z);	
	
		//! setClausula
		/*! Obtiene un elemento específico de una claúsula
		\param x es un número entero que indica la claúsula deseada
		\param z es un vector<bool> que indica la nueva clausula en la posicion x
       */       
		void setClausula(int x, vector<bool> z);
			
 		//! getNumeroClausulas
		/*! Retorna el número de claúsulas que tiene el cromosoma
       */
        int getNumeroClausulas();

        //! getNumeroClausulas
        /*! elimina la claúsula x del cromosoma y reduce en 1 el numeroClausulas
        \param x es un número entero que indica la claúsula a eliminar
       */
        void deleteClausula(int x);
        	
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
		//! evaluarCromosoma
		/*! Evalua el cromosoma ante todas las entradas posibles.
       */		
		void evaluarCromosoma();		
	private:
	    //! numeroClausulas
		/*!
		  Entero que almacena el número de claúsulas del cromosoma.
		*/    
		int numeroClausulas;
		
	    //! numeroVariables
		/*!
		  Entero que almacena el número de variables del cromosoma.
		*/    
		int numeroVariables;
		
        //! numeroVariablesARepresentar
		/*!
		  Entero que almacena el número de variables y su representación negada del cromosoma.
		*/    
		int numeroVariablesARepresentar;
		
         //! numeroEntrada
		/*!
		  Entero que almacena el número de posibles entradas que puede tener el cromosoma es 2^(numerovariables).
		*/   
		int numeroEntrada;
		
	    //! estadoCromosoma
		/*!
		  Vector de arreglos de booleanos que almacena cada claúsula y los posibles valores de cada variable.
		*/ 		
		vector<bool *> estadoCromosoma;
		
	    //! cromosomaEvaluado
		/*!
		  Vector de booleanos que almacena la salida del cromosoma evaluado ante todos los posibles valores de entrada 
		*/ 	
		vector<bool> cromosomaEvaluado;
		
	    //! usarMaxiTerminos
		/*!
		  Indica si se va usar representación de maxitérminos o minitérminos
		*/ 	
		bool usarMaxiTerminos;
		
		//! GenerarIndividuo
		/*! Genera los valores de cada variable en cada claúsula en la clase Cromosoma
       */
		void GenerarIndividuo();	
			

		
		//! decimalABinario
		/*! Genera una representación booleana de un número entero (Función auxiliar)
		\param number es un número entero que representa el número decimal a convertir a binario
		\return string que es la representación binaria de un número entero
       */			
		string decimalABinario(int number);
		
		//! aptitud
		/*! Almacena la aptitud calculada del cromosoma
       */		
        double aptitud;
};
 
#endif
