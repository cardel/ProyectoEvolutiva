#include "cruce.h"

Cruce::Cruce(vector<Cromosoma*> poblacion)
{
    this->poblacionSeleccionada=poblacion;
}

vector<Cromosoma*> Cruce::aplicarCruce()
{
    vector<Cromosoma*> hijos;
    int size = poblacionSeleccionada.size();
    if(size%2!=0){//! no numero par de padres
        //! no deberia de pasar
    }
    for(int i=0;i<size;i=i+2){
        Cromosoma* padre = poblacionSeleccionada[i], *madre=poblacionSeleccionada[i+1], *hijo1, *hijo2;
        int menorClausulas= padre->getNumeroClausulas();
        if(menorClausulas>madre->getNumeroClausulas()){
            menorClausulas=madre->getNumeroClausulas();
        }

        if(menorClausulas==0){//! no puede sacar hijos!!

        }

        srand(time(NULL));
        int alfa;
        if(menorClausulas==1){
            alfa=1;
        }else{
            alfa = 1+ rand()%(menorClausulas-1);
        }

        hijo1=new Cromosoma(2*alfa, padre->getNumeroVariables(),false);//! ojo

        for(int i=0; i<alfa;i++){
            hijo1->setClausula(i,padre->getClausula(i));
        }
        for(int i=alfa; i<alfa*2;i++){
            hijo1->setClausula(i,madre->getClausula(i-alfa));

        }
        int padreSobra= (padre->getNumeroClausulas()-alfa), madreSobra=(madre->getNumeroClausulas()-alfa);
        int sizeHijo2 = padreSobra +madreSobra ;

        hijo2 = new Cromosoma(sizeHijo2, padre->getNumeroVariables(),false);//! ojo

        for(int i=0; i<sizeHijo2;i++){
            if(padreSobra!=0){
                hijo2->setClausula(i,padre->getClausula(i+alfa));
                padreSobra--;
            }else if(madreSobra!=0){
                hijo2->setClausula(i,madre->getClausula(i+alfa));
                madreSobra--;
            }
        }

        hijos.push_back(hijo1);
        hijos.push_back(hijo2);
    }
    return hijos;
}
