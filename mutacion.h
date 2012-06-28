#ifndef MUTACION_H
#define MUTACION_H

#include "Cromosoma.h"
#include <vector>

//! Clase para implementar mutación
/*!
 *  \brief     Clase Mutacion
 *  \details   Para mutar se selecciona el 2 % de los individuos, en éstos se selecciona aleatoriamente una claúsula, con probabilidad del 50 % se realiza alguna de estas dos acciones. * Borrar claúsula Borra una clausula, si es la única de la función, la salida de la misma es siempre 0.Cambiar el valor de una variable Se selecciona una posición de la claúsula y se cambia el valor que tiene asignado por su negación.
 *  \author    Carlos Andres Delgado
 *  \author    Edgar Andres Moncada
 *  \author    Luis Felipe Vargas
 *  \version   1.0
 *  \date      2012
 *  \copyright GNU Public License.
 */
class Mutacion
{
public:
    //! Constructor.
        /*!
        Constructor para la aplicación de la mutación de los hijos generados de la población de Cromosomas
        \param poblacion es un vector que contiene los hijos generados en el Cruce.
        */
    Mutacion(vector <Cromosoma> hijos);
    /*! Funcion que mutara a los Cromosomas hijos el 2% de la población.
    */
    /*!
      \return un vector con los cromosomas hijos ya mutados.
    */
    vector<Cromosoma> aplicarMutacion();
};

#endif // MUTACION_H
