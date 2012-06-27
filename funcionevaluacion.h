#ifndef FUNCIONEVALUACION_H
#define FUNCIONEVALUACION_H
#include "Cromosoma.h"
#include "TablaDeVerdad.h"
#include <vector>

//! Clase para el manejo de la función de evaluación.
/*!
Esta clase permitira el calculo de la función de aptitud para cada elemento e la población de Cromosomas y
poder obtenerlos de manera ordenada.
*/
class FuncionEvaluacion
{
public:
    //! Constructor.
    /*!
    Constructor para la aplicación y calculo de la función de evaluación para cada Cromosoma.
    \param poblacion es un vector que contendrá la población de cromosomas.
    */
    FuncionEvaluacion(vector<Cromosoma>);
    //! Función que calculara a cada cromosoma la función de evaluación y retornara los cromosomas seleccionados para relizar el cruce.
    /*!
      \return un vector con los cromosomas seleccionados.
    */
    vector<Cromosoma> aplicarEvaluacion();
private:
};

#endif // FUNCIONEVALUACION_H
