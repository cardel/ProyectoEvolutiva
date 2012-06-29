#include "seleccion.h"

Seleccion::Seleccion(vector<Cromosoma*> poblacion, vector<Cromosoma*> hijos)
{
    this->poblacion=poblacion;
    this->hijosMutados=hijos;
}

vector<Cromosoma*> Seleccion::aplicarSeleccion()
{
    vector<Cromosoma*> nuevaGeneracion;
    int sizePoblacion=poblacion.size();
    int sizeHijos = hijosMutados.size();//! la cantidad de padres que se borraran
    
    for(int i=0;i<sizeHijos;i++){
        nuevaGeneracion.push_back(poblacion[i]);
    }

    for(int j=0;j<sizeHijos;j++){
        nuevaGeneracion.push_back(hijosMutados[j]);
    }
    
    
    return nuevaGeneracion;//! debe tener el mismo tamaño de la poblacion
}
