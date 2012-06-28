#include "funcionaptitud.h"

FuncionAptitud::FuncionAptitud(vector<Cromosoma> poblacion, TablaDeVerdad tablaVerdad, bool esMinTermino)
{
    this->poblacion = poblacion;
    this->tablaVerdad = tablaVerdad;
    this->esMinTermino = esMinTermino;
    this->mejorAptitud=-1;
    this->sumaAptitud=0;
}

double FuncionAptitud::obtenerMejorAptitud()
{
    return mejorAptitud;
}

vector<Cromosoma> FuncionAptitud::aplicarAptitud()
{
    int size = poblacion.size();
    for(int j =0;j<size;j++){//! por cada cromosoma
        int numComparaciones = (int)pow(2, poblacion.at(0).getNumeroVariables());
        Cromosoma c_tmp = poblacion[j];
        for(int i=0;i<numComparaciones;i++){//! para cada valor de verdad
            double aptitud = c_temp.getNumeroClausulas() + (int)(c_tmp.obtenerSalida(i)||tablaVerdad.obtenerSalida(i));

            if(mejorAptitud==-1 || mejorAptitud<aptitud){
                mejorAptitud=aptitud;
            }

            c_tmp.setAptitud(aptitud);//! esta es la aptitud no la normalizacion


            //! sumaAptitud+=aptitud;

        }
    }
    /*! ordena sobre el vector de entrada
    */
    sort(poblacion.begin(),poblacion.end(), compareAptitudCromosoma);

    return poblacion;
}

bool FuncionAptitud::operator compareAptitudCromosoma(const Cromosoma &a, const Cromosoma &b)
{
    return (a.getAptitud()<b.getAptitud());
}
