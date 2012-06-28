#ifndef FUNCIONEVALUACION_H
#define FUNCIONEVALUACION_H
#include "Cromosoma.h"
#include <vector>
#include <time>
#include <stdlib.h>

//! Clase para seleccionar el Mating pool
/*!
Esta clase permitira seleccionar los cromosomas de acuerdo a la aptitud para la realización del cruce.
*/
class FuncionSeleccionCruce
{
public:
    //! Constructor.
    /*!
    Constructor para la aplicación del Mating pool.
    \param poblacion es un vector que contendrá la población de cromosomas.
    \param mejorAptitud es el valor con la mejor aptitud, esto para calcular la normalización y que quede entre [0,1].
        Se obtiene de la funcion de aptitud.
    */
    FuncionSeleccionCruce(vector<Cromosoma> poblacion, double mejorAptitud);
    //! Función que calculará los cromosomas seleccionados para relizar el cruce.
    /*!
      \return un vector con los cromosomas seleccionados.
    */
    vector<Cromosoma> aplicarEvaluacion();
private:
    vector<Cromosoma> poblacion;
    vector<double> puntuacionesAcumuladas;
    void calcularPuntuacionesAcumuladas();
    double mejorAptitud;
};

#endif // FUNCIONEVALUACION_H
