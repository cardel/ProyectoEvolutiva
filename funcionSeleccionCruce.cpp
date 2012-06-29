#include "funcionSeleccionCruce.h"

FuncionSeleccionCruce::FuncionSeleccionCruce(vector<Cromosoma*> poblacion, double mejorAptitud)
{
    this->poblacion=poblacion;
    this->mejorAptitud=mejorAptitud;
}

vector<Cromosoma*> FuncionSeleccionCruce::aplicarSeleccionCruce()
{
    calcularPuntuacionesAcumuladas();//! se calculan las puntuaciones acumuladas

    int size = poblacion.size();
    vector<Cromosoma*> tmp(poblacion), seleccionCruce;
    int k= (size/2);//! constante a la mitad de la poblacion
    if(k%2!=0){
        k--;
    }
    srand(time(NULL));
    int r =rand();
    for(int i = 1; i <= k;i++ ){
        r=(r+i-1/k);
        int posicion = 0;
        while(r>0 && r < size && r <= puntuacionesAcumuladas[posicion]){//! se selecciona la posicion donde r cayo en "la ruleta"
            posicion++;
        }
        /*! mirando el algoritmo por internet dice que puede repetirse elementos, asi el erase no iria */
        seleccionCruce.push_back(tmp[posicion]);
        //tmp.erase(tmp.begin()+posicion);
    }
    return seleccionCruce;
}

void FuncionSeleccionCruce::calcularPuntuacionesAcumuladas()
{
    int size=poblacion.size();
    double sumAptitud=0;
    puntuacionesAcumuladas.resize(size);
    for(int i=size-1;i>=0;i--){
        double p=0;
        for(int j=0;j<i;j++){
            Cromosoma* c_tmp = poblacion[j];
            p+=c_tmp->getAptitud() / mejorAptitud;
            if(i==size){
                sumAptitud+=c_tmp->getAptitud();
            }
        }
        puntuacionesAcumuladas[i]= p/sumAptitud;
    }

}


