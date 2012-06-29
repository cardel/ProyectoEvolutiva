#include "mutacion.h"

Mutacion::Mutacion(vector <Cromosoma*> hijos)
{
    this->hijosMutados=hijos;
}

vector<Cromosoma*> Mutacion::aplicarMutacion()
{
    int cantidad = (int)((double)(hijosMutados.size())*2/100);
    rand(time(NULL));
    for(int i=0; i < cantidad; i++){
        if(rand()%2==0){
            //Cambiar un valor
            Cromosoma* t =hijosMutados[i];
            int x=rand()%t->getNumeroClausulas(),y=rand()%(t->getNumeroVariables()*2),value=t->get(x,y);

            t->set(x,y, !(value==true));

        }else{
            //Borrar clausula
            Cromosoma* t =hijosMutados[i];
            int posClausulaBorrar= rand()%t->getNumeroClausulas();
            t->deleteClausula(posClausulaBorrar);
        }

    }


    return hijosMutados;
}
