#include "funcionaptitud.h"


FuncionAptitud::FuncionAptitud(vector<Cromosoma*> poblacion, TablaDeVerdad *tablaVerdad, bool esMinTermino)
{
    this->poblacion = poblacion;
    this->tablaVerdad = tablaVerdad;
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

		double aptitud = 25*(double)c_tmp->getNumeroClausulas();
		double count =0;
		for(int i=0;i<numComparaciones;i++){//! para cada valor de verdad
			if(c_tmp->obtenerSalida(i)==tablaVerdad->obtenerSalida(i)){
				count++;
			}
		}
		//Se busca minimzar la funcion de aptitud
		count=numComparaciones-count;
		aptitud+= 75*count;
		
		
		c_tmp->setAptitud(aptitud);//! esta es la aptitud no la normalizacion

		if(mejorAptitud==-1 || mejorAptitud>aptitud){
			mejorAptitud=aptitud;
		}

    }
    
    /*! ordena sobre el vector de entrada
    */
    for (int i=0; i<size; i++)
	{
		for (int j=i+1; j<size; j++)
		{
			if (poblacion.at(i)->getAptitud()>poblacion.at(j)->getAptitud())
			{
				Cromosoma * aux=poblacion.at(i);
				poblacion.at(i)=poblacion.at(j);
				poblacion.at(j)=aux;
			}
		}
	}
	
    return poblacion;
}
