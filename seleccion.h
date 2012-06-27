#ifndef SELECCION_H
#define SELECCION_H
#include "Cromosoma.h"
#include <vector>

//! Clase para el manejo de la función de Aptitud.
/*!
Esta clase permitira el calculo de la función de aptitud para cada elemento e la población de Cromosomas y
poder obtenerlos de manera ordenada.
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
    Seleccion(vector<Cromosoma> poblacion, vector<Cromosoma> hijos);
    /*! Función seleccionara, por medio del metodo de seleccion por ruleta, entre la población vieja y
        los hijos mutados para que pasen a la siguiente generación.
    */
    /*!
      \return un vector con los cromosomas seleccionados del mismo tamaño de la población inicial.
    */
    aplicarSeleccion();
};

#endif // SELECCION_H
