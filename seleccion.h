#ifndef SELECCION_H
#define SELECCION_H
#include "Cromosoma.h"
#include <vector>


//! Clase para el manejo de la función de Aptitud.
/*!
 *  \brief     Clase Seleccion
 *  \details   Esta clase permitira el calculo de la función de aptitud para cada elemento de la población de Cromosomas y poder obtenerlos de manera ordenada.
 *  \author    Carlos Andres Delgado
 *  \author    Edgar Andres Moncada
 *  \author    Luis Felipe Vargas
 *  \version   1.0
 *  \date      2012
 *  \copyright GNU Public License.
 */ 
class Seleccion
{
public:
    //! Constructor.
        /*!
        Constructor para la aplicación de la seleccion de cromosomas
        \param poblacion es un vector que contendrá la población de cromosomas viejas.
        \param hijos es un vector que contendrá la población de cromosomas que se ha cruzado y aplicado posibles mutaciones.
        */
    Seleccion(vector<Cromosoma*> poblacion, vector<Cromosoma*> hijos);
    /*! Función seleccionara entre la población vieja y
        los hijos mutados para que pasen a la siguiente generación. Se eliminan la mitad de los padres con peor aptitud
    */
    /*!
      \return un vector con los cromosomas seleccionados del mismo tamaño de la población inicial.
    */
    vector<Cromosoma*> aplicarSeleccion();
private:
    vector<Cromosoma*> poblacion;
    vector<Cromosoma*> hijosMutados;
	
};

#endif // SELECCION_H
