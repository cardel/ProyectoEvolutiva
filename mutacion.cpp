#include "mutacion.h"

Mutacion::Mutacion(vector <Cromosoma*> hijos)
{
    this->hijosMutados=hijos;
}

vector<Cromosoma*> Mutacion::aplicarMutacion()
{
    int cantidad = (int)((double)(hijosMutados.size())*2/100);
    srand(time(NULL));
    for(int i=0; i < cantidad; i++){

        int r=rand();
        Cromosoma* t =hijosMutados[i];
        int numClausulas = t->getNumeroClausulas();
        if(numClausulas==0){// no se puede hacer nada la clausula
            //cout << numClausulas << ":" << cantidad <<endl;
            cantidad--;
            continue;
        }
        if(r%2==0){

            //Cambiar un valor
            int x= rand() % numClausulas;//%;
            int y=(int)(rand()%(t->getNumeroVariables()*2));
            bool value=t->get(x,y);
            t->set(x,y, !(value==true));

        }else{
            //Borrar clausula
            Cromosoma* t =hijosMutados[i];
            int posClausulaBorrar= (int)(rand()%t->getNumeroClausulas());
            t->deleteClausula(posClausulaBorrar);
        }

    }


    return hijosMutados;
}
