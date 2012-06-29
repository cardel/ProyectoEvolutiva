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
    for(int i=0;i<sizePoblacion;i++){
        if(i==sizeHijos){
            break;
        }
        nuevaGeneracion.push_back(poblacion[i]);
    }

    for(int j=0;j<sizeHijos;j++){
        nuevaGeneracion.push_back(hijosMutados[j]);
    }
    cout << "sizePoblacion: "<<sizePoblacion << " sizeNuevoG: " << nuevaGeneracion.size() << endl;
    return nuevaGeneracion;//! debe tener el mismo tamaño de la poblacion
}
