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
    
    if(size%2==1) size--;
    
    for(int i=0; i<size; i=i+2)
    {
		 Cromosoma* padre = poblacionSeleccionada[i], *madre=poblacionSeleccionada[i+1], *hijo1, *hijo2;
		 
		 int sizePadre = padre->getNumeroClausulas();
		 int sizeMadre = madre->getNumeroClausulas();
		 
		 int numeroVariables = madre->getNumeroVariables();
		 //Igualar cromosomas
		 if(sizePadre>sizeMadre)
		 {
				int diferencia = sizePadre-sizeMadre;
				Cromosoma * nuevaMadre = new Cromosoma(sizePadre, numeroVariables, usarMaxiterminos);
				
				//Llenar con lo que hay en la madre
				for(int x=0; x<sizeMadre; x++)
				{
					nuevaMadre->setClausula(x,madre->getClausula(x));
				}
				
				//Llenar el resto
				for(int x=sizeMadre; x<sizePadre; x++)
				{
					nuevaMadre->setClausula(x,madre->getClausula(x%sizeMadre));
				}
				madre = nuevaMadre;
				sizeMadre = sizePadre;
		 }

		 if(sizePadre<sizeMadre)
		 {
				int diferencia = sizePadre-sizeMadre;
				Cromosoma * nuevoPadre = new Cromosoma(sizeMadre, numeroVariables, usarMaxiterminos);
				
				//Llenar con lo que hay en la madre
				for(int x=0; x<sizePadre; x++)
				{
					nuevoPadre->setClausula(x,padre->getClausula(x));
				}
				
				//Llenar el resto
				for(int x=sizePadre; x<sizeMadre; x++)
				{
					nuevoPadre->setClausula(x,padre->getClausula(x%sizePadre));
				}
				padre = nuevoPadre;
				sizePadre = sizeMadre;
		 }
		 //Crear dos hijos
			srand ( time(NULL) );
		 int alfa = 1;
		 if(sizeMadre>1) alfa = 1 + rand()%(sizeMadre-1);
		 
		 int beta = 1;		 
		 if(numeroVariables>1) beta = 1 + rand()%(numeroVariables-1);		 
		 //Hijo 1

		 hijo1= new Cromosoma(alfa,numeroVariables, usarMaxiterminos);
		 for(int x=0; x<alfa; x++)
		 {
			 for(int y=0; y<numeroVariables; y++)
			 {
					if(y<beta) hijo1->set(x,y,padre->get(x,y));
					else hijo1->set(x,y,madre->get(x,y));
			 }
		 }
		 //Hijo 2
		 hijo2= new Cromosoma(sizePadre-alfa+1,numeroVariables, usarMaxiterminos);
		 for(int x=0; x<hijo2->getNumeroClausulas(); x++)
		 {
			 for(int y=0; y<numeroVariables; y++)
			 {
			
				if(y<beta) hijo2->set(x,y,padre->get(alfa+x-1,y));
				else hijo2->set(x,y,madre->get(alfa+x-1,y));
			 }
		 }
		 hijos.push_back(hijo1);
		 hijos.push_back(hijo2);
	}	
    return hijos;
}
