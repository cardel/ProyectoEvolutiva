#include "funcionaptitud.h"

bool FuncionAptitud::ES_MIN_TERMINO=true;


FuncionAptitud::FuncionAptitud(vector<Cromosoma*> poblacion, TablaDeVerdad *tablaVerdad, bool esMinTermino)
{
    this->poblacion = poblacion;
    this->tablaVerdad = tablaVerdad;
    ES_MIN_TERMINO = esMinTermino;
    this->mejorAptitud=-1;
}

double FuncionAptitud::obtenerMejorAptitud()
{
    return mejorAptitud;
}

vector<Cromosoma*> FuncionAptitud::aplicarAptitud()
{
    int size = poblacion.size();
    for(int j =0;j<size;j++){//! por cada cromosoma
        int numComparaciones = (int)pow(2, poblacion[j]->getNumeroVariables());
        Cromosoma *c_tmp = poblacion[j];
        if(c_tmp->getAptitud()==-1){//! si no tiene una aptitud calculada
            double aptitud = (double)c_tmp->getNumeroClausulas();
            double count =0;
            for(int i=0;i<numComparaciones;i++){//! para cada valor de verdad
                if(c_tmp->obtenerSalida(i)==tablaVerdad->obtenerSalida(i)){
                    count++;
                }
            }
            aptitud+= count;
            c_tmp->setAptitud(aptitud);//! esta es la aptitud no la normalizacion

            if(FuncionAptitud::ES_MIN_TERMINO){
                if(mejorAptitud==-1 || mejorAptitud>aptitud){//tratamos de minimizar
                    mejorAptitud=aptitud;
                }
            }else{
                if(mejorAptitud==-1 || mejorAptitud<aptitud){//tratamos de maximizar
                    mejorAptitud=aptitud;
                }
            }

            //! sumaAptitud+=aptitud;
        }

    }
    /*! ordena sobre el vector de entrada
    */

    sort(poblacion.begin() , poblacion.end(), compare());

    return poblacion;
}
