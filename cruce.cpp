#include "cruce.h"

Cruce::Cruce(vector<Cromosoma*> poblacion)
{
    this->poblacionSeleccionada=poblacion;
}

vector<Cromosoma*> Cruce::aplicarCruce()
{
    vector<Cromosoma*> hijos;
    int size = poblacionSeleccionada.size();
    int cantidadHijos=(poblacionSeleccionada.size()/2);
    if(cantidadHijos%2!=0){//! esto no deberia pasar
        cantidadHijos--;
    }

    for(int i=0;i<size;i=i+2){
        Cromosoma* padre = poblacionSeleccionada[i], *madre=poblacionSeleccionada[i+1], hijo1, hijo2;
        int menorClausulas= padre->getNumeroClausulas();
        bool padreMenorNumClausulas=true;
        if(menorClausulas>madre->getNumeroClausulas()){
            menorClausulas=madre->getNumeroClausulas();
            padreMenorNumClausulas=false;

        }
        srand(time(NULL));
        int alfa = 1+ rand()%(menorClausulas-1);
        //como tomar las clausulas :S

        hijos.push_back(hijo1);
        hijos.push_back(hijo2);
    }

    return hijos;
}
