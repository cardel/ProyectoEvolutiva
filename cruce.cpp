#include "cruce.h"

Cruce::Cruce(vector<Cromosoma*> poblacion, bool usarMaxiterminos)
{
    this->poblacionSeleccionada=poblacion;
    this->usarMaxiterminos=usarMaxiterminos;
}

vector<Cromosoma*> Cruce::aplicarCruce()
{
    vector<Cromosoma*> hijos;
    int size = poblacionSeleccionada.size();
    
    /*for(int i=0;i<size;i=i+2){
        Cromosoma* padre = poblacionSeleccionada[i], *madre=poblacionSeleccionada[i+1], *hijo1, *hijo2;
        
        int menorClausulas= (int)min(padre->getNumeroClausulas(),madre->getNumeroClausulas());        
        int alfa;
        
        if(menorClausulas==1) alfa=1;
        else alfa = 1+ rand()%(menorClausulas-1); 

		hijo1=new Cromosoma(2*alfa, padre->getNumeroVariables(),usarMaxiterminos);
		
		for(int i=0; i<alfa; i++){
			hijo1->setClausula(i,padre->getClausula(i));
		}
		for(int i=alfa; i<alfa*2; i++){
			hijo1->setClausula(i,madre->getClausula(i-alfa));
		}
		hijos.push_back(hijo1);
		
		//Generar hijo 2
		int padreSobra= (padre->getNumeroClausulas()-alfa), madreSobra=(madre->getNumeroClausulas()-alfa);
		int sizeHijo2 = padreSobra +madreSobra;
		
		//No entra si el hijo 2 va tener 0 clausulas
		if(menorClausulas>1||sizeHijo2>1)
		{				

			hijo2 = new Cromosoma(sizeHijo2, madre->getNumeroVariables(),usarMaxiterminos);//! ojo

			for(int i=0; i<padreSobra;i++){
				hijo2->setClausula(i,padre->getClausula(i+alfa));
			}
			   
			for(int i=0; i<madreSobra; i++)
			{
				hijo2->setClausula(i+padreSobra,madre->getClausula(i+alfa));
			} 		
			hijos.push_back(hijo2);
		}
    }*/
    
    for(int i=0; i<size; i++)
    {
		 Cromosoma* padre = poblacionSeleccionada[i], *madre=poblacionSeleccionada[i+1], *hijo1, *hijo2;
		 
		 //Igualar cromosomas
		 

	}	
    return hijos;
}
