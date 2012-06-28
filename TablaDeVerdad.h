#ifndef TABLADEVERDAD_H
#define TABLADEVERDAD_H

#include <vector>
using namespace std;
//! Clase TablaDeVerdad. 
/*! 
 *  \brief     Clase cromosoma
 *  \details   Define la tabla de verdad de la entrada
 *  \author    Carlos Andres Delgado
 *  \author    Edgar Andres Moncada
 *  \author    Luis Felipe Vargas
 *  \version   1.0
 *  \date      2012
 *  \copyright GNU Public License.
 */
class TablaDeVerdad
{
	public:
		//! Constructor
		/*! Constructor de la clase Cromosoma
       */
		TablaDeVerdad();
		
		//! Destructor
		/*! Destructor de la clase Cromosoma
       */
		~TablaDeVerdad();
		
		//! obtenerSalida
		/*! Obtiene una salida ante una entrada decimal de la entrada
		\param posicionDecimal es un número entero que representa la posición que se desea conocer
		\return booleano que representa el valor que toma la tabla de verdad ante la entrada especificada
        */  		
		bool obtenerSalida(int posicionDecimal);
		
		//! escribirTablaDeVerdad
		/*! Escribe una salida para la entrada en orden
		\param valor booleano que indica la entrada
        */  		
		void escribirTablaDeVerdad(bool valor);		
		
	private:
	
	    //! tablaDeVerdad
		/*!
		  Vector de booleanos que representa la tabla de verdad, la posición i representa la salida de la tabla de verdad ante una entrada con el mismo valor
		*/ 
		vector<bool> tablaDeVerdad;
};
 
#endif
