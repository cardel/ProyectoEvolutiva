#include "funcionaptitud.h"

FuncionAptitud::FuncionAptitud(vector<Cromosoma> poblacion, TablaDeVerdad tablaVerdad, bool esMinTermino)
{
    this->poblacion = poblacion;
    this->tablaVerdad = tablaVerdad;
    this->esMinTermino = esMinTermino;
    this->mejorAptitud=-1;
}

double FuncionAptitud::obtenerMejorAptitud()
{
    return mejorAptitud;
}

vector<Cromosoma> FuncionAptitud::aplicarAptitud()
{
    int size = poblacion.size();
    for(int j =0;j<size;j++){//! por cada cromosoma
        int numComparaciones = (int)pow(2, poblacion[j].getNumeroVariables());
        Cromosoma c_tmp = poblacion[j];
        double aptitud = (double)c_tmp.getNumeroClausulas();
        double count =0;
        for(int i=0;i<numComparaciones;i++){//! para cada valor de verdad
            if(c_tmp.obtenerSalida(i)==tablaVerdad.obtenerSalida(i)){
                count++;
            }
        }
        aptitud+= count;
        c_tmp.setAptitud(aptitud);//! esta es la aptitud no la normalizacion

        if(esMinTermino){
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
    /*! ordena sobre el vector de entrada
    */
    sort(poblacion.begin() , poblacion.end(), compare());

    return poblacion;
}


