#ifndef FUNCIONAPTITUD_H
#define FUNCIONAPTITUD_H

#include "Cromosoma.h"
#include "TablaDeVerdad.h"
#include <algorithm>
#include <vector>

//! Clase para el manejo de la función de Aptitud.
/*!
 *  \brief     Clase aptitud
 *  \details   Esta clase permitira el calculo de la función de aptitud para cada elemento e la población de Cromosomas y poder obtenerlos de manera ordenada.
 *  \author    Carlos Andres Delgado
 *  \author    Edgar Andres Moncada
 *  \author    Luis Felipe Vargas
 *  \version   1.0
 *  \date      2012
 *  \copyright GNU Public License.
 */
class FuncionAptitud
{
public:
    //! Constructor.
    /*!
    Constructor para la aplicación y calculo de la función de aptitud para cada Cromosoma.
    \param poblacion es un vector que contendrá la población de cromosomas.
    \param tablaVerdad es la tabla de verdad para obtener el valor de la funcion.
    \param esMinTermino variable booleana que indica si se trabaja con mini términos o maxi términos.
    */
    FuncionAptitud(vector <Cromosoma*> poblacion, TablaDeVerdad *tablaVerdad,bool esMinTermino);
    //! Función que calculara a cada cromosoma la función de aptitud y retornara la población ordena.
    /*!
        \return un vector con los cromosomas ordenados de mejor aptitud a peor aptitud.
    */
    vector<Cromosoma*> aplicarAptitud();
    //! Función que retorna el valor de la mejor aptitud calculada.
    /*!
        \return un double con el valor de la mejor aptitud.
    */
    double obtenerMejorAptitud();
    /*! Estructura para realizar la comparación de la función sort
    */
    struct compare
    {
        bool operator()(Cromosoma* a, Cromosoma* b) const
        {
          return (a->getAptitud()<b->getAptitud());
        }
    };

private:
    vector<Cromosoma*> poblacion;
    TablaDeVerdad *tablaVerdad;
    double mejorAptitud;
};

#endif // FUNCIONAPTITUD_H
