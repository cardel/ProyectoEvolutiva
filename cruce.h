#ifndef CRUCE_H
#define CRUCE_H
#include "Cromosoma.h"
#include <vector>


//! Clase para el manejo del Cruce de los cromosomas.
/*!
 *  \brief     Clase Cruce
 *  \details   Esta clase permitira realizar el cruce de los cromosomas. Se seleccionan dos cromosomas dentro del grupo de seleccionados, se toma el cromosoma con menor número de cláusulas y se genera un número aleatorio entre 1 y ese número menos 1, valor que se denota con alfa. Con éste valor se generan dos hijos, uno tomando en ambos cromosomas alfa claúsulas iniciales y generando un cromosoma de tamaño 2 ∗ alfa, con el resto de ambos cromosomas se realiza el mismo procedimiento.
 *  \author    Carlos Andres Delgado
 *  \author    Edgar Andres Moncada
 *  \author    Luis Felipe Vargas
 *  \version   1.0
 *  \date      2012
 *  \copyright GNU Public License.
 */ 

class Cruce
{
public:
    //! Constructor.
    /*!
    Constructor para la aplicación de Cruce a la población de Cromosomas
    \param poblacion es un vector que contendrá la población de Cromosomas generado por la función de evaluación.
    */
    Cruce(vector<Cromosoma*> poblacion);
    //! Función que calculara los nuevos hijos al cruzar la población actual.
    /*!
      \return un vector con los nuevos Cromosomas.
    */
    vector<Cromosoma*> aplicarCruce();
private:
    vector<Cromosoma*> poblacion;

};

#endif // CRUCE_H
